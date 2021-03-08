#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<fstream.h>
#include<stdio.h>
#include<iomanip.h>
class CBSE
   {
   int rollno;
   char name[20];
   int a_marks,b_marks,c_marks;
   float per;
   char grade;
   int std;
 public:
   void calc()
   {
     per=(a_marks+b_marks+c_marks)/3;
     if (per>=90)
       grade='A';
     else if (per>=80 && per<90)
       grade='B';
	else if (per>=70 && per<80)
       grade='C';
	else if (per>=60 && per<70)
       grade='D';
	else if (per>=50 && per<60)
       grade='E';
       else
       grade='F';
   }
   void getdata();
   void tabular();
   void showdata();
   int roll()
     {
     return rollno;
     }
   };


void CBSE::getdata()
{
   clrscr();
  cout<<"\n\t STUDENT DETAILS";
  cout<<"\n\n\nEnter roll number of student  ";
  cin>>rollno;
  cout<<"\nEnter name of student  ";
  gets(name);
  cout<<"\nEnter marks in Maths out of 100  ";
  cin>>a_marks;
	   while(a_marks>100)
	{
	cout<<"\nENTER VALID INPUT";
	cout<<"\nEnter Again  ";
	cin>>a_marks;
	}
   cout<<"\nEnter marks in Physics out of 100  ";
  cin>>b_marks;
	  while(b_marks>100)
	{
	cout<<"\nENTER VALID INPUT";
	cout<<"\nEnter Again  ";
	cin>>b_marks;
	}
   cout<<"\nEnter marks in Chemistry out of 100  ";
  cin>>c_marks;
	   while(c_marks>100)
	{
	cout<<"ENTER VALID INPUT";
	cout<<"\nEnter Again  ";
	cin>>c_marks;
	}
   calc();
}
void CBSE::showdata()
{
  calc();
  cout<<"\n\nThe Student record you asked for is";
  cout<<"\n\n\n\n\nRoll number of the student:"<<rollno;
  cout<<"\n\n\tName of student  "<<name;
  cout<<"\n\n\tMarks in Maths  "<<a_marks;
  cout<<"\n\n\tMarks in Phyics  "<<b_marks;
  cout<<"\n\n\tMarks in Chemistry  "<<c_marks;
  cout<<"\n\n\tPercentage of the student is:  "<<per;
  cout<<"\n\n\tGrade of student is:  "<<grade<<endl<<endl;
}
void CBSE::tabular()
{
cout<<rollno<<setw(15)<<name<<setw(9)<<a_marks<<setw(6)<<b_marks<<setw(7)<<c_marks<<setw(6)<<setw(9)<<setprecision(3)<<per<<"\t"<<"          "<<grade<<"\n";
}
fstream fp;
CBSE st;

void write_stud()
{
clrscr();
fp.open("student.dat",ios::out|ios::app);
st.getdata();
fp.write((char*)&st,sizeof(st));
fp.close();
cout<<"\n\nStudent Record has been created";
getch();
};


void display_rec()
{
clrscr();
cout<<"Displaying all records";
fp.open("student.dat",ios::in);
   while(fp.read((char*)&st,sizeof(st)))
   {
   st.showdata();
   cout<<"\n";
   }
fp.close();
}
void display_spec(int n)
{
int flag=0;
fp.open("student.dat",ios::in);
	  while(fp.read((char*)&st,sizeof(st)))
	  {
		    if(st.roll()==n)
		    {
		    clrscr();
		    st.showdata();
		    flag=1;
		    }
	  }
fp.close();
  if(flag==0)
  {
  cout<<"\n\nRecord Does Not Exist";
  }
}

void del_stud()
{
int n;
clrscr();
cout<<"\n\nPlease enter the roll number to be deleted : ";
cin>>n;
fp.open("student.dat",ios::in|ios::out);
fstream fp2;
fp2.open("temp.dat",ios::out);
fp.seekg(0,ios::beg);
  while(fp.read((char*)&st,sizeof(st)))
   {
      if(st.roll()!=n)
	{
	fp2.write((char*)&st,sizeof(st));
	}
   }
cout<<"\n\nRecord for roll number "<<n<<" has been deleted";
fp2.close();
fp.close();
remove("student.dat");
rename("temp.dat","student.dat");
getch();
}

void st_result()
{
clrscr();
fp.open("student.dat",ios::in);
cout<<"\n\n\t\t\t\tRESULT\n\n";
cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
cout<<"R.no.      Name        A      B      C      Perc.     Grade\n";
cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
      while(fp.read((char*)&st,sizeof(st)))
      {
      st.tabular();
      }
fp.close();
}

void modify()
{
int rno, found=0;
clrscr();
cout<<"\n\nEnter the Roll Number of the student to modify the record : ";
cin>>rno;
fp.open("student.dat", ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(st)))
      {
      if(st.roll()==rno)
	 {
	 st.showdata();
	 cout<<"\n\nEnter New Details";
	 st.getdata();
	 int pos=-1*sizeof(st);
	 fp.seekp(pos,ios::cur);
	 fp.write((char*)&st,sizeof(st));
	 cout<<"\n\nRecord has been updated" ;
	 found=1;
	 }
       }
fp.close();
     if(found==0)
     cout<<"\nRECORD NOT FOUND\n";
getch();
}




void main()
{
int ch;
clrscr();
gotoxy(40,1);
cout<<"WELCOME";
gotoxy(42,3);
cout<<"TO";
gotoxy(40,5);
cout<<"Student";
gotoxy(35,7);
cout<<"Result Management";
gotoxy(40,9);
cout<<"System";
gotoxy(50,20);
cout<<"PLEASE PRESS ENTER TO CONTINUE";
getch();
do
   {
   clrscr();
   cout<<"\n\n\tMain Menu";
   cout<<"\n\n\t1.Create Student Record";
   cout<<"\n\n\t2.Display Class Result";
   cout<<"\n\n\t3.Display Specific Student record";
   cout<<"\n\n\t4.Modify Existing Record";
   cout<<"\n\n\t5.Delete Student Record";
   cout<<"\n\n\t6.Exit";
   cout<<"\n\n\tPlease Select your option   ";
   cin>>ch;

   switch(ch)
   {
   case 1: write_stud();
	     getch();
	    break;
   case 2: st_result();
	    getch();
	    break;
   case 3: int num;
	  clrscr();
	  cout<<"\n\n\tPlease Enter The Roll Number:  ";
	  cin>>num;
	  display_spec(num);
	  getch();
	  break;
  case 4: modify();
	  break;

  case 5:del_stud();
	  getch();
	  break;

  case 6: break ;
   }
}while(ch!=6);
getch();
}
