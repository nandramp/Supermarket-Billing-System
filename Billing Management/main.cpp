#include<iostream>
#include<fstream>
using namespace std;

// Define Shopping class
class Shopping
{ 
    private:
       int ProductCode;
       float Price;
       float Discount;
       string ProductName;

    public:
       void Menu();              //function no 1
       void Administrator();     //function no 2
       void Buyer();             //function no 3
       void Add();               //function no 4
       void Edit();              //function no 5
       void Remove();            //function no 6
       void List();              //function no 7
       void Receipt();           //function no 8
       
};

/*****************************************************************************************************/
/* function no 1 to display Supermarket Main Menu and give option to the user to choose from the Menu*/
void Shopping::Menu()
{
    m:
    int Choice;
    string Email;
    string Password;  
    
    cout<<"\t\t\t\t   Supermarket Main Menu  \n";
    cout<<"\t\t\t\t|   1) Administrator     |\n";
    cout<<"\t\t\t\t|   2) Buyer             |\n";
    cout<<"\t\t\t\t|   3) Exit              |\n";
    cout<<"\nPlease select one opiton : ";
    cin>>Choice;
    
    switch(Choice)
    {
        case 1:
           cout<<"\t\t\t Please Login \n";
           cout<<"\t\t\t Enter Email   \n";
           cin>>Email;
           cout<<"\t\t\t  Password      \n";
           cin>>Password;

           if(Email=="nandram.iitkgp@gmail.com" and Password=="incorrectpassword")
           {
               Administrator();
           }
           else
           {
               cout<<"Invalid email/password";
           }
           break;
        
        case 2:
           Buyer();
           break;
        
        case 3:
            exit(0);
            break;
        default:
            cout<<"Please select from the given options";
            break;     
    }
    goto m;
}

/***********************************************************************************************************/
/* function no 2 to display Administrator Menu and give option to the Administrator to choose from the Menu*/
void Shopping:: Administrator()
{
    m:
     int Choice;
     cout<<"\n\n\n\t\t\t  Administrator Menu ";
     cout<<"\n\t\t\t|1) Add the product     |";
     cout<<"\n\t\t\t|2) Modify the product  |";
     cout<<"\n\t\t\t|3) Delete the product  |";
     cout<<"\n\t\t\t|4) Back to main menu   |";

     cout<<"\n\n Please enter your choice ";
     cin>>Choice;

     switch (Choice)
     {
        case 1:
            Add();
            break;
        case 2:
            Edit();
            break;
        case 3:
            Remove();
            break;
        case 4:
            Menu();
            break;
        default:
            cout<<"Invalid choice";
            break;
     }
     goto m;
}

/*****************************************************************************************************/
/* function no 3 to display Buyer Menu and give option to the Buyer to choose from the Menu*/
void Shopping:: Buyer()
{
    m:
    int Choice;
    cout<<"\n\t\t\t Buyer Menu";
    cout<<"\n\t\t\t|1) Buy product  |";
    cout<<"\n\t\t\t|2) Go back      |";
    cout<<"\n\nEnter your choice : ";
    cin>>Choice;
    switch(Choice)
    {
        case 1:
            Receipt();
            break;
        case 2:
            Menu();
            break;
        default:
            cout<<"Invalid Choice";
            break;
    }
    goto m;
}

/************************************************************************/
/* function no 4 to Add new product in to the Supermarket product list  */
void Shopping:: Add()
{
    m:
    fstream Data;
    int C;
    int Token = 0;
    float P;
    float D;
    string N;

    cout<<"\n\n Add new product";
    cout<<"\n\n Procuct code of the product ";
    cin>>ProductCode;
    cout<<"\n\n Name of the procuct: ";
    cin>>ProductName;
    cout<<"\n\n Price of the product : ";
    cin>>Price;
    cout<<"\n\n Discount on the product: ";
    cin>>Discount;

    Data.open("database.txt",ios::in);

    if(!Data)
    {
        Data.open("database.txt",ios::app|ios::out);
        Data<<" "<<ProductCode<<" "<<ProductName<<" "<<Price<<" "<<Discount<<"\n";
        Data.close();
    }
    else
    {
        Data>>C>>N>>P>>D;
        while(!Data.eof())
        {
            if(C==ProductCode)
            {
                Token++;
            }
            Data>>C>>N>>P>>D;
        }
        Data.close();
    

        if(Token==1)
           {
              goto m;
           }
        else
           {
               Data.open("database.txt",ios::app|ios::out);
               Data<<" "<<ProductCode<<" "<<ProductName<<" "<<Price<<" "<<Discount<<"\n";
               Data.close();
           }
    }
    cout<<"\n\n\t\t Product added succesfully !";

}

/************************************************************************/
/* function no 5 to Add Edit product in to the Supermarket product list */
void Shopping:: Edit()
{
    fstream Data,Data1;
    int ProductKey;
    int Token = 0;
    int C;
    float P;
    float D;
    string N;

    cout<<"\n Modify the Record  ";
    cout<<"\n Product code : ";
    cin>>ProductKey;

    Data.open("database.txt",ios::in);

    if(!Data)
    {
        cout<<"\n\nFile doesn't exist! ";
    }
    else
    {
        Data1.open("database1.txt",ios::app|ios::out);

        Data>>ProductCode>>ProductName>>Price>>Discount;
        while(!Data.eof())
        {
            if(ProductKey==ProductCode)
            {
                cout<<"\n Product new cod : ";
                cin>>C;
                cout<<"\n Name of the product";
                cin>>N;
                cout<<"\n Price";
                cin>>P;
                cout<<"\n Discount : ";
                cin>>D;
                Data1<<" "<<C<<" "<<N<<" "<<P<<" "<<D<<"\n";
                cout<<"\n\n Record edited";
                Token++;
            }
            else
            {
                Data1<<" "<<ProductCode<<" "<<ProductName<<" "<<Price<<" "<<Discount<<"\n";

            }
            Data>>ProductCode>>ProductName>>Price>>Discount;

        }
        Data.close();
        Data1.close();

        remove("database.txt");
        rename("databacse1.txt","database.txt");

        if(Token == 0)
        {
            cout<<"\n\n Record not fount sorry!";
        }

    }
}

/************************************************************************/
/* function no 6 to Remove product from the Supermarket product list    */
void Shopping:: Remove()
{
    fstream Data,Data1;
    int ProductKey;
    int Token = 0;
    cout<<"\n Delete product";
    cout<<"\n Enter the product code : ";
    cin>>ProductKey;
    Data.open("database.txt",ios::in);

    if(!Data)
    {
        cout<<"\n\n\t !File doesn't exist!";
    }
    else
    {
        Data1.open("database1.txt",ios::app|ios::out);
        Data>>ProductCode>>ProductName>>Price>>Discount;

        while(!Data.eof())
        {
            if(ProductCode==ProductKey)
            {
                cout<<"\n\n\t Product deleted succesfully";
                Token++;
            }
            else
            {
                Data1<<" "<<ProductCode<<" "<<ProductName<<" "<<Price<<" "<<Discount<<"\n";
            }
            Data>>ProductCode>>ProductName>>Price>>Discount;
        }

        Data.close();
        Data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(Token==0)
        {
            cout<<"\n\n\t Record not found";
        }
    }

}

/********************************************************************************/
/* function no 7 to Display all the product which are available in Supermarket  */
void Shopping:: List()
{
    fstream Data;
    Data.open("database.txt",ios::in);
    cout<<"\n\n ProductNumber  Name\t\tPrice\n";
    Data>>ProductCode>>ProductName>>Price>>Discount;

    while(!Data.eof())
    {
        cout<<ProductCode<<"\t\t"<<ProductName<<"\t\t"<<Price<<"\n";
        Data>>ProductCode>>ProductName>>Price>>Discount;
    }
    Data.close();
}

/************************************************************************************/
/* function no 8 to take order from the Byer and display Receipt of  ordered product*/
void Shopping:: Receipt()
{
    fstream Data;
    int Arrc[100];
    int Arrq[100];
    string Choice;
    int C = 0;
    float Amount = 0;
    float Discount = 0;
    float Total = 0;

    // cout<<"\n\n\t\t\t\t RECEIPT";
    Data.open("database.txt",ios::in);

    if(!Data)
    {
        cout<<"\n\n Empty database!";
    }
    else
    {
        Data.close();
         
        List();
        cout<<"\n________________________________________________\n";
        cout<<"\n            Please place the order                ";
        cout<<"\n________________________________________________\n";

        do
        {
            m:
            cout<<"\n Enter the product Number : ";
            cin>>Arrc[C];
            cout<<"\n Enter the product quantity : ";
            cin>>Arrq[C];
            for(int i=0;i<C;i++)
            {
                if(Arrc[C]==Arrc[i])
                {
                    cout<<"\n\n\t Duplicate product code.\n\t Please try again";
                    goto m;
                }
            }
            C++;
            cout<<"\n\n Do you want to buy another product? if yes then press y else press no : ";
            cin>>Choice;
        }
        while(Choice=="y");
            
                cout<<"\n\n\t\t\t______________________RECEIPT_______________________\n";
                cout<<"\nProduct No   Product Name\t\tProduct Quantity\t Price\t\t Discount \t\t Amount With Discount\n ";
                
                for(int i=0;i<C;i++)
                {
                    Data.open("database.txt",ios::in);
                    Data>>ProductCode>>ProductName>>Price>>Discount;
                    while(!Data.eof())
                    {
                        if(ProductCode==Arrc[i])
                        {
                            Amount = Price*Arrq[i];
                            float AmountAfterDiscount = Amount-(Amount*Discount/100);
                            Total = Total+AmountAfterDiscount;
                            cout<<"\n"<<ProductCode<<"\t     "<<ProductName<<"\t\t\t"<<Arrq[i]<<"\t\t\t "<<Price<<"\t\t "<<Discount<<"\t\t\t  "<<AmountAfterDiscount;
                        }
                        Data>>ProductCode>>ProductName>>Price>>Discount;
                    }
                }
                Data.close();

            
            cout<<"\n\n________________________________________________";
            cout<<"\n Total Amount : "<<Total;
        


    }
}

/************************************************************************/
/* Main function to Execute our programme                              */
int main()
{
    Shopping s;
    s.Menu();
}