#include<iostream>
#include<conio.h>
#include<fstream>
#include<cmath>
#include<windows.h>
#include<cstring>
#include<ctime>


using namespace std;

 fstream fout;

class Product
{
    private:
    int product_num;
    char product_name[100];
    float price,disc;
    int quant;

    public:
        Product()
        {
            product_num=0;
            price=0;
            quant=0;
        }
        void add_product()
        {
            cout<<"Enter the product number"<<endl;
            cin>>product_num;
            cout<<"Enter the name of the product"<<endl;
            cin>>product_name;
            cout<<"Enter the price of new product"<<endl;
            cin>>price;
            cout<<"How many product you are going to add"<<endl;
            cin>>quant;

        }
    void added_product()
            {
            cout<<"product number"<<"\t\t"<<"product name"<<"\t\t\t"<<"price"<<"\t\t\t"<<"       quantity"<<endl;
            cout<<product_num<<"\t\t\t\t"<<product_name<<"\t\t\t"<<price<<"\t\t\t\t"<<quant<<endl;

            }
            float return_discount()
            {
                disc=2;
                return disc;
            }

            int return_product_num()
            {
                return product_num;
            }
            int return_quant()
            {

                return quant;
            }
            char* return_product_name()
            {

                return product_name;
            }
            float return_price()
            {

                return price;
            }



};
Product pro;
void new_product()
{int a,n;
cout<<"Enter the number of product you want to add"<<endl;
cin>>n;
        fout.open("supermarket.dat",ios::out | ios::app);
        for(a=0;a<n;a++ )
       {

       pro.add_product();
        fout.write((char*)&pro,sizeof(pro));
        system("CLS");
       }

        fout.close();
        cout<<"data has been added"<<endl;


}
void display_all_product()
{
    system("CLS");
 fout.open("supermarket.dat",ios::in);
  cout << "Entire product database"<< endl;
     cout << "---------------------------" << endl;
 while(fout.read((char*)&pro,sizeof(pro)))

{
    pro.added_product();
    cout<<"----------------------------------------------------------------------------------------------"<<endl;

}
fout.close();
_getch();

}
void edit_product()
{
    int num,get=0;
    cout<<"*****************EDIT PRODUCT******************"<<endl;
    cout<<"Enter the product number need to edit"<<endl;
    cin>>num;
    fout.open("supermarket.dat",ios::in | ios::out);
     while (fout.read((char * ) & pro, sizeof(pro)) && get== 0)
     {
         if(pro.return_product_num()== num)
         {
             pro.added_product();
             cout<<"Enter new detail"<<endl;
             pro.add_product();
             int position = -1 * sizeof(pro);
              fout.seekp(position, ios::cur);
            fout.write((char * ) & pro, sizeof(pro));
            cout << "\n\n\t Record Updated";
            get = 1;

         }

     }
     fout.close();
     if(get==0)
     {

         cout<<"Record not found"<<endl;

     }
     _getch();


}
bill()
{
    int order_arr[50], quan[50], c = 0;
    float amt,dvatamt, total = 0;
    char ch = 'Y';
    system("CLS");
   // menu();
    cout << "\n============================";
    cout << "\n PLACE  THE PRODUCTS TO BUY ";
    cout << "\n============================\n";
    do
    {
        cout << "\n\nEnter The Product No. Of The Product : ";
        cin >> order_arr[c];
        cout << "\nQuantity in number : ";
        cin >> quan[c];
        c++;
        cout << "\nDo You Want To Order Another Product ? (y/n)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\nThank You !!!!!";
    _getch();
    system("CLS");
    time_t now=time(0);

    tm* timePtr= localtime(&now);
     cout << "Date     " <<(timePtr->tm_mday)<<"/"<< (timePtr->tm_mon)+1 <<"/"<< (timePtr->tm_year)+1900<< endl;
  cout << "Time     " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec) << endl;
    cout << "\n\n******************************** INVOICE ************************\n";
    cout << "\nPr No.\tPr Name\t  Quantity \t   Price  \tAmount with 2% discount  ";
    for (int x = 0; x <= c; x++)
    {
        fout.open("supermarket.dat", ios:: in );
        fout.read((char * ) & pro, sizeof(pro));
        while (!fout.eof())
        {
            if (pro.return_product_num() == order_arr[x])
            {
                amt = pro.return_price() * quan[x];
                dvatamt = amt - (amt * pro.return_discount()/100);
                cout << "\n" << order_arr[x] << "\t" << pro.return_product_name() <<
                    "\t" << quan[x] << "\t\t" << pro.return_price() << "\t\t" << dvatamt << "\t\t" << endl;

                total += dvatamt;
            }
            fout.read((char * ) & pro, sizeof(pro));
        }

        fout.close();
    }
    cout << "\n\n\t\t\t\t\tTOTAL = " << total;
    _getch();

}
search_index(int n)
{
    int flag =0;
    fout.open("supermarket.dat",ios::in);
    while (fout.read((char * ) & pro, sizeof(pro)))
    {
        if (pro.return_product_num() == n)
        {
      system("CLS");
            pro.added_product();
            flag = 1;
        }
    }
    fout.close();
    if (flag == 0)
        cout << "\n\nrecord not exist";
    _getch();

}
 void cleardata()
 {
    fout.open("supermarket.dat", ios::out| ios::trunc);
    fout.close();
  }


int main()

{


    char choice;
    do{
    system("CLS");
    cout<<" WELCOME TO THE SUPERMARKET BILLING SYSTEM"<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout << "\t1.Add New Product"<<endl;
    cout << "\t2.List All Products"<<endl;
    cout << "\t3.Edit PRODUCT"<<endl;
    cout<<"\t4. Search index"<<endl;
    cout<<"\t5.Bill system"<<endl;
    cout<<"\t6.Delete all products"<<endl;
    cout<<"\t7.exit"<<endl;
    cout<<"--------------------*********--------------------"<<endl;
    cout<<"\n\n Please enter your choice"<<endl;
    cin>>choice;
    system("CLS");
    switch(choice)
    {
     case '1':
        new_product();
        break;
    case '2':
        display_all_product();
        break;
   case '3':
    edit_product();
       break;
   case '4':
       int num;
       cout<<"Enter the  product number"<<endl;
       cin>>num;
   search_index(num);

    break;

    case '5':
       bill();
        break;

    case '6':
        cleardata();
     break;
    case '7':
        exit(0);
    default :
        cout<<"\a Wrong entry"<<endl;
    }
    }while (choice!='7');
}

