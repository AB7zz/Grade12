#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<dos.h>
#include<process.h>
struct Date
{
	int day;
	int month;
	int year;
};
class Officer
{
	char name[30];
	char sex;
	char officer_code[10];
	char rank[20];
	int no_of_service_years;
	Date date_of_birth;
	int no_of_medals;
	float salary;
	char dept_name[15];
public:
	void enter_details();
	void display_details();
	void modify_details();
	char * ret_name() { return name; }
	char ret_sex() { return sex; }
	char * ret_code() { return officer_code; }
	char * ret_rank() { return rank; }
	int ret_serv_yrs() { return no_of_service_years; }
	int ret_medals() { return no_of_medals; }
	float ret_sal() { return salary; }
	char * ret_dept() { return dept_name; }
};
void Officer::enter_details()
{
	clrscr();
	cout<<"\nEnter the Officer's details : ";
	cout<<"\nEnter the Officer's Name : ";
	gets(name);
	int t;
	do
	{
		cout<<"\nEnter the sex of the officer : (M/F) ";
		cin>>sex;
		if(sex=='M' ^ sex=='F' ^ sex=='f' ^ sex=='m')
		{
			t=1;
		}
		else
		{
			cout<<"\nPlease re enter a valid gender!!";
			t=0;
		}
	}
	while(t==0);
	cout<<"\nEnter the officer's employment code : ";
	cin>>officer_code;
	cout<<"\nEnter the rank of the officer : ";
	gets(rank);
	do
	{
		cout<<"\nEnter the no of service years : ";
		cin>>no_of_service_years;
		if(no_of_service_years>0 && no_of_service_years<100)
		{
			t=1;
		}
		else
		{
			cout<<"\nPlease enter a valid amount!";
			t=0;
		}
	}
	while(t==0);
	cout<<"\nEnter the date of birth of the officer : (For eg, 12 2 1985) ";
	cin>>date_of_birth.day>>date_of_birth.month>>date_of_birth.year;
	cout<<"\nEnter the number of medals earned by the officer : ";
	cin>>no_of_medals;
	cout<<"\nEnter the salary of the officer : ";
	cin>>salary;
	do
	{
		t=1;
		cout<<"\nEnter the department name of the officer (Army,Navy,Air Force Or Marine Corps) : ";
		gets(dept_name);
		if(strcmpi(dept_name,"Air Force")!=0 && strcmpi(dept_name,"Army")!=0 && strcmpi(dept_name,"Navy")!=0 && strcmpi(dept_name,"Marine Corps")!=0)
		{
			cout<<"\nPlease enter a valid department name!";
			t=0;
		}
	}
	while(t==0);
	getch();
}
void Officer::display_details()
{
	cout<<"\nName : "<<name;
	cout<<"\nSex : "<<sex;
	cout<<"\nCode : "<<officer_code;
	cout<<"\nRank : "<<rank;
	cout<<"\nNo of Service Years : "<<no_of_service_years;
	cout<<"\nDate of Birth : "<<date_of_birth.day<<"-"<<date_of_birth.month<<"-"<<date_of_birth.year;
	cout<<"\nNo of Medals : "<<no_of_medals;
	cout<<"\nSalary : "<<salary;
	cout<<"\nDepartment : "<<dept_name;
	cout<<endl;
	getch();
}
void Officer::modify_details()
{
	clrscr();
	int ch;
	char yn;
	do
	{
		cout<<"\nModify Menu for Officers";
		cout<<"\nSelect an option from below of what you would like to modify from the record : ";
		cout<<"\n1.Name";
		cout<<"\n2.Sex";
		cout<<"\n3.Code";
		cout<<"\n4.Rank";
		cout<<"\n5.No of Service Years";
		cout<<"\n6.Date of Birth";
		cout<<"\n7.No of Medals";
		cout<<"\n8.Salary";
		cout<<"\n9.Department";
		cout<<"\n10.Exit";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:	cout<<"\nEnter the new name of the Officer : ";
				gets(name);
				break;
			case 2: int t;
				do
				{
					t=1;
					cout<<"\nEnter the sex of the officer : (M/F) ";
					cin>>sex;
					if(sex=='M' ^ sex=='F' ^ sex=='f' ^ sex=='m')
					{
						t=1;
					}
					else
					{
						cout<<"\nPlease re enter a valid gender!!";
						t=0;
					}
				}
				while(t==0);
				break;
			case 3:	cout<<"\nEnter the new code of the Officer : ";
				cin>>officer_code;
				break;
			case 4:	cout<<"\nEnter the new rank of the Officer : ";
				gets(rank);
				break;
			case 5:	do
				{
					cout<<"\nEnter the no of service years : ";
					cin>>no_of_service_years;
					if(no_of_service_years>0 && no_of_service_years<100)
					{
						t=1;
					}
					else
					{
						cout<<"\nPlease enter a valid amount!";
						t=0;
					}
				}
				while(t==0);
				break;
			case 6:	cout<<"\nEnter the new date of birth of the Officer : ";
				cin>>date_of_birth.day>>date_of_birth.month>>date_of_birth.year;
				break;
			case 7:	cout<<"\nEnter the new number of medals of the Officer : ";
				cin>>no_of_medals;
				break;
			case 8:	cout<<"\nEnter the new salary of the Officer : ";
				cin>>salary;
				break;
			case 9:	do
				{
					t=1;
					cout<<"\nEnter the department name of the officer (Army,Navy,Air Force Or Marine Corps) : ";
					gets(dept_name);
					if(strcmpi(dept_name,"Air Force")!=0 && strcmpi(dept_name,"Army")!=0 && strcmpi(dept_name,"Navy")!=0 && strcmpi(dept_name,"Marine Corps")!=0)
					{
						cout<<"\nPlease enter a valid department name!";
						t=0;
					}
				}
				while(t==0);
				break;
			case 10:cout<<"\nExiting the Modify Menu!";
				break;
			default:cout<<"\nInvalid choice! Please re enter!";
		}
		clrscr();
	}
	while(ch!=10);
	getch();
}
void AddToOfficerFile()
{
	clrscr();
	fstream F;
	char ch='y';
	F.open("Military.dat",ios::binary|ios::app|ios::out);
	Officer O;
	while(ch=='y'|| ch=='Y')
	{
		cout<<"\nEnter the details of the new record you would like to add : ";
		O.enter_details();
		F.write((char *) &O,sizeof(O));
		cout<<"\nWould you like to enter another record? (Y/N) : ";
		cin>>ch;
	}
	F.close();
	clrscr();
}
void searchbyoffname()
{
	fstream F;
	F.open("Military.dat",ios::binary|ios::in);
	Officer O;
	char off[25];
	int found=0;
	cout<<"\nEnter the name of the Officer to search for : ";
	gets(off);
	while(F.read((char *) &O,sizeof(O)))
	{
		if(strcmpi(O.ret_name(),off)==0)
		{
			O.display_details();
			found=1;
		}
	}
	if(!found)
		cout<<"Sorry! Officer's record not found in the file...\n";
	F.close();
}
void searchbycode()
{
	fstream F;
	F.open("Military.dat",ios::binary|ios::in);
	Officer O;
	char off[10];
	int found=0;
	cout<<"\nEnter the code of the Officer to search for : ";
	cin>>off;
	while(F.read((char *) &O,sizeof(O)))
	{
		if(strcmpi(O.ret_code(),off)==0)
		{
			O.display_details();
			found=1;
		}
	}
	if(!found)
		cout<<"Sorry! officer's record not found in the file...\n";
	F.close();
}
void searchbysex()
{
	fstream F;
	F.open("Military.dat",ios::binary|ios::in);
	Officer O;
	char off;
	int found=0;
	cout<<"\nEnter the sex of the Officers to search for : ";
	cin>>off;
	while(F.read((char *) &O,sizeof(O)))
	{
		if(O.ret_sex()==off)
		{
			O.display_details();
			found=1;
		}
	}
	if(!found)
		cout<<"Sorry! officer's record not found in the file...\n";
	F.close();
}
void searchbyrank()
{
	fstream F;
	F.open("Military.dat",ios::binary|ios::in);
	Officer O;
	char off[20];
	int found=0;
	cout<<"\nEnter the rank of the Officers to search for : ";
	gets(off);
	while(F.read((char *) &O,sizeof(O)))
	{
		if(strcmpi(O.ret_rank(),off)==0)
		{
			O.display_details();
			found=1;
		}
	}
	if(!found)
		cout<<"Sorry! officer's record not found in the file...\n";
	F.close();
}
void searchbydept()
{
	fstream F;
	F.open("Military.dat",ios::binary|ios::in);
	Officer O;
	char off[15];
	int found=0;
	cout<<"\nEnter the department of the Officers to search for : ";
	gets(off);
	while(F.read((char *) &O,sizeof(O)))
	{
		if(strcmpi(O.ret_dept(),off)==0)
		{
			O.display_details();
			found=1;
		}
	}
	if(!found)
		cout<<"Sorry! officer's record not found...\n";
	F.close();
}
void searchbyservyrs()
{
	fstream F;
	F.open("Military.dat",ios::binary|ios::in);
	Officer O;
	int t, found=0;
	int off1,off2;
	do
	{
		t=1;
		cout<<"\nEnter the range of no of service years of the Officers to search for : ";
		cout<<"\nEnter the upper limit : ";
		cin>>off1;
		cout<<"\nEnter the lower limit : ";
		cin>>off2;
		if(off1<off2)
		{
			cout<<"\nInvalid range! Please re enter!";
			t=0;
		}
	}
	while(t==0);
	while(F.read((char *) &O,sizeof(O)))
	{
		if(O.ret_serv_yrs()>off2  && O.ret_serv_yrs()<off1)
		{
			O.display_details();
			found=1;
		}
	}
	if(!found)
		cout<<"Sorry! officer's record not found...\n";
	F.close();
}
void searchbysal()
{
	fstream F;
	F.open("Military.dat",ios::binary|ios::in);
	Officer O;
	int t, found=0;
	float off1,off2;
	do
	{
		t=1;
		cout<<"\nEnter the range of salary of the Officers you would like to search for : ";
		cout<<"\nEnter the upper limit : ";
		cin>>off1;
		cout<<"\nEnter the lower limit : ";
		cin>>off2;
		if(off1<off2)
		{
			cout<<"\nInvalid range! Please re enter!";
			t=0;
		}
	}
	while(t==0);
	while(F.read((char *) &O,sizeof(O)))
	{
		if(O.ret_sal()>off2 && O.ret_sal()<off1)
		{
			O.display_details();
			found=1;
		}
	}
	if(!found)
		cout<<"Sorry! officer's record not found...\n";
	F.close();
}
void searchbymedals()
{
	fstream F;
	F.open("Military.dat",ios::binary|ios::in);
	Officer O;
	int t, found=0;
	float off1,off2;
	do
	{
		t=1;
		cout<<"\nEnter the range of no of medals of the Officers you would like to search for : ";
		cout<<"\nEnter the upper limit : ";
		cin>>off1;
		cout<<"\nEnter the lower limit : ";
		cin>>off2;
		if(off1<off2)
		{
			cout<<"\nInvalid range! Please re enter!";
			t=0;
		}
	}
	while(t==0);
	while(F.read((char *) &O,sizeof(O)))
	{
		if(O.ret_medals()>off2 && O.ret_medals()<off1)
		{
			O.display_details();
			found=1;
		}
	}
	if(!found)
		cout<<"Sorry! officer's record not found...\n";
	F.close();
}
void DisplayOfficerFile()
{
	fstream F;
	F.open("Military.dat",ios::binary|ios::in);
	Officer O;
	while(F.read((char *) &O,sizeof(O)))
	{
		O.display_details();
	}
	F.close();
}
void SearchOfficerFile()
{
	clrscr();
	fstream F;
	int ch;
	do
	{
		cout<<"\nSearch and Display Menu";
		cout<<"\n1.Search by name";
		cout<<"\n2.Search by code";
		cout<<"\n3.Search by sex";
		cout<<"\n4.Search by rank";
		cout<<"\n5.Search by department";
		cout<<"\n6.Search by no of service years";
		cout<<"\n7.Search by salary range";
		cout<<"\n8.Search by no of medals";
		cout<<"\n9.Display all records stored";
		cout<<"\n10.Exit";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:	searchbyoffname();
				break;
			case 2:	searchbycode();
				break;
			case 3:	searchbysex();
				break;
			case 4:	searchbyrank();
				break;
			case 5: searchbydept();
				break;
			case 6: searchbyservyrs();
				break;
			case 7:	searchbysal();
				break;
			case 8:	searchbymedals();
				break;
			case 9:	DisplayOfficerFile();
				break;
			case 10:cout<<"\nExiting the search and display menu!";
				break;
			default:cout<<"\nInvalid choice! Please re enter!";
		}
		clrscr();
	}
	while(ch!=10);
	getch();
}
void ModifyOfficerFile()
{
	clrscr();
	fstream F1,F2;
	F1.open("Military.dat",ios::binary|ios::in);
	F2.open("Temp.dat",ios::binary|ios::out);
	Officer O;
	char off[25];
	int found=0;
	cout<<"\nEnter the name of the Officer whose record is to be modified : ";
	gets(off);
	while(F1.read((char *) &O,sizeof(O)))
	{
		if(strcmpi(O.ret_name(),off)!=0)
		{
			F2.write((char *) &O,sizeof(O));
		}
		else
		{
			O.modify_details();
			F2.write((char *) &O,sizeof(O));
			cout<<"\nThe record has been successfully modified";
			found=1;
		}
	}
	if(!found)
	cout<<"\nThe record could not be located!";
	getch();
	clrscr();
	F1.close();
	F2.close();
	remove("Military.dat");
	rename("Temp.dat","Military.dat");
}
void DeleteOfficerFile()
{
	clrscr();
	fstream F1,F2;
	F1.open("Military.dat",ios::binary|ios::in);
	F2.open("Temp.dat",ios::binary|ios::out);
	Officer O;
	char off[30];
	int found=0;
	cout<<"\nEnter the name of the Officer whose record is to be deleted : ";
	gets(off);
	while(F1.read((char *)&O,sizeof(O)))
	{
		if(strcmpi(O.ret_name(),off)!=0)
		{
			F2.write((char *)&O,sizeof(O));
		}
		else
		{
			found=1;
			cout<<"\nThe record has been successfully deleted";
		}
	}
	if(!found)
	cout<<"\nThe record could not be located!";
	getch();
	F1.close();
	F2.close();
	remove("Military.dat");
	rename("Temp.dat","Military.dat");
	clrscr();
}
void menu()
{
	clrscr();
	int ch;
	do
	{
		cout<<"\nMain Menu";
		cout<<"\n1.View existing personnel";
		cout<<"\n2.Add a new recruit";
		cout<<"\n3.Delete veteran record";
		cout<<"\n4.Modify prexisting record";
		cout<<"\n5.Exit";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:	SearchOfficerFile();
				break;
			case 2:	AddToOfficerFile();
				break;
			case 3:	DeleteOfficerFile();
				break;
			case 4:	ModifyOfficerFile();
				break;
			case 5:	cout<<"\nYou have succesfully logged out of the military database";
				break;
			default:cout<<"\nInvalid choice! Please re enter!";
		}
	}
	while(ch!=5);
}
void intro_screen()
{
	cout<<"  _    _  _____   __  __ _ _ _ _                   \n";
	cout<<" | |  | |/ ____| |  \\/  (_) (_) |                  \n";
	cout<<" | |  | | (___   | \\  / |_| |_| |_ __ _ _ __ _   _ \n";
	cout<<" | |  | |\\___ \\  | |\\/| | | | | __/ _` | '__| | | |\n";
	cout<<" | |__| |____) | | |  | | | | | || (_| | |  | |_| |\n";
	cout<<"  \\____/|_____/  |_|  |_|_|_|_|\\__\\__,_|_|    \__, |\n";
	cout<<"                                              __/ |\n";
	cout<<"                                             |___/\n";
	sleep(3);
	cout<<"\n\n\nWelcome to the United States Military Database";
	char password[10];
	cout<<"\n\nEnter password : ";
	gets(password);
	if(strcmp(password,"washington")==0)
	{
		cout<<"\nCorrect Password";
		getch();
	}
	else
	{
		cout<<"\nIncorrect Password! Shutting down!";
		getch();
		exit(0);
	}
	menu();
}
void main()
{
	clrscr();
	intro_screen();
	getch();
}