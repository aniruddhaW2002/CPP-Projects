#include<iostream>
using namespace std;
int main(){
    int returTotalBill(void);
   int totalBill= returTotalBill();
    cout<<"Your Total Bill Amount Is"<<totalBill;
    cout<<"Thank you for you order !"<<endl;
}
int returTotalBill()
{
    char c;
    char item;
    char vegItem;
    int billAmount=0;
    char selectAgain;
    char nonvegItem;
    cout<<"-------------Welcome To Online Food Order----------"<<endl;
    cout<<"------------Please Follow Below Instruction----------"<<endl;
    cout<<"Step 1 : Please press s to start your order"<<endl;
    cout<<"Step 2 :  you can order both Veg and Nonveg item"<<endl;
    cout<<"Step 3 :  Please press a to select veg  item "<<endl;
    cout<<"Step 4 :  Please press b to select Nonveg  item "<<endl;
    cout<<"Step 5 :  You will get your final Bill after your order "<<endl;
    start:
    cin>>c;
    if(c=='s' || c=='S'){
        items:
        cout<<"Please select your choice "<<endl;
        cout<<"(a) Veg Item              (b)Nonveg Item"<<endl;
        cin>>item;
        if(item=='a' || item=='A'){
             vegItemList:
            cout<<"Please select 1,2,3,4,5 as per your choice"<<endl;
            cout<<"(1)Paneer Masala : Price : Rs -150"<<endl;
            cout<<"(2)Paneer Angaar : Price : Rs -180"<<endl;
            cout<<"(3)Veg Koliwada : Price : Rs -170"<<endl;
            cout<<"(4)Veg Maratha : Price : Rs -190"<<endl;
            cout<<"(5)Baigaan Masala : Price : Rs -200"<<endl;
            cin>>vegItem;
            if(vegItem=='1')
            {
                billAmount=billAmount+150;

            }
            else if(vegItem=='2')
            {
                billAmount=billAmount+180;

            }
             else if(vegItem=='3')
            {
                billAmount=billAmount+170;

            }
             else if(vegItem=='4')
            {
                billAmount=billAmount+190;

            }
             else if(vegItem=='5')
            {
                billAmount=billAmount+200;

            }
            

 
        }
       
        else{
            cout<<"You have entered wrong value ,please try again"<<endl;
            goto vegItemList;
        }
        cout<<"Do you want to add more items,y or n? "<<endl;
        cin>>selectAgain;
        if(selectAgain=='y'){
            goto items;
        }
        else{
            return billAmount;
        }


    }
     else if(item=='b' || item=='B'){
        nonvegItemList:
            cout<<"Please select 1,2,3,4,5 as per your choice"<<endl;
            cout<<"(1)Chicken Chilly : Price : Rs -250"<<endl;
            cout<<"(2)Chicken Biryani : Price : Rs - 140"<<endl;
            cout<<"(3)Mutton Biryani : Price : Rs - 200"<<endl;
            cout<<"(4)Chicken Masala : Price : Rs -210"<<endl;
            cout<<"(5)Mutton Handi : Price : Rs -400"<<endl;
            cin>>nonvegItem;
            if(nonvegItem=='1')
            {
                billAmount=billAmount+250;

            }
            else if(nonvegItem=='2')
            {
                billAmount=billAmount+140;

            }
             else if(nonvegItem=='3')
            {
                billAmount=billAmount+200;

            }
             else if(nonvegItem=='4')
            {
                billAmount=billAmount+210;

            }
             else if(nonvegItem=='5')
            {
                billAmount=billAmount+400;

            }
       
        else{
            cout<<"You have entered wrong value ,please try again"<<endl;
            goto nonvegItemList;
        }
        cout<<"Do you want to add more items, y or n? "<<endl;
        cin>>selectAgain;
        if(selectAgain=='y'){
            goto items;
        }
        else{
            return billAmount;
        }
    }
    else if((item !='a'||item !='A') && (item !='b' || item !='B')){
        cout<<"You have entered wrong value ,please try again"<<endl;
        goto items;
    }
    else {
        cout<<"You have entered wrong value ,please press s!"<<endl;
        goto start;

    }
 return  billAmount;
}