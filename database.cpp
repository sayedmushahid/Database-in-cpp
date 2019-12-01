#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;
//void input();
//void search();
//void edit();
//void displayall();
//int main();
class db
{
	private:
		string f_name;
		string m_name;
		string l_name;
		int age;
		string roll_no;
		public:
			void input();
			void search();
			void edit();
			void displayall();
			
				
};

int main()
{
	system("title DB");
	system("color A");
	db student;
	cout<<endl<<endl;
	cout<<"\t\t\t Welcome To DataBase Program Of CS-18";
	cout<<"\n\n 1. Input new student data."<<endl;
	cout<<" 2. Search for a student by his roll number."<<endl;
	cout<<" 3. Edit an existing data of students."<<endl;
	cout<<" 4. Display all students data."<<endl;
	cout<<" 5. Exit."<<endl<<endl;
	cout<<"\t\t\t\tPlease Enter Your Choice:"<<endl;
	cout<<"\t\t\t\t";
	int choice;
	cin>>choice;
	switch(choice)
	{
	case 1:
	{
		student.input();
		break;
	 } 
	 case 2:
	{
		student.search();
		break;
	 }
	 case 3:
	{
		student.edit();
		break;
	 }
	 case 4:
	{
		student.displayall();
		break;
	 }
	 case 5:
	{
		_Exit(EXIT_SUCCESS);
		break;
		}
	}
		
	return 0;
	
}
void db::input()
{
		system("cls");
	cout<<"\n\n";
	cout<<" Enter student first name"<<endl;
	cin.ignore();
	getline(cin,f_name);
	cout<<" Enter student middle name"<<endl;
	getline(cin,m_name);
	cout<<" Enter student last name"<<endl;
	getline(cin,l_name);
	cout<<" Enter student roll number"<<endl;
	getline(cin,roll_no);
	cout<<" Enter student age"<<endl;
	cin>>age;
	string filename;
	filename=roll_no;
	filename.append(".txt");
	ofstream file;
	file.open(filename);
	file<<"STUDENT NAME \t\t\t ROLL NUMBER \t AGE"<<endl;
	file<<f_name<<" "<<m_name<<" "<<l_name<<" \t\t "<<roll_no<<"\t\t "<<age;
	file.close();
		ofstream dir("alldata.txt" , ios :: app);
		dir<<f_name<<" "<<m_name<<" "<<l_name<<" \t\t "<<roll_no<<"\t\t "<<age<<endl;
		dir.close();
		cout<<endl;
		cout<<"____________________________________________________________________________________________________________________";
		cout<<endl;
		cout<<endl;
		main();
}

void db::search()
{
		system("cls");
		cout<<"\n\n";
		cout<<"Enter Student's Roll Number To Search:"<<endl;
		cin.ignore();
		getline(cin,roll_no);
		string filename;
		filename=roll_no;
		filename.append(".txt");
		cout<<endl<<endl;
		cout<<"The data of the student is:"<<endl<<endl;
		ifstream file;
		file.open(filename);
		string line;
		while(getline(file,line))
		{
			cout<<line<<endl;
		}
		file.close();
		cout<<endl;
		cout<<"____________________________________________________________________________________________________________________";
		cout<<endl;
		cout<<endl;
		main();
}
void db::edit()
{
	system("cls");
		cout<<"\n\n";
		cout<<"Enter Student's Roll Number To Edit:"<<endl;
		cin.ignore();
		getline(cin,roll_no);
		string filename;
		filename=roll_no;
		filename.append(".txt");
		cout<<endl<<endl;
		cout<<"The existing data of the student is:"<<endl<<endl;
		ifstream file;
		file.open(filename);
		string line;
		while(getline(file,line))
		{
			cout<<line<<endl;
		}
		file.close();
		cout<<"\n\n";
	cout<<"Enter the student's new first name"<<endl;
	cin.ignore(0);
	getline(cin,f_name);
	cout<<"Enter the student's new middle name"<<endl;
	getline(cin,m_name);
	cout<<"Enter the student's new last name"<<endl;
	getline(cin,l_name);
	cout<<"Enter the student's new roll number"<<endl;
	getline(cin,roll_no);
	cout<<"Enter the student's new age"<<endl;
	cin>>age;
	filename=roll_no;
	filename.append(".txt");
	ofstream newfile;
	newfile.open(filename);
	newfile<<"STUDENT NAME \t\t\t ROLL NUMBER \t AGE"<<endl;
	newfile<<f_name<<" "<<m_name<<" "<<l_name<<" \t\t "<<roll_no<<"\t\t "<<age;
		newfile.close();
		ofstream dir("alldata.txt" , ios :: app);
		dir<<f_name<<" "<<m_name<<" "<<l_name<<" \t\t "<<roll_no<<"\t\t "<<age<<endl;
		dir.close();
		cout<<endl;
		cout<<"____________________________________________________________________________________________________________________";
		cout<<endl;
		cout<<endl;
		main();
}
void db::displayall()
{
	system("cls");
	cout<<"\n\n\n\t\t\t\t THE DATA OF ALL STUDENTS OF CS-18 IS"<<endl<<endl<<endl;
	cout<<"STUDENT NAME \t\t\t ROLL NUMBER \t AGE"<<endl;
	cout<<endl;
		ifstream file;
		file.open("alldata.txt");
		string line;
		while(getline(file,line))
		{
			cout<<line<<endl;
		}
		file.close();
		cout<<endl;
		cout<<"____________________________________________________________________________________________________________________";
		cout<<endl;
		cout<<endl;
		main();
}
