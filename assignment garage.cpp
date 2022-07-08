#include<iostream>
using namespace std;
const int maxsize=20;
void list();
void signture();
class car 
{ 
	int seatsNo,n,carID,passengers; double seatPrice;string driverName;                             
	public:
	car()//deafault constractor
	{seatsNo =0;passengers =0;seatPrice =0;carID=0;driverName ="Empty";}
	car(int carID,int SNo, double Sprice,int p,string dName)
	{this->carID=carID;seatsNo =SNo;seatPrice =Sprice;passengers =p;driverName =dName;}		
	
	void setSNo(int SNo){seatsNo=SNo;}
	void setCarId(int carID){this->carID=carID;}
	void setSPrice(double Sprice){seatPrice=Sprice;}
	void setPassengers(int p){passengers=p;}
	void setDName(string dName){driverName=dName;}

	int getSNo(){return seatsNo;}
	int getCarId(){return this->carID;}
	int getPassengers(){return passengers;}
    double getSPrice(){return seatPrice;}
	string getDName(){return driverName;}
	
	~car() {}
	
	void operator=(car c)
 	{setCarId(c.getCarId());setSNo(c.getSNo());setDName(c.getDName());setSPrice(c.getSPrice());setPassengers(c.getPassengers());}
 
};
// --------------------- the start of queue class -------------------------//
class queue
{
	int front,rear,count;
	car c[maxsize];
	public:
	queue(){count=0;front=0;rear=maxsize-1;}
	bool empty(){return(count==0);}
	bool append(int carID, int SNo,int p,double Sprice, string dName)
    {
  if(count==maxsize)return 0;
  rear=(rear+1)%maxsize;
  c[rear].setCarId(carID);c[rear].setSNo(SNo);c[rear].setSPrice(Sprice);c[rear].setPassengers(p);c[rear].setDName(dName);
  count++;return 1;
	}
	bool append2(car temp)
    {
  if(count==maxsize)return 0;
  rear=(rear+1)%maxsize;
  c[rear]=temp;
  count++;return 1;
	}
	bool serve(){if(empty())return 0;front=(front+1)%maxsize;count--;return 1;}	
	car retrieve(car &item){switch (empty())case 0: break;item=c[front];return item;}

};
void checkServedID(queue served,int &carID,string &dName,double &Sprice,int &seatsNo)
{
	car ncar;
	int item;
	served.retrieve(ncar);
	while(!served.empty())
	{
		while(ncar.getCarId()==carID&&(ncar.getDName()!=dName||ncar.getSPrice()!=Sprice||ncar.getSNo()!=seatsNo))
		 {
		 cout<<"sorry!! enter car ID that not used before\n";
 		 cout<<"car ID : ";
 		 cin>>carID;
 		 cout<<"the driver name for this id :"<<ncar.getDName()<<endl;
 		 cin>>dName;
 		 cout<<"the car seats number :"<<ncar.getSNo();
 		 cin>>seatsNo;
 		 cout<<"the car seat price :"<<ncar.getSPrice();
 		 cin>>Sprice;
	     cout<<"\n-------------------------\n\n";
 
	     
		 }
		 served.serve();
	}
}
void checkingCarId(queue &q,int carid)// auto method
{
	car ncar;
	q.retrieve(ncar);	   	
	while(carid==ncar.getCarId())
	  {
	  if(carid!=ncar.getCarId()){q.serve();break;}
	 cout<<"sorry!! enter car ID that not used before\n";
	 cout<<"car ID : ";
	 cin>>carid;
	 cout<<"\n-------------------------\n\n";
	  }
  ncar.setCarId(carid);
  
}
  

void addcar(queue &q,queue &served)
{
	int SNo,carID, p;double Sprice;string dName;car ncar;
	cout<<"enter the car id : ";
	cin>>carID;
	cout<<"enter the seat number : ";
	cin>>SNo;
	cout<<"enter the number of passenger : ";
	cin>>p;
	cout<<"enter the seat price : ";
	cin>>Sprice;
	cout<<"enter the driver name : ";
	cin>>dName;
	while(p>SNo)
	{
		cout<<"The Number of Passengers (More than) the seat number!! please enter possiable values"<<endl;
		cin>>p;
	}	
	checkingCarId(q,carID);
	checkServedID(served,carID,dName,Sprice,SNo);
	q.append(carID,SNo,p,Sprice,dName);
	
}
void addcar2(queue &q,queue served)
{
	int SNo,carID, p;double Sprice;string dName;car ncar;
	cout<<"enter the car id : ";
	cin>>carID;
	cout<<"enter the seat number : ";
	cin>>SNo;
	cout<<"enter the number of passenger : ";
	cin>>p;
	cout<<"enter the seat price : ";
	cin>>Sprice;
	cout<<"enter the driver name : ";
	cin>>dName;
	while(p>SNo)
	{
		cout<<"The Number of Passengers (More than) the seat number!! please enter possiable values"<<endl;
		cin>>p;
	}	
	checkingCarId(q,carID);
	checkServedID(served,carID,dName,Sprice,SNo);
	q.append(carID,SNo,p,Sprice,dName);
	
}
void RemoveCar(queue &q,queue &served)
{
	car ncar;
	q.retrieve(ncar);
	served.append2(ncar);
	cout<<"the passengers in this travel ==> "<<ncar.getPassengers()<<endl;
	cout<<"the car was removed sucessfully!!"<<endl;
	q.serve();	
}
void CarForword(queue &q,queue &served)
{
	car ncar;int ID;queue temp;
	cout<<"enter the car you want to forward it : ";
	cin>>ID;
	while(!q.empty())
	{	
	q.retrieve(ncar);
	if(ncar.getCarId()==ID)
	{
	served.append2(ncar);
	q.serve();
	}
	else {
	temp.append2(ncar);
	q.serve();
	}
	 }
	 while(!temp.empty())
	 {
 		temp.retrieve(ncar);
 		q.append2(ncar);
 		temp.serve();
 		
 	 }
}	
void InsertCar(queue &q,queue served)
{	car ncar;
	queue temp1;
	int n;
	cout<<"enter the postion number"<<endl;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		q.retrieve(ncar);
		temp1.append2(ncar);
		q.serve();	
	}
	addcar2(q,served);
	while(!q.empty())
	{
		q.retrieve(ncar);
		temp1.append2(ncar);
		q.serve();
	}
	while(!temp1.empty())
	{
		temp1.retrieve(ncar);
		q.append2(ncar);
		temp1.serve();
	}	
	

	
}
void GarageInfo(queue q)
{
	car ncar;
	if(q.empty())cout<<"(((the garage is empty)))"<<endl;
	while(!q.empty())
	{
	q.retrieve(ncar);
	cout<<"*************************************************\n"<<endl;
	cout<<"Driver Name : "<<ncar.getDName()<<endl;
	cout<<"Car ID : "<<ncar.getCarId()<<endl;
	cout<<"Seat number : "<<ncar.getSNo()<<endl;
	cout<<"number of passengers :"<<ncar.getPassengers()<<endl;
	cout<<"Seat price : "<<ncar.getSPrice()<<endl;
	cout<<"\n"<<endl;
	q.serve();
	}
}

double GarageIncome(queue q,queue served)
{
	double Totalincome=0,income_garage=0,income_served=0;
	car ncar;
	
	while(!q.empty())
	{
		q.retrieve(ncar);
		income_garage+=(ncar.getSPrice()*ncar.getPassengers()*1.0);
		q.serve();
	}
		while(!served.empty())
	{
		served.retrieve(ncar);
		income_served+=(ncar.getSPrice()*ncar.getPassengers()*1.0);
		served.serve();
	}
	Totalincome=income_garage+income_served;
	cout<<"Total garage income ==> ";
	return Totalincome;
	
}


car fun(queue super,car c)
{
	if(super.empty())return c;
	while(!super.empty())
	{
		car temp;
		super.retrieve(temp);
		if(temp.getCarId()==c.getCarId())
		{
			c.setPassengers(temp.getPassengers()+c.getPassengers());
		}
		super.serve();
		return c;
	}
}
car superDriver(queue q,queue served)
{
	queue temp;
	queue super;
	car ncar;
	while(!q.empty())
	{
		q.retrieve(ncar);
		temp.append2(ncar);
		q.serve();
	}
		while(!served.empty())
	{
		served.retrieve(ncar);
		temp.append2(ncar);
		served.serve();
	}
	while(!temp.empty())
	{
		temp.retrieve(ncar);
		super.append2(fun(super,ncar));
		temp.serve();
	}
	car maxS;
	super.retrieve(maxS);
	while(!super.empty())
	{
		super.retrieve(ncar);
		if(ncar.getPassengers()*ncar.getSPrice()>(maxS.getPassengers()*maxS.getSPrice()))
		maxS=ncar;
		super.serve();	
	}
	return maxS;
} 

main()
{
  	 queue q ,served;
	 int choice,SNo, p;
	 double Sprice;
	 string dName;
	 car c;
	do{
	    list();
		cin>>choice;
		if(choice==1){
		cout<<"*************************************************\n"<<endl;
		addcar(q,served);
		cout<<"\n*************************************************\n"<<endl;
		}
		else if(choice==2)
		{
		cout<<"*************************************************\n"<<endl;
		RemoveCar(q,served);
		cout<<"\n*************************************************\n"<<endl;
		}
		else if(choice==3)
		{
		cout<<"*************************************************\n"<<endl;
		CarForword(q,served);
		cout<<"\n*************************************************\n"<<endl;
		}
		else if(choice==4)
		{
		cout<<"*************************************************\n"<<endl;
		InsertCar(q,served);
		cout<<"\n*************************************************\n"<<endl;
		}
		else if(choice==5)
		{
		cout<<"*************************************************\n"<<endl;
		GarageInfo(q);
		cout<<"\n*************************************************\n"<<endl;
		}
		else if(choice==6){
		cout<<"*************************************************\n"<<endl;
		cout<<GarageIncome(q,served)<<endl;
		cout<<"\n*************************************************\n"<<endl;
		}
		else if(choice==7){
		car c2 = superDriver(q,served);
		cout<<"*************************************************\n"<<endl;
		cout<<"the name of the super driver : "<<c2.getDName()<<endl;
		cout<<"the income that achive it : "<<(c2.getPassengers()*c2.getSPrice());
		cout<<"\n*************************************************\n"<<endl;
		cout<<endl;}
		else if(choice>9){
		cout<<"*************************************************\n"<<endl;
		cout<<"please enter between 1-8 only!!"<<endl;
		cout<<"\n*************************************************\n"<<endl;
		}

	 }while(choice!=8);
	 return 0;
}
void list()
{
	cout<<"1.Add a car to the garage"<<endl;
	cout<<"2.Remove a car"<<endl;
	cout<<"3.Forward a car"<<endl;
	cout<<"4.Insert a car at"<<endl;
	cout<<"5.Print garage information "<<endl;
	cout<<"6.Garage income "<<endl;
	cout<<"7.Super driver "<<endl;
	cout<<"8.Exit"<<endl;

	cout<<"please enter your choice : ";
}
