#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Item
{
	string ItemName;
	int IID;
	int SID;
	float price;
public:
	Item()
	{
		ItemName="";
		SID=0;
		IID=0;
		price=0.0;
	}
	Item(string ItemName,int IID,int SID,float price)
	{
		this->ItemName=ItemName;
		this->IID=IID;
		this->SID=SID;
		this->price=price;
	}

	void setItem(string ItemName,int IID,int SID,float price)
	{
		if(SID<0 && IID<0 && price<0)
		{
			;
		}

		else
		{
			this->ItemName=ItemName;
			this->IID=IID;
			this->SID=SID;
			this->price=price;
		}
	}

	bool operator==(const Item & items)
	{
		if(this->ItemName==items.ItemName && this->IID==items.IID && this->SID==items.SID)
		{
			return true;
		}

		else
			return false;
	}

	string getItemName()
	{
		return ItemName;
	}

	int getIID()
	{
		return IID;
	}

	int getSID()
	{
		return SID;
	}
	
	float getItemPrice()
	{
		return price;
	}
};
class ShopingCart
{
	Item items[30];
	int counter;

public:
	ShopingCart()
	{
		counter=0;
	}

	void AddItemsToCart(Item items)
	{
		if(counter<30)
		{
			this->items[counter]=items;
			counter++;
		}

		else
			;

	}

	void RemoveItemFromCart(Item item)
	{
		if(counter>0)
		{
			for(int i=0;i<counter;i++)
			{
				if(this->items[i]==item)
				{
					items[i] =items[counter];
					counter--;
				}
			}
		}
	}

	int getItemCount()
	{
		return counter;
	}
};

class Customer
{
	string CustomerName;
	ShopingCart SCobj;
	int SID;
public:
	Customer()
	{
		CustomerName="";
		SID=0;
	}
	Customer(string CustomerName,int SID,ShopingCart SCobj)
	{
		this->CustomerName=CustomerName;
		this->SCobj=SCobj;

		if(SID>0)
		{
			this->SID=SID;
		}
	}

	void setSC(string CustomerName,int SID,ShopingCart SCobj)
	{
		this->CustomerName=CustomerName;
		this->SCobj=SCobj;

		if(SID>0)
		{
			this->SID=SID;
		}
	}

	ShopingCart getSC()
	{
		return SCobj;
	}

	int getSID()
	{
		return SID;
	}

	string getName()
	{
		return CustomerName;
	}
};

class Store
{
protected:
	string StoreName;
	int SID;
	Item items[30];
	Customer customers[30];
	int CustomerCount ;
	int stock;
public:
	Store()
	{
		StoreName="";
		SID=0;
		CustomerCount=0;
		stock=0;
	}
	Store(string StoreName,int SID,int stock)
	{
		this->StoreName=StoreName;
		this->SID=SID;
		this->stock=stock;
		CustomerCount=0;
	}

	void setStore(string StoreName,int SID,int stock)
	{
		this->StoreName=StoreName;
		this->SID=SID;
		this->stock=stock;
		CustomerCount=0;
	}

	virtual void enter (Customer &c)=0;
	virtual void exit (Customer &c)=0;
	virtual void AddToCart(ShopingCart &cart,Item &items)=0;
	virtual void RemoveFromCart(ShopingCart &cart,Item &items)=0;

};

class BookStore :public Store
{
public:
	BookStore():Store("Book Store",1,0)
	{
		AddItems();
	}

	void AddItems()
	{
		items[0].setItem("OOP",2,1,600);
		items[1].setItem("Cal",3,1,500);
		items[2].setItem("BE",4,1,400);
		items[3].setItem("DM",5,1,300);
		stock=4;
	}

	void enter(Customer &c)
	{
		cout<<"Welcome To The Book Store"<<endl<<endl<<endl;
		purchase(c);

	}

	void purchase(Customer &c)
	{
		cout<<"Store ID :"<<items[0].getSID()<<endl<<endl<<endl;
		for(int i=0;i<stock;i++)
		{
			
			cout<<"Name :"<<items[i].getItemName()<<endl;
			cout<<"Item ID :"<<items[i].getIID()<<endl;
			cout<<"Price :"<<items[i].getItemPrice()<<endl;

			cout<<endl;
		}

		cout<<"Enter Id of the book you want to buy :";
		cout<<"              OR             "<<endl;
		cout<<"Press 0 to leave "<<endl;
		int id;
		cin>>id;
		if(id==0)
		{
			
		}

		else 
		{
		bool find;
		find=false;

		for (int i=0;i<stock;i++)
			{
				if (id==items[i].getIID())
					{
						AddToCart(c.getSC(),items[i]);
						find=true;
						cout<<"item added"<<endl;
						break;
					}
			}

		if (find==false)
		{
			cout<<"Book Not Found"<<endl;
		}

		Sleep(2000);
		system("cls");
		cout<<"To Shop more press 1 "<<endl;
		cout<<"To Exit Press 2"<<endl;
		cout<<"Your Choice :";
		int x;
		cin>>x;

		system ("cls");

		if(x==1)
		{
			purchase(c);
		}

		else if(x==2)
		{
			exit(c);
		}

		else 
		{cout<<"You made a wrong call "<<endl;
		Sleep(2000);
		}

		}
	}	

	void exit(Customer &c)
	{
		cout<<"Thanks for comming"<<endl;
	}

	void AddToCart(ShopingCart &cart,Item &items)
	{
		cart.AddItemsToCart(items);
	}
	void RemoveFromCart(ShopingCart &cart,Item &items)
	{
		cart.RemoveItemFromCart(items);
	}
};	

class ShoeStore :public Store
{
public:
	ShoeStore():Store("Book Store",2,0)
	{
		AddItems();
	}

	void AddItems()
	{
		items[0].setItem("Adidas",9,2,600);
		items[1].setItem("Nike",9,2,500);
		items[2].setItem("Levis",9,2,400);
		items[3].setItem("Fayva",9,2,300);
		stock=4;
	}

	void enter(Customer &c)
	{
		cout<<"Welcome To The Shoe Store"<<endl<<endl<<endl;
		purchase(c);

	}

	void purchase(Customer &c)
	{
		cout<<"Store ID :"<<items[0].getSID()<<endl<<endl<<endl;
		for(int i=0;i<stock;i++)
		{
			
			cout<<"Name :"<<items[i].getItemName()<<endl;
			cout<<"Shoe Size :"<<items[i].getIID()<<endl;
			cout<<"Price :"<<items[i].getItemPrice()<<endl;

			cout<<endl;
		}

		cout<<"Enter Name of the shoe you want to buy :";
		cout<<"              OR             "<<endl;
		cout<<"Press 0 to leave "<<endl;
		string sname;
		cin>>sname;
		if(sname=="0")
		{
			
		}

		else 
		{
		bool find;
		find=false;

		for (int i=0;i<stock;i++)
			{
				if (sname==items[i].getItemName())
					{
						AddToCart(c.getSC(),items[i]);
						find=true;
						cout<<"item added"<<endl;
						break;
					}
			}

		if (find==false)
		{
			cout<<" Not Found"<<endl;
		}

		Sleep(2000);
		system("cls");
		cout<<"To Shop more press 1 "<<endl;
		cout<<"To Exit Press 2"<<endl;
		cout<<"Your Choice :";
		int x;
		cin>>x;

		system ("cls");

		if(x==1)
		{
			purchase(c);
		}

		else if(x==2)
		{
			exit(c);
		}

		else 
		{cout<<"You made a wrong call "<<endl;
		Sleep(2000);
		}

		}
	}	

	void exit(Customer &c)
	{
		cout<<"Thanks for comming"<<endl;
	}

	void AddToCart(ShopingCart &cart,Item &items)
	{
		cart.AddItemsToCart(items);
	}
	void RemoveFromCart(ShopingCart &cart,Item &items)
	{
		cart.RemoveItemFromCart(items);
	}
};	

class GameStore :public Store
{
public:
	GameStore():Store("Game Store",3,0)
	{
		AddItems();
	}

	void AddItems()
	{
		items[0].setItem("COD",2,3,600);
		items[1].setItem("PUBG",3,3,500);
		items[2].setItem("CS",4,3,400);
		items[3].setItem("GTA",5,3,300);
		stock=4;
	}

	void enter(Customer &c)
	{
		cout<<"Welcome To The Game Store"<<endl<<endl<<endl;
		purchase(c);

	}

	void purchase(Customer &c)
	{
		cout<<"Store ID :"<<items[0].getSID()<<endl<<endl<<endl;
		for(int i=0;i<stock;i++)
		{
			
			cout<<"Name :"<<items[i].getItemName()<<endl;
			cout<<"Item ID :"<<items[i].getIID()<<endl;
			cout<<"Price :"<<items[i].getItemPrice()<<endl;

			cout<<endl;
		}

		cout<<"Enter Id of the book you want to buy :";
		cout<<"              OR             "<<endl;
		cout<<"Press 0 to leave "<<endl;
		int id;
		cin>>id;
		if(id==0)
		{
			
		}

		else 
		{
		bool find;
		find=false;

		for (int i=0;i<stock;i++)
			{
				if (id==items[i].getIID())
					{
						AddToCart(c.getSC(),items[i]);
						find=true;
						cout<<"item added"<<endl;
						break;
					}
			}

		if (find==false)
		{
			cout<<"Game Not Found"<<endl;
		}

		Sleep(2000);
		system("cls");
		cout<<"To Shop more press 1 "<<endl;
		cout<<"To Exit Press 2"<<endl;
		cout<<"Your Choice :";
		int x;
		cin>>x;

		system ("cls");

		if(x==1)
		{
			purchase(c);
		}

		else if(x==2)
		{
			exit(c);
		}

		else 
		{cout<<"You made a wrong call "<<endl;
		Sleep(2000);
		}

		}
	}	

	void exit(Customer &c)
	{
		cout<<"Thanks for comming"<<endl;
	}

	void AddToCart(ShopingCart &cart,Item &items)
	{
		cart.AddItemsToCart(items);
		cout<<"\nItem Added"<<endl;
	}
	void RemoveFromCart(ShopingCart &cart,Item &items)
	{
		cart.RemoveItemFromCart(items);
		cout<<"\nItem Removed"<<endl;
	}
};	

class Mall
{
	string MallName;
	Customer Cobj;
public:
	Mall(string MallName)
	{
		this->MallName=MallName;
	}
	
	void EnterInMAll(Customer &c)
	{

		back:

		cout<<"   //``````````````````````````````````````````````````//"<<endl;
		cout<<"  //			  WELCOME TO		      //"<<endl;
		cout<<" //			BHAMBHEERI MALL		     //"<<endl;
		cout<<"//..................................................//"<<endl<<endl<<endl;

		cout<<"Stores In the Mall"<<endl<<endl;

		cout<<"1) Book Store "<<endl;
		cout<<"2) Shoe Store "<<endl;
		cout<<"3) Game Store "<<endl<<endl;

		cout<<"Store # you want to visit or 0 to exit:";
		int storeno;
		cin>>storeno;

		system("cls");

		if (storeno==0)
		{
			goto end;
		}

		if(storeno==1)
		{
			BookStore obj;
			obj.enter(c);

			Sleep(1000);
			system("cls");

			int again;


			cout<<"Press 1 to enter to another store else 0 to exit :";
			cin>>again;

			system("cls");
			while(1)
			{
				if(again==1)
				{
					goto back;
				}

				else
				{
					goto end;
				}
			}
		}

		else if(storeno==2)
		{
			ShoeStore obj;
			obj.enter(c);

			Sleep(1000);
			system("cls");

			int again;


			cout<<"Press 1 to enter to another store else 0 to exit :";
			cin>>again;

			system("cls");
			while(1)
			{
				if(again==1)
				{
					goto back;
				}

				else
				{
					goto end;
				}
			}


		}

		else if(storeno==3)
		{
			GameStore obj;
			obj.purchase(c);

			Sleep(1000);
			system("cls");

			int again;


			cout<<"Press 1 to enter to another store else 0 to exit :";
			cin>>again;

			system("cls");
			while(1)
			{
				if(again==1)
				{
					goto back;
				}

				else
				{
					goto end;
				}
			}
		}

		else
			cout<<"\n\nyou made a wrong choice See you Next time\n"<<endl;
end:
		cout<<"Have a Nice Day \n BHAMBHEERI MAll SERVING PAKISTAN\n\n";
	}
};

void main()
{
	Customer c;
	Mall obj("Bhambheeri");
	obj.EnterInMAll(c);
}