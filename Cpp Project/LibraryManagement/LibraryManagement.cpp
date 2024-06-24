#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib> // For std::atoi

struct Book {
    int id;
    std::string title;
    std::string author;
    int year;
};

struct Member {
    int id;
    std::string name;
    std::string email;
};

class Library {
public:
    void addBook(const Book& book) {
        books.push_back(book);
        saveBooksToFile();
    }

    void viewBooks() const {
        for (const auto& book : books) {
            std::cout << "ID: " << book.id << ", Title: " << book.title 
                      << ", Author: " << book.author << ", Year: " << book.year << "\n";
        }
    }

    void deleteBook(int bookId) {
        auto it = std::find_if(books.begin(), books.end(), [bookId](const Book& book) {
            return book.id == bookId;
        });
        if (it != books.end()) {
            books.erase(it);
            saveBooksToFile();
            std::cout << "Book with ID " << bookId << " deleted.\n";
        } else {
            std::cerr << "Book with ID " << bookId << " not found.\n";
        }
    }

    Library() {
        loadBooksFromFile();
    }

private:
    std::vector<Book> books;

    void saveBooksToFile() const {
        std::ofstream file("books.txt");
        for (const auto& book : books) {
            file << book.id << "," << book.title << "," << book.author << "," << book.year << "\n";
        }
    }

    void loadBooksFromFile() {
        std::ifstream file("books.txt");
        if (!file.is_open()) {
            std::cerr << "Error opening books.txt for reading.\n";
            return;
        }
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string token;
            Book book;
            std::getline(iss, token, ','); book.id = std::atoi(token.c_str());
            std::getline(iss, book.title, ',');
            std::getline(iss, book.author, ',');
            std::getline(iss, token, ','); book.year = std::atoi(token.c_str());
            books.push_back(book);
        }
        file.close();
    }
};

class Management {
public:
    void addMember(const Member& member) {
        members.push_back(member);
        saveMembersToFile();
    }

    void viewMembers() const {
        for (const auto& member : members) {
            std::cout << "ID: " << member.id << ", Name: " << member.name 
                      << ", Email: " << member.email << "\n";
        }
    }

    void deleteMember(int memberId) {
        auto it = std::find_if(members.begin(), members.end(), [memberId](const Member& member) {
            return member.id == memberId;
        });
        if (it != members.end()) {
            members.erase(it);
            saveMembersToFile();
            std::cout << "Member with ID " << memberId << " deleted.\n";
        } else {
            std::cerr << "Member with ID " << memberId << " not found.\n";
        }
    }

    Management() {
        loadMembersFromFile();
    }

private:
    std::vector<Member> members;

    void saveMembersToFile() const {
        std::ofstream file("members.txt");
        for (const auto& member : members) {
            file << member.id << "," << member.name << "," << member.email << "\n";
        }
    }

    void loadMembersFromFile() {
        std::ifstream file("members.txt");
        if (!file.is_open()) {
            std::cerr << "Error opening members.txt for reading.\n";
            return;
        }
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string token;
            Member member;
            std::getline(iss, token, ','); member.id = std::atoi(token.c_str());
            std::getline(iss, member.name, ',');
            std::getline(iss, member.email, ',');
            members.push_back(member);
        }
        file.close();
    }
};

int main() {
    Management management;
    Library library;
    int choice;

    do {
        std::cout << "\nLibrary Management System\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. View Books\n";
        std::cout << "3. Delete Book\n";
        std::cout << "4. Add Member\n";
        std::cout << "5. View Members\n";
        std::cout << "6. Delete Member\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            Book book;
            std::cout << "Enter Book ID: "; std::cin >> book.id;
            std::cin.ignore();
            std::cout << "Enter Title: "; std::getline(std::cin, book.title);
            std::cout << "Enter Author: "; std::getline(std::cin, book.author);
            std::cout << "Enter Year: "; std::cin >> book.year;
            library.addBook(book);
            break;
        }
        case 2:
            library.viewBooks();
            break;
        case 3: {
            int bookId;
            std::cout << "Enter Book ID to delete: "; std::cin >> bookId;
            library.deleteBook(bookId);
            break;
        }
        case 4: {
            Member member;
            std::cout << "Enter Member ID: "; std::cin >> member.id;
            std::cin.ignore();
            std::cout << "Enter Name: "; std::getline(std::cin, member.name);
            std::cout << "Enter Email: "; std::getline(std::cin, member.email);
            management.addMember(member);
            break;
        }
        case 5:
            management.viewMembers();
            break;
        case 6: {
            int memberId;
            std::cout << "Enter Member ID to delete: "; std::cin >> memberId;
            management.deleteMember(memberId);
            break;
        }
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
 