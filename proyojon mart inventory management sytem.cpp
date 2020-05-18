#include<iostream>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
using namespace std;
int i,n;
ifstream fin;
ofstream fout;
fstream fio;
void disp();
class stock
{
    char name[20];
	float pr;
	int quant, pass;

public:
	void get()
	{
	cout<<"Name: ";
	cin>>name;
	cout<<"Price: ";
	cin>>pr;
	cout<<"Quantity: ";
	cin>>quant;
    }
	void get2()
	{
	cout<<"Name: ";
	cin>>name;
	cout<<"Quantity: ";
	cin>>quant;
    }

	void show()
	{
	cout<<"\n"<<name<<"\t\t"<<quant<<"\t\t\t"<<pr;
	cout<<"\n";
    }

    int stchk(char nm[30])
    {
	if(strcmp(nm,name)==0)
	 return 0;
	else
	return 1;
    }

    void withd(int qty)
    {
	if(quant>=qty)
	{
		quant=quant-qty;
		cout<<"\n\nTotal price to be Paid: "<<pr*qty<<"Tk Only";
    }
	else
	   cout<<"\n\nInsufficient Stock";
	    getch();
    }

    void refil(int qty, float prc)
    {

		quant=quant+qty;
		pr=pr+prc;
		cout<<"\nStock Updated.";
	    getch();
    }
}st;

class logo
{
public:
    iubat_logo()
    {
        cout<<"\n";
	cout<<"\t\t\t          ||||||||||||||||||"<<endl;
    cout<<"\t\t\t  ||||||          ||           ||||||"<<endl;
    cout<<"\t\t\t    ||        ##########         ||"<<endl;
    cout<<"\t\t\t    ||        ##  ##  ##         ||"<<endl;
    cout<<"\t\t\t    ||  ||||||    ##      ||     ||"<<endl;
    cout<<"\t\t\t    ||  ||  ||    ##     ||||    ||"<<endl;
    cout<<"\t\t\t    ||  ||||      ##    ||  ||   ||"<<endl;
    cout<<"\t\t\t    ||  ||||      ##   ||||||||  ||"<<endl;
    cout<<"\t\t\t    ||  ||  ||    ##   ||    ||  ||"<<endl;
    cout<<"\t\t\t    ||  ||||||   #### ||||  |||| ||"<<endl;
    cout<<"\t\t\t    ||            ||             ||"<<endl;
    cout<<"\t\t\t      |||||||||||||||||||||||||||   "<<endl;
    cout<<"\t\t\t                  ||"<<endl;
    cout<<"\t\t\t          ||||||||||||||||||"<<endl;
    cout<<"\n";
    cout<<"\n";

    cout<<"\t\t\t\t Welcome to My Project"<<endl;
    cout<<"\n";
    cout<<"\n";
    cout<<"Projects Details \t\t\t\t\t\tStudent Details:"<<endl;
    cout<<"----------------\t\t\t\t\t\t----------------"<<"\n"<<endl;
    cout<<"Project Name: Proyojon Mart Inventory \t\t\t\tName: SAFFFT HABiB"<<"\n"<<endl;
    cout<<"Project Type: Small Inventory System\t\t\t\tID: 18103198"<<"\n"<<endl;
    cout<<"\t\t\t\t\t\t\t\tProgram: BCSE"<<"\n"<<endl;
    cout<<"\t\t\t\t\t\t\t\tSection: 'C'"<<"\n"<<endl;
    }

    proyojon_mart_logo()
    {
        cout<<"\n";
	cout<<"\t\t\t        Welcome to"<<endl;
	cout<<"\n";
	cout<<"\t\t\t            ||||            "<<endl;
	cout<<"\t\t\t          |#|  |#|          "<<endl;
	cout<<"\t\t\t         |#|    |#|         "<<endl;
	cout<<"\t\t\t        |#|      |#|       "<<endl;
	cout<<"\t\t\t       |#|        |#|    "<<endl;
	cout<<"\t\t\t      |#|          |#|   "<<endl;
	cout<<"\t\t\t    ######        ###### "<<endl;
	cout<<"\t\t\t||||||||||||||||||||||||||||"<<endl;
	cout<<"\t\t\t||                        ||"<<endl;
	cout<<"\t\t\t||  ####################  ||"<<endl;
	cout<<"\t\t\t||  ##                ##  ||"<<endl;
	cout<<"\t\t\t||  ##  ||||||||||||  ##  ||"<<endl;
	cout<<"\t\t\t||  ##  ||Proyojon||  ##  ||"<<endl;
	cout<<"\t\t\t||  ##  ||        ||  ##  ||"<<endl;
	cout<<"\t\t\t||  ##  ||  Mart  ||  ##  ||"<<endl;
	cout<<"\t\t\t||  ##  ||||||||||||  ##  ||"<<endl;
	cout<<"\t\t\t||  ##                ##  ||"<<endl;
	cout<<"\t\t\t||  ####################  ||"<<endl;
	cout<<"\t\t\t||                        ||"<<endl;
	cout<<"\t\t\t||||||||||||||||||||||||||||"<<endl;
    cout<<"\n";
    cout<<"\n";
    cout<<"\t\t\t       Proyojon Mart"<<endl;
    }
};

void addnew()
{
	system("cls");

	cout<<"\nEnter How Many Products you want to Add: ";
    cin>>n;

    if (n!=0)
    {

	int j,l,sum=0;
	fout.open("shop.dat",ios::binary|ios::app);
	for(i=0;i<n;i++)

	{
		cout<<"\n\nEnter Product Details You Want to Add\n\n";
	    st.get();
	    fout.write((char*)&st,sizeof(st));
        cout<<"\n\nProduct Added";
		cin.get();
    }
    cout<<"\n\nStock Updated";

    fout.close();
    cin.get();
    system("cls");
    disp();
}
	else
{
	fout.close();
	cin.get();
	system("cls");
	cout<<"\n\nNo items to be added";
}
}

void buy()
{
	system("cls");
	char temp[100];
	int qty;
	int i=0;
	long pos=0;
	disp();

	cout<<"\n\n\n\n---------------------------------------------"<<endl;
	cout<<"Enter Product Details You Want to Buy\n";
	cout<<"\n\nProduct's Name: ";
	cin>>temp;
	cout<<"\n\nEnter Quantity: ";
	cin>>qty;
	fio.open("shop.dat",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stchk(temp)==0)
	    {
		  st.withd(qty);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		  i++;
		  break;
	    }
     }

     if(i!=1)
       cout<<"\n\nNo Products";
     fio.close();
    cin.get();
    system("cls");
	 disp();
	getch();
}

void disp()
{
	int i=1;

	cout<<"\t\tProyojon Mart"<<endl;
	cout<<"---------------------------------------------"<<"\n"<<endl;
	cout<<"-------- \t-------------- \t\t-----"<<endl;
	cout<<"Products \tStock Quantity \t\tPrice"<<endl;
	cout<<"-------- \t-------------- \t\t-----"<<endl;
	 fin.open("shop.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof())
	  {
	     if(fin.tellg()<0)
	     {	i=0; break;}
	     st.show();
	  }
     }
     if(i==0)
     {
        cout<<"\n\nNo Products";
     }
     fin.close();

}

void refill()
{
	system("cls");
	char temp[100];
	int qty;
	float prc;
	int i=0;
	long pos=0;
	disp();

	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"----------------------------------------\n";
	cout<<"Enter Product Details You Want to Update\n";
	cout<<"----------------------------------------\n";
	cout<<"\nProducts Name: ";
	cin>>temp;
	cout<<"\nQuantity: ";
	cin>>qty;
	cout<<"\nPrice: ";
	cin>>prc;
	fio.open("shop.dat",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stchk(temp)==0)
	    {
		  st.refil(qty,prc);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		  i++;break;
	    }
     }
     if(i!=1)
       cout<<"\n\nNo Products";
     fio.close();
    system("cls");
    cin.get();
    disp();
    cin.get();
}

void remove()
{
	system("cls");
	 int i=0;
     char temp[30];

     disp();

    cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"----------------------------------------\n";
	cout<<"Enter Product Details You Want to Remove\n";
	cout<<"----------------------------------------\n";

     cout<<"\nProduct's Name: ";
     cin>>temp;
     fout.open("temp.dat",ios::binary);
     fin.open("shop.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof())
	    if(st.stchk(temp)==0)
	    {
		  st.show();
		  cout<<"\nProduct Removed";
		  i++;
	    }
	    else
		  fout.write((char*)&st,sizeof(st));
     }
     if(i==0)
       cout<<"\nNot found!!";
     fin.close();
     fout.close();
     remove("shop.dat");
     rename("temp.dat","shop.dat");

     system("cls");
     cout<<"Product is Removed";
     getch();
     system("cls");
     disp();
}

int main()
{
	logo lg;
	int i,j, pass, pass2;

    lg.iubat_logo();
	getch();
	system("cls");

	lg.proyojon_mart_logo();
	getch();
	system("cls");

    mainmenu:
	cout<<"\n";
	cout<<"Proyojon Mart\n";
	cout<<"--------------"<<endl;
	cout<<"\n";
	cout<<"1. Dealer Menu"<<"\n"<<endl;
	cout<<"2. Customer Menu"<<endl;
	cout<<"\n"<<endl;
	cout<<"\n"<<endl;
	cout<<"Enter Your Choice: ";
	cin>>j;
	if(j==1)
	{
	system("cls");
    system("cls");

    cout<<"\n";
    cout<<"Login Area"<<endl;
    cout<<"----------"<<"\n"<<endl;

    cout<<"Enter User ID: ";//User ID: 18103198
    cin>>pass;

    cout<<"\n";

    cout<<"Enter Password: ";//Password: 1234
    cin>>pass2;

	if(pass==18103198 && pass2==1234)
	{
    system("cls");
	dealermenu:
	system("cls");
	cout<<"Dealer Menu"<<endl;
	cout<<"-----------"<<"\n"<<endl;
	cout<<"1. Add New Product"<<"\n"<<endl;
	cout<<"2. Display stock"<<"\n"<<endl;
	cout<<"3. Update Stock"<<"\n"<<endl;
	cout<<"4. Remove an Item"<<"\n"<<endl;
	cout<<"5. Go to Main Menu"<<"\n"<<endl;
	cout<<"6. Exit"<<endl;
	cout<<"\n";
	cout<<"\n";
	cout<<"\nEnter your Choice: ";
	cin>>i;
	if(i==1)
	{
		addnew();
		getch();
	goto dealermenu;
	}

	else if(i==2)
	{
		system("cls");
	disp();
	getch();
	goto dealermenu;
	}
	else if(i==3)
	{
		refill();
		goto dealermenu;
	}
	else if(i==4)
	{
		remove();
		getch();
		goto dealermenu;
	}
	else if(i==5)
	{
		system("cls");
		goto mainmenu;
	}
	else
	{
    system("cls");
	exit(0);
}
}
else
{
	system("cls");
	cout<<"Wrong Password\n\n";
	cout<<"Access Denied\n\n";
	exit(0);
}
	}
	if(j==2)
	{
		custmenu:
	system("cls");
	cout<<"Customer Menu"<<endl;
	cout<<"-------------"<<"\n"<<endl;
	cout<<"1. Buy Products"<<"\n"<<endl;
	cout<<"2. Display Product List"<<"\n"<<endl;
	cout<<"3. Go to Main Menu"<<"\n"<<endl;
	cout<<"4. Exit"<<endl;
	cout<<"\n";
	cout<<"\n";
	cout<<"\n\nEnter your Choice: ";
	cin>>i;

	if (i==1)
	{
	buy();
	getch();
	goto custmenu;
	}

	if(i==2)
	{
    system("cls");
	disp();
	getch();
	goto custmenu;
	}

	if(i==3)
	{
		system("cls");
		goto mainmenu;
	}

	else
	{
    system("cls");
	exit(0);
    }
    }
getch();
}
