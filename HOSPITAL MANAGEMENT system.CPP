#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
struct patient
{
    long long mob_no;
	string firstname;
	string lastname;
	int age;
	char blood_grp[6];
	char gender;
    patient*next;
};
class hospital_management
{
	patient *front,*rear;
	int fee,med_fee;
	public:
    hospital_management	() //constructor
	{
		front=NULL;
		rear=NULL;
	}
    patient input();
    void insertatend();
    void insertatbeg();
    void getpatientout();
    void displaypatients();
    //int search(int);
    char deptname[50];
    void total_bill();
   friend void total_exp(hospital_management);
};

int convertnumber()
{
   char b[20];
   cin.getline(b,sizeof(b));
   return atoi(b);
}

void deptmenu (hospital_management * q)
{
    int choice = 0, success;
    patient p;
    while (choice != 5)
	{
    system("cls");
	cout<<"\n\n\tWelcome To depts : " << q->deptname;
	cout<<"\n\t\t[1] Add normal patient\n";
	cout<<"\t\t[2] Add critically ill patient\n";
	cout<<"\t\t[3] Take patient to Doctor\n";
	cout<<"\t\t[4] Display list\n";
	cout<<"\t\t[5] Change depts or exit\n";
	cout<<"\n\tPlease enter your choice : ";
	choice=convertnumber();

    switch (choice)
	{
	  case 1:	q->insertatend();
				cout << "\n\tPress any key";
	    		getch();
	 			break;

      case 2:	q->insertatbeg();
	    		cout << "\n\tPress any key";
	    		getch();
				break;

      case 3:	q->getpatientout();
	 			cout<<"\n\tPress any key";
     			getch();
	      		break;

      case 4:	system("cls");
	 			q->displaypatients();
	 			cout<<"\n\tPress any key";
	 			getch();
				break;
	 }
    }
}
void output(patient *p)
{
	char arr1[20],arr2[20],arr3[3],arr4[20];
	char arr5[20],arr6[20];
	
	ifstream obj("hospital.txt");
	obj.getline(arr1,20);
    obj.getline(arr2,20);
	obj.getline(arr3,20);
	obj.getline(arr4,20);
	obj.getline(arr5,20);
	obj.getline(arr6,20);
	cout<<"\n\nPatient data:";
	cout<<"\n\nFirst Name       : "<<arr1;
	cout<<"\nLast Name          : "<<arr2;
	cout<<"\nGender             : "<<arr3;
	cout<<"\nAge                : "<<arr5;
	cout<<"\nBlood Group        : "<<arr4;
	cout<<"\nMobile Number      : "<<arr6;
	obj.close();	
}

void hospital_management:: insertatend()
{
     patient*p=new patient();
     *p=input();
     if(p->mob_no==0)
     return;

     if(front==NULL)
     {
     	front=p;
        rear=p;
        p->next=NULL;
     }
     else
     {
     	p->next=NULL;
        rear->next=p;
        rear=p;
     }
     system("cls");
     cout << "\n\tPatient added:";
     output(p);
}

void hospital_management :: insertatbeg()
{
     patient*p=new patient();
     *p=input();
     if(p->mob_no==0)
     return;

     if(front==NULL)

     {
         front=p;
         rear=p;
         p->next=NULL;
     }
     else
     {
        p->next=front;
        front=p;
     }
     system("cls");
     cout << "\n\tPatient added:";
     output(p);
}

void hospital_management :: getpatientout()
{
	 system("cls");
     if(front==NULL)
     {
     	cout<<"\n\tNo Patient to operate";
     }
     else
     {
     	patient*p=new patient();
     	p=front;
     	front=front->next;
 	    cout << "\n\tPatient to operate:";
        output(p);
 	 }
}

void hospital_management:: displaypatients()
{
     if(front==NULL)
     {
     	cout<<"\n\tNo patient";
 	 }
     patient*p=new patient;
     p=front;
     while(p!=NULL)
     {
        cout<<"\nPatient data:";
		cout<<"\nFirst Name       : "<<p->firstname;
		cout<<"\nLast Name        : "<<p->lastname;
		cout<<"\nGender           : "<<p->gender;
        cout<<"\nAge              : "<<p->age;
        cout<<"\nBlood Group      : "<<p->blood_grp;
		cout<<"\nMobile Number    : "<<p->mob_no;
		cout<<"\n************\n";
        p=p->next;
     }
     cout<<"\n";
}

patient hospital_management :: input()
{
    int flag=0;
   patient *p=new patient();
   cout << "\n\tPlease enter data for patient\n";
   cout<<"\n\tFirst name     : ";
   getline(cin,p->firstname);
   cout << "\tLast name      : ";
   getline(cin,p->lastname);
   again :
   cout << "\tBlood Group    : ";
   cin>>p->blood_grp;
   if((strcmp(p->blood_grp,"A+")==0)||(strcmp(p->blood_grp,"a+")==0)||(strcmp(p->blood_grp,"A-")==0)||(strcmp(p->blood_grp,"a-")==0)||
      (strcmp(p->blood_grp,"B+")==0)||(strcmp(p->blood_grp,"b+")==0)||(strcmp(p->blood_grp,"B-")==0)||(strcmp(p->blood_grp,"b-")==0)||
      (strcmp(p->blood_grp,"O+")==0)||(strcmp(p->blood_grp,"o+")==0)||(strcmp(p->blood_grp,"O-")==0)||(strcmp(p->blood_grp,"o-")==0)||
      (strcmp(p->blood_grp,"AB+")==0)||(strcmp(p->blood_grp,"ab+")==0)||(strcmp(p->blood_grp,"AB-")==0)||(strcmp(p->blood_grp,"ab-")==0))
             flag=1;
    if(flag==0)
    {
        cout<<"\nWrong Entry...Enter a valid Blood Group..Try Again..";
        goto again;

    }
   cout<<"\tGender           : (m/f)";
   cin>>p->gender;
   cout<<"\tAge              : ";
   cin>>p->age;
   cout<<"\tMobile number    : ";
   cin>>p->mob_no;
   ofstream myfile("hospital.txt");
   myfile<<"first name: "<<p->firstname<<endl<<"last name: "<<p->lastname<<endl<<"blood group: "<<p->blood_grp<<endl<<"gender: "<<p->gender<<endl<<"age: "<<p->age<<endl<<"mobile_no.: "<<p->mob_no<<endl;
   return *p;
}

void hospital_management::total_bill()
{
	cout<<"docter fees: ";
	cin>>fee;
	cout<<"medicine bill: ";
    cin>>med_fee;
    ofstream myfile("hospital.txt",ios::app);
    myfile<<"docter fees: "<<fee<<endl<<"medicine bill: "<<med_fee<<endl;
    myfile.close();    
}
void total_exp(hospital_management obj)
{
 int total;
 total=obj.fee+obj.med_fee;
 cout<<"the total expenditure:";
 cout<<total;
 ofstream myfile("hospital.txt",ios::app);
 myfile<<"the total expenditure:"<<total<<endl;
 myfile.close();
 	
}
int main ()
{
    int i, choice = 0;
	hospital_management depts[4];
    hospital_management p1;
    
	while(choice!=5)
	{
		strcpy(depts[0].deptname,"General Clinic\n");
		strcpy(depts[1].deptname,"Heart Clinic\n");
		strcpy(depts[2].deptname,"Lung Clinic\n");
		strcpy(depts[3].deptname,"Plastic Surgery\n");
		system("cls");
		cout<<"\n\t>>>>>>>>>>>>>>>>>>>>>>>>>>";
		cout<<"\n\tHOSPITAL MANAGEMENT SYSTEM\t";
		cout<<"\n\t<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
		for (i = 0; i < 4; i++)
		{
			cout<<"\t"<<(i+1)<<": "<<depts[i].deptname;
		}
		cout<<"\t5: Exit";
		cout<<"\n\n\tPlease enter your choice : ";
		choice=convertnumber();
		if(choice>=1 && choice<=4)
		{
			deptmenu(&depts[choice-1]);
		}

	}
	p1.total_bill();
	total_exp(p1);
	if(choice==5)
	cout<<"\n\t\tThank you! \n"<<endl;
	cout<<"file write operation is perfomed succesfully"<<endl;	
	exit(0);
}
