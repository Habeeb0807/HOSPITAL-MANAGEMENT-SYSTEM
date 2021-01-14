#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<fstream.h>
#include<stdio.h>
#include<iomanip.h>

int userid;
void login();
class patient
 {
   public:
   int pid,age,diasp,sysp,temp;
   float phoneno,height,weight;
   char name[30],sex;
   void checkvitals();
   void getdetails()
     {
       cout<<"ID: ";
       cin>>pid;
       cout<<"\n";
       cout<<"Name: ";
       gets(name);
       cout<<"\n";
       cout<<"Phone No: ";
       cin>>phoneno;
       cout<<"\n";
       cout<<"Age: ";
       cin>>age;
       cout<<"\n";
       cout<<"Height: ";
       cin>>height;
       cout<<"\n";
       cout<<"Weight:";
       cin>>weight;
       cout<<"\n";
       cout<<"Sex: ";
       cin>>sex;
       cout<<"\n";
   }

   void display()
   {
     cout<<"Id: "<<pid<<"\n";
     cout<<"Name: "<<name<<"\n";
     cout<<"Age: "<<age<<"\n";
     cout<<"Height: "<<height<<"\n";
     cout<<"Weight: "<<weight<<"\n";
     cout<<"Sex: "<<sex<<"\n";
     cout<<"********************"<<endl;
   }
 }; patient p;





 void patient::checkvitals()
 {  int temp;
	cout<<"BP Check-"<<"\n";
    cout<<"Enter systolic pressure - ";
    cin>>sysp;
    cout<<endl;
    cout<<"Enter diastolic pressure - ";
    cin>>diasp;
    cout<<endl;
    if(sysp<=120 && diasp<=80)
     cout<<"Pressure - normal";
    else
     cout<<"Pressure - high"<<"\n";
    cout<<"\nTemp check\n";
    cout<<"Enter temp - ";
    cin>>temp;
    if(temp<=37)
    cout<<"\nNormal";
    else
    cout<<"\nHigh Temp";
 }





 void create()
  {
   int n,i;
   patient p;
   fstream fout;
   cout<<"Enter Number of Records To be Added: ";
   cin>>n;
 
   cout<<"\n";
   fout.open("patient.dat",ios::out|ios::binary);
     for(i=0;i<n;i++)
       {
	   p.getdetails();
	   fout.write((char*)&p,sizeof(p));
       }
       fout.close();
  }
  void search()
   {
     patient p;
     fstream fin;
     float no;
     fin.open("patient.dat",ios::in|ios::binary);
     cout<<"Enter contact number: ";
     cin>>no;
     cout<<"\n";
     while(!fin.eof())
      {
       fin.read((char*)&p,sizeof(p));
       if(p.phoneno==no)
       p.display();
      }
      fin.close();
     }
    void searchp()
   {
     patient p;
     fstream fin;

     fin.open("patient.dat",ios::in|ios::binary);

     while(!fin.eof())
      {
       fin.read((char*)&p,sizeof(p));

       p.display();
      }
      fin.close();
     }

     void append()
     {
      int k,i;
      patient p;
      fstream fout;
      fout.open("patient.dat",ios::app|ios::binary);
      cout<<"Number of patients to be entered: ";
      cin>>k;
      for(i=0;i<k;i++)
       {
	p.getdetails();
	fout.write((char*)&p,sizeof(p));
       }
       fout.close();
      }

   class medicine
    {
      public:
      int mid, stock;
      float cost;
      char disease[20];
      void input()
      {
	cout<<"ID: ";
	cin>>mid;
	cout<<"Stock: ";
	cin>>stock;
	cout<<"Disease: ";
	gets(disease);
	cout<<"Cost: ";
	cin>>cost;
      }
      void disp()
       {
	 cout<<"ID: "<<mid<<"\n";
	 cout<<"Stock: "<<stock<<"\n";
	 cout<<"cost:"<<cost;
	 cout<<"\n";
	 cout<<"Disease: "<<disease<<"\n";
	 cout<<"********"<<endl;
       }
      }; medicine m;
  void createm()
  {
   int n,i;
   medicine m;
   fstream fout;
   cout<<"Enter Number of Records To be Added: ";
   cin>>n;
   cout<<"\n";
   fout.open("medicine.dat",ios::out|ios::binary);
     for(i=0;i<n;i++)
       {
	   m.input();
	   fout.write((char*)&m,sizeof(m));
       }
       fout.close();
  }
      void appendmedicine()
       {
	 int k,i;
	 medicine m;
	 fstream fout;
	 fout.open("medicine.dat",ios::app|ios::binary);
	 cout<<"Enter number of medicines to be added: "<<"\n";
	 cin>>k;
	 cout<<"\n";
	 for(i=0;i<k;i++)
	  {

	    m.input();
	    fout.write((char*)&m,sizeof(m));
	  }
	  fout.close();
	 }

	 void medsearch()
	  {
	   medicine m;
	   int code;
	   cout<<"Enter medicine code: ";
	   cin>>code;

	   fstream fin;
	   fin.open("medicine.dat",ios::in|ios::binary);
	   while(!fin.eof())
	     {
	       fin.read((char*)&m,sizeof(m));
	       if(m.mid==code)
	      {
			if(m.stock>0)
	      { cout<<"AVAILABLE"<<endl;
			m.disp();
			break;
	      }
	       else
	       {
		cout<<"NOT IN STOCK";
	       break;
	       }
		  }
	     }

	     fin.close();
	     }


   class doctor
   {

      char name[30];
      char dept[20];
      int roomno;
      char qualf[30];
      char gender;
      public :
      int docid;
      void displaydoc();
      void getdetails()
      {
      cout<<"Enter the doctor id\n";
      cin>>docid;
      cout<<"Enter the name\n";
      cin>>name;
      cout<<"Enter the department\n";
      cin>>dept;
      cout<<"Enter the qualifications\n";
      cin>>qualf;
      cout<<"Enter the gender\n";
      cin>>gender;
      }
    }; doctor d;

     void doctor::displaydoc()
      {

      cout<<"Id: "<<docid<<"\n";
      cout<<"Name: "<<name<<"\n";
      cout<<"Gender :"<<gender<<"\n";
      cout<<"Department :"<<dept<<"\n";
      cout<<"Qualification :"<<qualf<<"\n";
      cout<<"********"<<endl;
      }



  void created()
  {
   int n,i;
   doctor d;
   fstream fout;
   cout<<"Enter Number of Records To be Added: ";
   cin>>n;
   cout<<"\n";

   fout.open("doctor.dat",ios::out|ios::binary);
     for(i=0;i<n;i++)
       {
	   d.getdetails();
	   fout.write((char*)&d,sizeof(d));
       }
       fout.close();
  }
  void searchd()
   {
     doctor d ;
     fstream fin;
     fin.open("doctor.dat",ios::in|ios::binary);

     cout<<"\n";

      while(!fin.eof())
      {
       fin.read((char*)&d,sizeof(d));
       d.displaydoc();
      }
      fin.close();
     }


  //Checks if username and passwords match. Returns 1,2,3 for doctor,pharmacist,receptionist respectively.
  //Returns 0 if no match
  int checkPassword( char user[20],char pass[20])
   {
    char uname[20];
    strcpy(uname,"doctor");
    if (strcmpi(user,uname) == 0) {
      if (strcmpi(pass,"docpass")==0)
	return 1;
    }
    strcpy(uname,"pharmacist");
    if (strcmpi(user,uname) == 0)
     {
      if (strcmpi(pass,"pharmpass")==0)
	return 2;
    }
    strcpy(uname,"receptionist");
    if (strcmpi(user,uname) == 0)
    {
      if (strcmpi(pass,"recpass")==0){
	cout<<"Correct password!";
	return 3;
      }
    }
    return 0;
  }


  //Takes username and input as parameters and returns 0/1/2/3 based on the result from checkPassword


  void pharmacistMenu()
   { int ch_p;
     cout<<"Hello Pharmacist"<<"\n";
     while(ch_p != 4)
     {
     getch();
     clrscr();
     cout<<"Enter -"<<"\n";
     cout<<"1. To view patient details"<<"\n";
     cout<<"2.To add medicine"<<"\n";
     cout<<"3.To search medicine by code"<<"\n";
     cout<<"4. Logout\n";
     cout<<"5.exit\n";
     cin>>ch_p;
	 if(ch_p==1)
	   search();
	 else if(ch_p==2)
		appendmedicine();
	       else if(ch_p==3)
		     medsearch();
		    else if(ch_p == 4)
			   login();
			  else if(ch_p==5)
			  exit(0);
	cout<<"Press any button to go back to menu\n";
	}
  }

  void receptionistMenu()
  {
   int ch_r;
   cout<<"Hello receptionist"<<"\n";
   while(ch_r != 5){
	getch();
	clrscr();
   cout<<"Enter  - "<<"\n";
   cout<<"1: To check patient list"<<"\n";
   cout<<"2: To add a new patient"<<"\n";
   cout<<"3: To view doctors list"<<"\n";
   cout<<"4: To search for a patient by contact number"<<"\n";
   cout<<"5. Logout\n";
   cout<<"6.Exit\n";
   cin>>ch_r;
   if(ch_r==1)
   searchp();
   else if(ch_r==2)
    append();
	 else if(ch_r==3)
	    searchd();
	      else if( ch_r==4)
		     search();
		   else if(ch_r == 5)
			 login();
			 else if(ch_r==6)
				   exit(0);
  cout<<"\nPress any button";
}
}




  void doctorMenu()
  {  patient p;
    int ch_d;
    cout<<"Hello Doctor! Press any button\n";
    while(ch_d != 3)
    {
    getch();
    clrscr();
    cout<<"Enter - "<<"\n";
    cout<<"1 - Patient details"<<"\n";
    cout<<"2- Check vitals"<<"\n";
    cout<<"3- Logout\n";
    cout<<"4-Exit\n";
    cin>>ch_d;

	if(ch_d==1)
		searchp();

		else if(ch_d==2)
		{
		     int pid;
		      cout<<"Enter patient ID";
		      cin>>pid;

     fstream fin;
     float no;
     fin.open("patient.dat",ios::in|ios::binary);

     while(!fin.eof())
      {
       fin.read((char*)&p,sizeof(p));
       if(p.pid==pid)
       {
	 p.checkvitals();
	   break;
       }
      }
      fin.close();
	}
	else if(ch_d == 3)
	login();
	      else if(ch_d==4)
	      exit(0);
	cout<<"\nPress any button to go back to menu\n";
}
}

	void login()
  {
    char pass[20],user[20];
    int result;
    clrscr();
    cout<<"Username : ";
    gets(user);
    cout<<"\nPassword : ";
    gets(pass);
    userid = checkPassword(user,pass);
    switch(userid){
     case 1:
       doctorMenu();
       break;
     case 2:
       pharmacistMenu();
       break;
     case 3:
       receptionistMenu();
       break;
     default:
       cout<<"\nWrong Username and/or password. Press any key to try again";
       getch();
       login();
       break;
    }
  }
  void main()
  {
    clrscr();
    int choice;
    patient p;
    medicine m;
    doctor d;
    /*create();
    created();
    createm();*/
    cout<<"\t       __      __        __\n";
    cout<<"\t      /  \\    /  \\ ____ |  | ____  ____    _____   ____ \n";
    cout<<"\t      \\   \\/\\/   // __ \\|  |/ ___\\/  _ \\  /     \\ / __ \\\n";
    cout<<"\t       \\        /|  ___/|  |  \\__(  <_> )|  Y Y  \|  ___/\n";
    cout<<"\t        \\__/\\__/  \\____\\|__|\\_____>____/ |__|_|__|\\____\\\n";
    cout<<"\t   _____         ________                        __      _\n";
    cout<<"_________________________________________________________________";
    cout<<"                       HOSPITAL MANAGEMENT SYSTEM          ";
    cout<<"***********************************************************";
    cout<<"Press any button to login..";
    getch();
    login();
  }


