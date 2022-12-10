#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<sstream>
#include<stdlib.h>
#define MAX_SIZE 5
using namespace std;

fstream fp;

class node1{
	public:
		int year;
		long long int price;
		string name,engnt,engnc,trans,color,asmb;
		node1 *next;
		
		string getname()
	    {
	    	return name;
		}
		int getyear()
		{
			return year;
		}
		string getengnt()
		{
			return engnt; 
		}
		string gettrans()
		{
			return trans;
		}
};

class hisobj{
	public:
	    char name[50],engnt[20],trans[20];
	    int year;
	    void input(int y,char *na,char *e,char *t)
	    {
	    	strcpy(name,na);
	    	strcpy(engnt,e);
	    	strcpy(trans,t);
	    	year = y;
		}
		void show()
		{
			cout<<name<<endl;
			cout<<year<<endl;
			cout<<engnt<<endl;
			cout<<trans<<endl;
		}
};

hisobj o1;

class llist{
	public:
		node1 *head;
		llist()
		{
			head = NULL;
		}
		void addnode(string *arr)
		{
			stringstream ss,st;
			node1 *temp = head;
			node1 *newnode = new node1;
			newnode->name = arr[0];
			ss << arr[1];
			ss >> newnode->price;
			st << arr[2];
			st >> newnode->year;
			newnode->engnt = arr[3];
			newnode->engnc = arr[4];
			newnode->trans = arr[5];
			newnode->color = arr[6];
			newnode->asmb = arr[7];
			newnode->next = NULL;
			if(temp == NULL){
				head = newnode;
   			}else{
				while(temp->next != NULL){
					temp = temp->next;
				}
				temp->next = newnode;
			}		
		}
		
		void addnodelast(string *arr)
		{
			stringstream ss,st;
			node1 *newnode = new node1;
			newnode->name = arr[0];
			ss << arr[1];
			ss >> newnode->price;
			st << arr[2];
			st >> newnode->year;
			newnode->engnt = arr[3];
			newnode->engnc = arr[4];
			newnode->trans = arr[5];
			newnode->color = arr[6];
			newnode->asmb = arr[7];
			if(head == NULL){
				newnode->next = NULL;
				head = newnode;
   			}else{
				newnode->next = head;
				head = newnode;
			}	
		}
			
		void displaycar()
		{
			node1 *temp = head;
			if(temp == NULL){
				cout<<"\n\n..........................SORRY NO RESULTS FOUND.....................\n";
			}else{
				int i = 1;
				while(temp != NULL){
					cout<<"\n\t\t\t--------CAR "<<i<<" )"<<endl; 
					cout<<temp->name<<endl;
					cout<<temp->price<<endl;
					cout<<temp->year<<endl;
					cout<<temp->engnt<<endl;
					cout<<temp->engnc<<endl;
					cout<<temp->trans<<endl;
					cout<<temp->color<<endl;
					cout<<temp->asmb<<endl;
					cout<<"\n\n\n";
					temp = temp->next;
					i++;
				}
			}
		}
		void display(node1 *temp)
		{
			cout<<"\n\n\n";
			cout<<temp->name<<endl;
			cout<<temp->price<<endl;
			cout<<temp->year<<endl;
			cout<<temp->engnt<<endl;
			cout<<temp->engnc<<endl;
			cout<<temp->trans<<endl;
			cout<<temp->color<<endl;
	    	cout<<temp->asmb<<endl;
		}	
		void cropprice(long long int lb,long long int ub)
		{
			node1 *temp1 = head,*temp2;
			if(temp1 == NULL){
				return;
			}else{
				while(temp1->price <= lb){
					head = temp1->next;
					free(temp1);
					temp1 = temp1->next;
				}
				while(temp1->next->price <= ub){
					temp1 = temp1->next;
				}
				temp1->next = NULL;
			}
	    }
	    void yearcrop(int year)
	    {
	    	node1 *temp1 = head,*temp2;
			if(temp1 == NULL){
				return;
			}else{
				while(temp1->year < year){
					head = temp1->next;
					free(temp1);
					temp1 = temp1->next;
				}
				while(temp1->next->year <= year){
					temp1 = temp1->next;
				}
				temp1->next = NULL;
			}
		}
		void cropname(string na)
		{
			node1 *temp1 = head;
			int n;
			if(temp1 == NULL){
				return;
			}else{
				do{
					n=0;
					temp1 = head;
					if(temp1->next == NULL){
						break;
					}
					if(temp1->name.find(na) > 10 && temp1 == head){
						head = head->next;
						n = 1;
					}else if(temp1->next->name.find(na) > 10 && temp1->next->next == NULL){
						temp1->next = NULL;
						n = 1;
					}else{
						while(temp1->next->name.find(na) < 10 ){
							temp1 = temp1->next;
							if(temp1->next == NULL){
								break;
							}
						}
						if(temp1->next == NULL){
							break;
						}
						if(temp1->next->next == NULL){
							temp1->next = NULL;
							n = 1;
					    }else{
					    	temp1->next = temp1->next->next;
							n = 1;
						}
					}
				}while(n == 1);
			}
		}	
		void cropengntype(string type)
		{
			node1 *temp1 = head;
			int n;
			if(temp1 == NULL){
				return;
			}else{
				do{
					n=0;
					temp1 = head;
					if(temp1->next == NULL){
						break;
					}
					if(temp1->engnt.find(type) > 10 && temp1 == head){
						head = head->next;
						n = 1;
					}else if(temp1->next->engnt.find(type) > 10 && temp1->next->next == NULL){
						temp1->next = NULL;
						n = 1;
					}else{
						while(temp1->next->engnt.find(type) < 10 ){
							temp1 = temp1->next;
							if(temp1->next == NULL){
								break;
							}
						}
						if(temp1->next == NULL){
							break;
						}
						if(temp1->next->next == NULL){
							temp1->next = NULL;
							n = 1;
					    }else{
					    	temp1->next = temp1->next->next;
							n = 1;
						}
					}
				}while(n == 1);
			}
		}
		void enginecc(string cc)
		{
			node1 *temp1 = head;
			int n;
			if(temp1 == NULL){
				return;
			}else{
				do{
					n=0;
					temp1 = head;
					if(temp1->next == NULL){
						break;
					}
					if(temp1->engnc.find(cc) > 10 && temp1 == head){
						head = head->next;
						n = 1;
					}else if(temp1->next->engnc.find(cc) > 10 && temp1->next->next == NULL){
						temp1->next = NULL;
						n = 1;
					}else{
						while(temp1->next->engnc.find(cc) < 10 ){
							temp1 = temp1->next;
							if(temp1->next == NULL){
								break;
							}
						}
						if(temp1->next == NULL){
							break;
						}
						if(temp1->next->next == NULL){
							temp1->next = NULL;
							n = 1;
					    }else{
					    	temp1->next = temp1->next->next;
							n = 1;
						}
					}
				}while(n == 1);
			}
		}
		void croptrans(string tr)
		{
			node1 *temp1 = head;
			int n;
			if(temp1 == NULL){
				return;
			}else{
				do{
					n=0;
					temp1 = head;
					if(temp1->next == NULL){
						break;
					}
					if(temp1->trans.find(tr) > 10 && temp1 == head){
						head = head->next;
						n = 1;
					}else if(temp1->next->trans.find(tr) > 10 && temp1->next->next == NULL){
						temp1->next = NULL;
						n = 1;
					}else{
						while(temp1->next->trans.find(tr) < 10 ){
							temp1 = temp1->next;
							if(temp1->next == NULL){
								break;
							}
						}
						if(temp1->next == NULL){
							break;
						}
						if(temp1->next->next == NULL){
							temp1->next = NULL;
							n = 1;
					    }else{
					    	temp1->next = temp1->next->next;
							n = 1;
						}
					}
				}while(n == 1);
			}
		}
		void deletelist()
		{
			head = NULL;
		}	
};

llist l1,l2;
class user{
	int id;
	char name[50],adrs[100],pno[20],mail[50],pass[50];
	public:
		void enter(int id)
		{
			this->id = id;
			cout<<"ID : "<<this->id;
			cout<<"\nENTER YOUR NAME : ";
			gets(name);
			cout<<"ENTER YOUR PHONE NUMBER : ";
			gets(pno);
			cout<<"ENTER YOUR ADDRESS : ";
			gets(adrs);
			cout<<"ENTER YOUR EMAIL : ";
			gets(mail);
			cout<<"PLEASE ENTER 15 CHARACTER PASSWORD : ";
			gets(pass);
		}
		void show()
		{
			cout<<"\nNAME : "<<name;
			cout<<"\nPHONE : "<<pno<<endl;
		}
		int getid()
		{
			return id;
		}
		char* getpswrd()
		{
			return pass;
		}
		char* getname()
		{
			return name;
		}
};


class queue {     
	public:
		string search[MAX_SIZE];
		int front, rear;
		queue()
		{
			int i;
			front = -1;
			rear = -1;
			for(i=0;i<MAX_SIZE;i++){
				search[i] = "NA";
			}
		}
     
		int isFull(){
			if(front == 0 && rear == MAX_SIZE - 1){
			    return true;
			}else{
			    return false;
			}
		}
     
		int isEmpty()
		{
			if(front == -1) 
			    return true;
			else {
				return false;
			}
		}
     
		void enQueue(string arr)
		{
			if(isFull()){
			    cout << endl<< "Queue is full!!";
		    }else {
			    if(front == -1) front = 0;
				rear++;
				search[rear] = arr;
		    }
		}
		void deQueue(){
			string s;
			if(isEmpty()){
			    cout << "Queue is empty!!" << endl;
			    return; 
			}else { 
			    s = search[front]; 
			    if(front >= rear){    
			        front = -1;
			        rear = -1;
			    }else {
			        front++;
			    }
				cout << endl << "Deleted =>>" << s << " from myqueue";
		    }
		}
		void displayQueue()
		{ 
			int i;
			if(isEmpty()) {
			    cout << endl << "Queue is Empty!!" << endl;
			}else {
				cout << endl << "Front = " << front;
				cout << endl << "Queue elements : ";
				for(i=front; i<=rear; i++){
					cout << search[i] << "\t";
				}
				cout << endl << "Rear = " << rear << endl;
			}
		}
		void filing(int id)
		{
			int i;
			fp.open("qfiling.txt", ios::out | ios::app);
			fp<<id<<",";
			for(i=front;i<=rear;i++){
				if(i != rear){
					fp<<search[i]<<",";
				}else{
					fp<<search[i]<<endl;
				}
			}
			fp.close();
		}
};

queue q1;

user u1;


class stack{
	public:
	    llist l1;
	    void push(string *arr)
	    {
	    	l1.addnodelast(arr);
		}
		void pop()
		{
			l1.head = NULL;
		}
		void display()
		{
			l1.displaycar();
		}
		int isempty()
		{
			if(l1.head == NULL){
				return 1;
			}
		}
};

stack s1;

void readcsv(string *arr1,int j)
{
	int i;
	fstream fp1;
	string arr[8];
	fp1.open("pakwheels.csv",ios::in);
	for(i = 1; i<20;i++){
		for(j=0;j<8;j++){
			if(j == 7){
				getline(fp1,arr[j],'\n');
			}else{
				getline(fp1,arr[j],',');
			}
		}
		if(arr[0].find(arr1[0]) < 10 || arr[0].find(arr1[1]) < 10 || arr[0].find(arr1[2]) < 10 || arr[0].find(arr1[3]) < 10 || arr[0].find(arr1[4]) < 10 ){
			s1.push(arr);
		}
		if(arr1[0] == arr[2] || arr1[1] == arr[2] || arr1[2] == arr[2] || arr1[3] == arr[2] || arr1[4] == arr[2]){
			s1.push(arr);
		}
	}
	fp1.close();
}

void reading(int id)
{
    stringstream ss;
	string s,t;
	string arr[5];
	int i,j;
	fp.open("qfiling.txt",ios::in);
	if(!fp){
		return;
	}
	while(!fp.eof()){
		getline(fp,s,'\n');
		stringstream X(s);
		getline(X,t,',');
		ss << t;
		ss >> i;
		if(id == i){
			j=0;
			while(getline(X,arr[j],',')){
			    j++;
			}
			readcsv(arr,j);
		}
	}
	fp.close();			
}


int getid()
{
	int i=1;
	fp.open("users.txt",ios::in);
	while(fp.read((char*) &u1, sizeof(user))){
		i++;
	}
	fp.close();
	return i;
}

void print()
{
	fp.open("users.txt",ios::in);
	while(fp.read((char*) &u1, sizeof(user))){
		u1.show();
		cout<<"\n\n..........................................................\n";
	}
	fp.close();
}

int signup()
{
	system("cls");
	int n = getid();
	fp.open("users.txt",ios::out | ios ::app);
	u1.enter(n);
	fp.write((char*) &u1 , sizeof(user));
	fp.close();
	return n;
}

int passsearch(char arr[])
{
	int n = 0;
	fp.open("users.txt" , ios::in);
	while(fp.read((char*) &u1 , sizeof(u1))){
		if(strcmp(arr,u1.getpswrd()) == 0){
			n = 1;
		}else{
			n = 0;
		}
	}
	fp.close();
	return n;
}

int idsearch(int id)
{
	int n = 0;
	fp.open("users.txt" , ios::in);
	while(fp.read((char*) &u1 , sizeof(u1))){
		if(id == u1.getid()){
			n = 1;
		}else{
			n = 0;
		}
	}
	fp.close();
	return n;
}

void bubblesort1()
{
	node1 *temp1 = l1.head,*temp2,*temp3;
	int swap;
	while(temp1->next != NULL){
		swap = 0;
	    node1 *temp2 = l1.head;
		while(temp2->next->next != NULL){
			if(temp2 == l1.head && temp2->price > temp2->next->price){
				temp3 = temp2->next;
				temp2->next = temp2->next->next;
				temp3->next = temp2;
				l1.head = temp3;
			}
			if(temp2->next->price > temp2->next->next->price){
				temp3 = temp2->next;
				temp2->next = temp2->next->next;
				temp3->next = temp2->next->next;
				temp2->next->next = temp3;
				swap = 1;
			}
			temp2 = temp2->next;
		}
		if(swap == 0){
			break;
		}
		temp1 = temp1->next;
	}
}
void pricesort(int lb,int ub)
{
	if(l1.head == NULL){
		string arr[8];
	    int j;
		fp.open("pakwheels.csv",ios::in);
		while(!fp.eof()){
			for(j=0;j<8;j++){
				if(j == 7){
					getline(fp,arr[j],'\n');
				}else{
					getline(fp,arr[j],',');
				}
			}
			l1.addnode(arr);
		}
		fp.close();
		bubblesort1();
		l1.cropprice(lb,ub);
		system("cls");
		cout<<"\n\n----------------------CARS IN THE RANGE "<<lb<<" - "<<ub<<"--------------------------------\n\n";
		l1.displaycar();
	}else{
		bubblesort1();
		l1.cropprice(lb,ub);
		system("cls");
		cout<<"\n\n----------------------CARS IN THE RANGE "<<lb<<" - "<<ub<<"--------------------------------\n\n";
		l1.displaycar();
	}
}

void bubblesort2()
{
	node1 *temp1 = l1.head,*temp2,*temp3;
	int swap;
	while(temp1->next != NULL){
		swap = 0;
	    node1 *temp2 = l1.head;
		while(temp2->next->next != NULL){
			if(temp2 == l1.head && temp2->year > temp2->next->year){
				temp3 = temp2->next;
				temp2->next = temp2->next->next;
				temp3->next = temp2;
				l1.head = temp3;
			}
			if(temp2->next->year > temp2->next->next->year){
				temp3 = temp2->next;
				temp2->next = temp2->next->next;
				temp3->next = temp2->next->next;
				temp2->next->next = temp3;
				swap = 1;
			}
			temp2 = temp2->next;
		}
		if(swap == 0){
			break;
		}
		temp1 = temp1->next;
	}
}

void namesearch(string na)
{
	if(l1.head == NULL){
		int j,n;
	    string arr[8];
		fp.open("pakwheels.csv",ios::in);
		while(!fp.eof()){
			for(j=0;j<8;j++){
				if(j == 7){
					getline(fp,arr[j],'\n');
				}else{
					getline(fp,arr[j],',');
				}
			}
			n = arr[0].find(na);
			if(n > -1 && n < 100){
				l1.addnode(arr);
			}
		}
	    fp.close();
	    system("cls");
		cout<<"\n\n----------------------ALL "<<na<<" CARS --------------------------------\n\n";
		l1.displaycar();
	}else{
		l1.cropname(na);
		system("cls");
		cout<<"\n\n----------------------ALL "<<na<<" CARS --------------------------------\n\n";
		l1.displaycar();
    }
}

void modelsearch(string year)
{
	if(l1.head == NULL){
		int j,n;
		string arr[8];
		fp.open("pakwheels.csv",ios::in);
		while(!fp.eof()){
			for(j=0;j<8;j++){
				if(j == 7){
					getline(fp,arr[j],'\n');
				}else{
					getline(fp,arr[j],',');
				}
			}
			n = arr[2].find(year);
			if(n > -1 && n < 100){
				l1.addnode(arr);
			}
		}
	    fp.close();
	    system("cls");
		cout<<"\n\n----------------------ALL CARS OF YEAR "<<year<<" --------------------------------\n\n";
		l1.displaycar();
	}else{
		int n;
		stringstream ss;
	    ss << year;
	    ss >> n;
		bubblesort2();
		l1.yearcrop(n);
		system("cls");
		cout<<"\n\n----------------------ALL CARS OF YEAR "<<year<<" --------------------------------\n\n";
		l1.displaycar();
    }
}

void enginetype(string engt)
{
	if(l1.head == NULL){
		int j,n;
		string arr[8];
		fp.open("pakwheels.csv",ios::in);
		while(!fp.eof()){
			for(j=0;j<8;j++){
				if(j == 7){
					getline(fp,arr[j],'\n');
				}else{
					getline(fp,arr[j],',');
				}
			}
			n = arr[3].find(engt);
			if(n > -1 && n < 100){
				l1.addnode(arr);
			}
		}
	    fp.close();
	    system("cls");
	    cout<<"\n\n----------------------ALL CARS OF "<<engt<<" ENGINE --------------------------------\n\n";
		l1.displaycar();
		getch();
	}else{
		l1.cropengntype(engt);
		system("cls");
	    cout<<"\n\n----------------------ALL CARS OF "<<engt<<" ENGINE --------------------------------\n\n";
		l1.displaycar();
    }
}

void enginecc(string engc)
{
	if(l1.head == NULL){
		int j,n;
		string arr[8];
		fp.open("pakwheels.csv",ios::in);
		while(!fp.eof()){
			for(j=0;j<8;j++){
				if(j == 7){
					getline(fp,arr[j],'\n');
				}else{
					getline(fp,arr[j],',');
				}
			}
			n = arr[4].find(engc);
			if(n > -1 && n < 100){
				l1.addnode(arr);
			}
		}
	    fp.close();
	    system("cls");
	    cout<<"\n\n----------------------ALL CARS OF "<<engc<<" --------------------------------\n\n";
		l1.displaycar();
	}else{
		l1.enginecc(engc);
		system("cls");
	    cout<<"\n\n----------------------ALL CARS OF "<<engc<<" --------------------------------\n\n";
		l1.displaycar();
    }
}


void searchtrans(string trans)
{
	if(l1.head == NULL){
		int j,n;
		string arr[8];
		fp.open("pakwheels.csv",ios::in);
		while(!fp.eof()){
			for(j=0;j<8;j++){
				if(j == 7){
					getline(fp,arr[j],'\n');
				}else{
					getline(fp,arr[j],',');
				}
			}
			n = arr[5].find(trans);
			if(n > -1 && n < 100){
				l1.addnode(arr);
			}
		}
	    fp.close();
	    system("cls");
	    cout<<"\n\n----------------------ALL "<<trans<<" CARS --------------------------------\n\n";
		l1.displaycar();
		getch();
	}else{
		l1.croptrans(trans);
		system("cls");
	    cout<<"\n\n----------------------ALL "<<trans<<" CARS --------------------------------\n\n";
		l1.displaycar();
    }
}
void umaylike()
{
	fstream fp1;
	int y,j,i,ch;
	string arr[8];
	fp.open("pakwheels.csv", ios :: in);
	fp1.open("purhis.txt", ios::in);
	while(fp1.read((char*) &o1 ,sizeof(hisobj))){
		for(i=1;i<100;i++){
			for(j=0;j<8;j++){
				if(j == 7){
					getline(fp,arr[j],'\n');
				}else{
					getline(fp,arr[j],',');
				}
			}
			stringstream ss;
			ss << arr[2];
			ss >> y;
			if(o1.name == arr[0] || o1.engnt == arr[3] || o1.trans == arr[5] && (y > 2015 &&  y < 2019)){
				l2.addnode(arr);
			}
		}
	}
	fp.close();
	fp1.close();
	system("cls");
	l2.displaycar();
	cout<<"\n\n\t\t\t\t1 : EXIT";
	cin >>ch;
	if(ch == 1){
		return;
	}
}
void deletelist(node1** head_ref)
{
	node1* current = *head_ref;
    node1* next = NULL;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}

void purfiling(node1 *temp)
{
	char na[50],e[10],t[20];
	fp.open("purhis.txt", ios::out | ios::app);
	strcpy(na,temp->name.c_str());
	strcpy(e,temp->getengnt().c_str());
	strcpy(t,temp->gettrans().c_str());
	o1.input(temp->getyear(),na,e,t);
	fp.write((char*) &o1, sizeof(hisobj));
	fp.close();
}

void readhis()
{
	fp.open("purhis.txt", ios::in);
	while(fp.read((char*) &o1, sizeof(hisobj))){
		o1.show();
	}
	fp.close();
}

void purchase(int n)
{
	int i,ch;
	node1 *temp1 = l1.head;
	for(i = 1;i < n-1;i++){
		temp1 = temp1->next;
	}
	system("cls");
	l1.display(temp1->next);
	cout<<"\n\nDO YOU WANT TO PURCHASE THIS CAR\n";
	cout<<"\n1 : PURCHASE";
	cout<<"\n2 : LEAVE";
	cout<<"\nENTER YOUR CHOICE : ";
	cin >>ch;
	if(ch == 1){
		purfiling(temp1->next);
		temp1->next = temp1->next->next;
	}else{
		return;
	}
}


void searchcars(int id)
{
	system("cls");
	int ch,ub,lb,n;
	string name,engnt,engnc,trans,year;
	do{
		cout<<"\n\n1 : SEARCH BY NAME";
		cout<<"\n2 : SEARCH BY MODEL";
		cout<<"\n3 : SEARCH BY PRICE RANGE";
		cout<<"\n4 : SEARCH BY ENGINE TYPE";
		cout<<"\n5 : SEARCH BY ENGINE CC";
		cout<<"\n6 : SEARCH BY TRANSMISSION";
		cout<<"\n7 : PURCHASE A CAR";
		cout<<"\n8 : SEARCH NEW CARS";
		cout<<"\nENTER YOUR CHOICE : ";
		cin >>ch;
		switch(ch){
			case 1:
				cout<<"\n\nENTER NAME OF CAR : ";
				cin >>name;
				q1.enQueue(name);
				namesearch(name);
				break;
			case 2:
				cout<<"\n\nENTER MODEL YEAR : ";
				cin >>year;
				q1.enQueue(year);
				modelsearch(year);
				break;
			case 3:
				cout<<"\n\nENTER PRICE RANGE LOWER BOUND: ";
				cin >>lb;
				cout<<"\n\nENTER UPPER BOUND : ";
				cin >>ub;
				pricesort(lb,ub);
				break;
			case 4:
				cout<<"\n\nENTER ENGINE TYPE : ";
				cin >>engnt;
				q1.enQueue(engnt);
				enginetype(engnt);
				break;
			case 5:
				cout<<"\n\nENTER ENGINE CC : ";
				cin >>engnc;
				q1.enQueue(engnc);
				enginecc(engnc);
				break;
			case 6:
				cout<<"\n\nENTER TRANSMISSION : ";
				cin >>trans;
				q1.enQueue(trans);
				searchtrans(trans);
				break;
			case 7:
				do{
					cout<<"\n\nENTER CAR NUMBER FROM LIST : ";
				    cin >>n;
				    if(n < 0){
				    	cout<<"\nPLEASE ENTER VALID NUMBER\n";
					}
				purchase(n);
				}while(n < 0);
			case 8:
				q1.filing(id);
				deletelist(&l1.head);
				exit;
		}
	}while(ch != 8);
}


void idpage(int id)
{
	user u2;
	int ch;
	fp.open("users.txt", ios::in);
	while(fp.read((char*) &u2 , sizeof(u2))){
		if(id == u2.getid()){
			break;
		}
	}
	fp.close();
	do{
		system("cls");
		cout<<"\n.........WELCOME "<<u2.getname()<<" TO YOUR ACCOUNT...............\n";
		cout<<"\n\nCARS THAT ARE TRENDING...................\n";
		reading(1);
		s1.display();
		cout<<"\n1 : SEARCH CARS";
		cout<<"\n2 : CARS YOU MAY LIKE";
		cout<<"\n3 : LOGOUT\n";
		cin >>ch;
		if(ch == 1){
			searchcars(id);
		}else if(ch == 2){
			umaylike();
		}else if(ch == 3){
			cout<<"\n-------------------LOGGING OUT---------------------------\n";
			s1.pop();
			l2.deletelist();
			return;
		}
	}while(ch != 3);
	return;
}

void login1()
{
	int n,i = 0;
	char pass[50];
	system("cls");
	while( i != 1){
		cout<<"\n\nPLEASE ENTER YOUR ID NUMBER : ";
		cin >>n;
		int i = idsearch(n);
		if(i != 1){
			cout<<"\n\n\t\tINCORRECT ID\n\n";
			system("cls");
		}else{
			break;
		}
	}
	fflush(stdin);
	i = 0;
	while( i != 1){
		cout<<"ENTER PASSWORD : ";
		cin >>pass;
		i = passsearch(pass);
		if(i != 1){
			cout<<"\n\n\t\tINCORRECT PASSWORD\n\n";
		}else{
			break;
		}
    }
    idpage(n);
    return;
}

void user1()
{
	int ch,id;
	system("cls");
	cout<<"\n1 : LOGIN";
	cout<<"\n2 : SIGN UP";
	cout<<"\n3 : EXIT";
	cout<<"\nENTER YOUR CHOICE : ";
	cin >>ch;
	fflush(stdin);
	switch(ch){
		case 1:
			login1();
			break;
		case 2:
			id = signup();
			idpage(id);
			break;
		case 3:
			return;
	}
	return;
}

void inputdata()
{
	system("cls");
	string name,engnt,engnc,trans,color,asmb;
	long long int price;
	int year;
	fp.open("pakwheels.csv" , ios::out | ios::app);
	cout<<"\n\nENTER DATA PLEASE......\n";
	cout<<"ENTER NAME OF CAR : ";
	cin >>name;
	cout<<"ENTER PRICE : ";
	cin >>price;
	cout<<"ENTER YEAR : ";
	cin >>year;
	cout<<"ENTER ENGINE TYPE : ";
	cin >>engnt;
	cout<<"ENTER ENGINE CC : ";
	cin >>engnc;
	cout<<"ENTER TRANSMISSION : ";
	cin >>trans;
	cout<<"ENTER COLOR : ";
	cin >>color;
	cout<<"ENTER ASSEMBLY : ";
	cin >>asmb;
	fp << name <<", "<<price<<", "<<year<<", "<<engnc<<", "<<engnt<<", "<<trans<<", "<<color<<", "<<asmb<<"\n";
	fp.close();	
}

void admin1()
{
	int ch;
	system("cls");
	do{
		cout<<"\n\n1 : ENTER CAR'S DATA IN EXCEL SHEET";
		cout<<"\n2 : EXIT";
		cin >>ch;
		if(ch == 1){
			inputdata();
		}else{
			return;
		}
	}while(ch != 2);
}

void admin()
{
	int id = 12345,i;
	string password = "sah615451",p;
	system("cls");
	do{
		cout<<"\n\n\nENTER ID : ";
	    cin >>i;
	    if(id != i){
	    	cout<<"INCORRECT ID : ";
		}
	}while(id != i);
	do{
		cout<<"\n\n\nENTER PASSWORD : ";
	    cin >>p;
	    if(password != p){
	    	cout<<"INCORRECT PASSWORD : ";
		}
	}while(password != p);
	admin1();	
}

mainlayout()
{
	int ch = 0;
	do{
		system("cls");
		cout<<"\n\n\n.........................WELCOME...........................\n\n";
		cout<<"\n1 : USER";
		cout<<"\n2 : ADMIN";
		cout<<"\n3 : EXIT";
		cout<<"\nENTER YOUR CHOICE : ";
		cin >>ch;
		switch(ch){
			case 1:
				user1();
				break;
			case 2:
				admin();
				break;
			case 3:
				exit;
		}
	}while(ch != 3);
}

void get()
{
	int i,j;
	string arr[8];
	fp.open("pakwheels.csv",ios::in);
		for(i = 1;i<=10;i++){
			for(j=0;j<8;j++){
				if(j == 7){
					getline(fp,arr[j],'\n');
				}else{
					getline(fp,arr[j],',');
				}
			}
			l1.addnodelast(arr);
	}
	fp.close();
	l1.displaycar();
}


int main()
{
	mainlayout();
}
