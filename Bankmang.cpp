#include<stdio.h>
#include<math.h>
#include<iostream>
#include<conio.h>
#include<fstream>
#include<ctype.h>
#include<string.h>
#include <bits/stdc++.h>

using namespace std;

void clear (void){
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
}

int n,N=0;
void line (void)
{
    for(int i=0;i<41;i++)
     cout<<"--";
     cout<<endl;
}
class Account
{
    int accountno;
    char name[100];
    float balance; // attribute for money deposited
    char type[30];

 public :
    void createacc(void);
    void showacc(void);
 void modify(void);

    void deposit(void);
    void withdraw(void);
 void report(void);

    int raccno(void);
    float rbal(void);
    char rtype(void);

};

Account a[100],acc;
    void Account :: createacc(void)
    {  clear();
       cout<<"\nCreate Account:-";
       cout<<"\nEnter Account Holder Name :\n"; //gets(name);
       fgets(name,50, stdin);
       //cin>>name;
      //cin.getline(name,80);
      cout<<"\nEnter the Account Number :";           cin>>accountno;
        clear();
       cout<<"\nEnter the type of account :";// gets(type); 
       fgets(type, 30, stdin);
       //cin>>type;
      //cin.getline(type,25);
       cout<<"\n Enter the money to be deposited :";   cin>>balance;
       
    }
    void Account :: showacc(void)
    {   line();
        cout<<"Account Data:-"<<endl;
        cout<<"Account Number: "<<accountno<<"\t";
        cout<<"Name of the Account holder: "<<name<<endl;
        //puts(name);
        cout<<"Balance "<<balance<<endl;
        cout<<"Type of account "<<type<<endl;
        line();

    }
    void Account :: modify(void)
    {   int x;
        cout<<"\nEnter the S.no. of option you want to modify";
        cout<<"\n1.Account Holder's Name\n2.Account Type\n3.Balance\n";
        cin>>x;
        switch (x)
        {
        case 1 :
             cout<<"Enter the NEW name";
             gets(name);
            break;
        case 2 :
             cout<<"Enter the NEW Account Type";
             gets(type);
            break;
        case 3 :
             cout<<"Enter the choice selected\n";
             cout<<"1.Deposit\n2.Draw money\n";
             int y;
             cin>>y;
             switch (y)
             { //float temp;
             case 1:
                //cout<<"\nEnter the amount to Deposit";
                //cin>>temp;
                deposit();
                 break;
             case 2:
                //cout<<"\nEnter the amount to Withdraw";
                //cin>>temp;
                withdraw();
                 break;
             default: cout<<"\nInvalid choice\n";
                 break;
             }

            break;
        default: cout<<"\nInvalid choice\n";
            break;
        }
    }
    void Account :: deposit(void)
    {   float amount;
        cout<<"Enter the amount of money to deposit\n";
        cin>>amount;
        balance+=amount;
    }
    void Account :: withdraw(void)
    {  float amount;
       cout<<"Enter the amount of money to withdraw\n";
       cin>>amount;
        balance-=amount;
    }
    void Account :: report(void)
    {
      cout<<setw(49)<<"\n\nAll ACCOUNTS REPORT\n";
line();
line();
cout<<setw(2)<<"S.no."<<setw(20)<<"Account Number"<<setw(12)<<"Name"<<setw(25)<<"Balance"<<setw(24)<<"Account Type\n";
    for(int i=0;i<N;i++)
     {
    cout<<setw(2)<<i+1<<setw(10)<<a[i].accountno<<setw(30)<<a[i].name<<setw(12)<<a[i].balance<<setw(12)<<a[i].type<<endl;
     line();

     }
    }
    int Account :: raccno(void)
    {
        return accountno;
    }
    float  Account :: rbal(void)
    {
        return balance;
    }
    char  Account :: rtype(void)
    {
        return type[10];
    }



void menu(int i)
{  int x;

 l:  cout<<"\nMENU :-\n";
    cout<<"\nEnter the S.no. of the option you choose\n";
    cout<<"1.modify\n";
    cout<<"2.Deposit money\n";
    cout<<"3.WIthdraw Money\n";
    cout<<"4.Show Account details \n";
  //cout<<"5.accno\n";
    cout<<"5.View Balance\n";
    cout<<"6.View Account Type\n";
    //cout<<"7.View Account Type\n";
    cin>>x;
    switch (x)
    {
    case 1:
        a[i].modify();
        break;
    case 2:
        a[i].deposit();
        break;
    case 3:
        a[i].withdraw();
        break;
    case 4:
        a[i].showacc();
        break;
    case 5:
        cout<<a[i].rbal()<<endl;
        break;
    case 6:
        cout<<a[i].rtype()<<endl;
        break;

    default:cout<<"Invalid entry\n";
        break;
    }

 {char ch;
   cout<<"Want to se Menu?(Type Y for yes)\n";

   cin>>ch;
   if(ch=='y'||'Y'){//cout<<"HO";
       goto l;}

   
 }

}


int main()
{
    int option,i=0;
    //Account a[N];
   label:
     cout<<"MAIN MENU :-\n";
    cout<<"Enter the S.no. of the option you want\n";
   cout<<"1.Create new Accounts\n";
   cout<<"2.Show all accounts details\n";
   cout<<"3.See Menu\n";
   cin>>option;
   switch (option)
   {
    case 1:
     {
     cout<<"Enter the no. of accounts to be made : \n"; cin>>n;
     N+=n;
       while (i<N)
       {
           a[i].createacc();
         i++;
       }

     }
     break;

    case 2:
     {// for(int i=0;i<N;i++)
      {
        acc.report();
      }
     }
     break;

    case 3:
     { int i,j;
      int accno;
      cout<<"\nEnter the Account number of the account :";
      cin>>accno;
      for( i=0;i<N;i++)
        {
        if(a[i].raccno()==accno)
        {j=i;}
        break;
        }
      menu(j);
     }
     break;

   default:cout<<"Invalid Entry \n";
       break;
   }

 /*{char ans;
   cout<<"Want to crate new accounts?(type Y for Yes and N for No)\n";
   cin>>ans;
   if(ans=='Y'||'y')
    {
     cout<<"Enter the no. of accounts to be made : \n"; cin>>n;
       for(int i=0;i<n;i++)
       {
         a[i].createacc();
       }
    }
 }*/

 /*   /////fortodisplayall
 {char ans;
    cout<<"Want to see all accounts?(type Y for Yes and N for No)\n";
   cin>>ans;
   if(ans=='Y'||'y')
     { for(int i=0;i<n;i++)
      {
        a[i].showacc();
      }
     }

 }*/

/*{ int i;
  int accno;
  cout<<"\nEnter the Account number of the account :";
  cin>>accno;
    for( i=0;i<n;i++)
    {
        a[i].raccno()==accno;
        break;
    }  menu(i);
}*/
 {char ch;
   cout<<"\nWant to see MAIN MENU?(Type Y for yes)\n";
   cin>>ch;
   //cout<<ch;
   //goto label;
if(ch=='y'||'Y'){//cout<<"HO";
       goto label;}

 }
//return 0;
}
