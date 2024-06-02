#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<chrono>
#include<thread>
using namespace std;
struct Student
{
	int ID;
	string name;
	int age;
	string city;
	float computer, math, english, urdu, islamiat, percentage, total, CGPA;
	float fees;
	float fine;
	string grade;
};
// adding student student //
void addStudent(vector<Student>& students)
{
	Student student_data;
	cout << "Enter student ID: ";
	cin >> student_data.ID;
	cin.ignore();
	cout << "Enter student name: ";
	getline(cin, student_data.name);
	cout << "Enter student age: ";
	cin >> student_data.age;
	cin.ignore();
	cout << "Enter student city: ";
	getline(cin, student_data.city);
	students.push_back(student_data);
	cout << "Student added successfully." << endl;
	cin.ignore();
}
// display specific student data //
void showStudentData(const vector<Student>& students, int ID)
{
	for (const Student& student : students)
	{
		if (student.ID == ID)
		{
			cout << "Student ID = " << student.ID << endl;
			cout << "Student Name = " << student.name << endl;
			cout << "Student Age = " << student.age << endl;
			cout << "Student City = " << student.city << endl;
			cin.ignore();
			return;
		}
	}
	cout << "No student found with ID " << ID << "." << endl;
}
// edit student data //
void editStudent(vector<Student>& students, int ID)
{
	for (Student& student : students)
	{
		if (student.ID == ID)
		{
			cout << "Press 1 to change name :" << endl;
			cout << "Press 2 to change age :" << endl;
			cout << "Press 3 to change city :" << endl;
			cout << "Press 4 to go back :" << endl;
			int choice;
			cout << "Enter your choice: ";
			cin >> choice;
			cin.ignore();
			switch (choice)
			{
			case 1:
				cout << "Enter new name for student: ";
				getline(cin, student.name);
				cout << "\n\nNAME CHANGED SUCCESSFULLY.................press enter to go back";
				cin.ignore();
				break;
			case 2:
				cout << "Enter new age for student: ";
				cin >> student.age;
				cout << "\n\nAGE CHANGED SUCCESSFULLY.................press enter to go back";
				cin.ignore();
				break;
			case 3:
				cout << "Enter new city for student: ";
				cin.ignore();
				getline(cin, student.city);
				cout << "\n\nCITY CHANGED SUCCESSFULLY.................press enter to go back";
				cin.ignore();
				break;
			case 4:
				return;
			default:
				cout << "Invalid choice!" << endl;
				break;
			}
		}
	}
	cout << "Student not found with ID " << endl;
}
// display all students data //
void showAllStudentData(const vector<Student>& students)
{
	cout << "...........................STUDENT DATA................................\n\n";
	for (const Student& student : students)
	{
		cout << "----------------------------------------------------------------------\n\n";
		cout << "STUDENT ID = " << student.ID << endl;
		cout << "STUDENT NAME = " << student.name << endl;
		cout << "STUDENT AGE = " << student.age << endl;
		cout << "STUDENT CITY = " << student.city << endl;
		cout << "\n\n----------------------------------------------------------------------";
	}
	cin.ignore();
	cout << "\n\n--------------------------Press enter to exit--------------------------------";
}
// add exam result of a student //
void addExamResult(vector<Student>& students, int ID)
{
	for (Student& student : students)
	{
		if (student.ID == ID)
		{
			cout << "Enter marks for computer: ";
			cin >> student.computer;
			cout << "Enter marks for math: ";
			cin >> student.math;
			cout << "Enter marks for islamiat: ";
			cin >> student.islamiat;
			cout << "Enter marks for english: ";
			cin >> student.english;
			cout << "Enter marks for urdu: ";
			cin >> student.urdu;
			student.total = student.computer + student.math + student.islamiat + student.urdu +
				student.english;
			student.percentage = (student.total / 500) * 100;
			student.CGPA = student.percentage / 25;
			if (student.percentage >= 90)
			{
				student.grade = "A*";
			}
			else if (student.percentage >= 80 && student.percentage < 90)
			{
				student.grade = "A";
			}
			else if (student.percentage >= 70 && student.percentage < 80)
			{
				student.grade = "B";
			}
			else if (student.percentage >= 60 && student.percentage < 70)
			{
				student.grade = "C";
			}
			else if (student.percentage >= 50 && student.percentage < 60)
			{
				student.grade = "D";
			}
			else if (student.percentage >= 40 && student.percentage < 50)
			{
				student.grade = "E";
			}
			else
				student.grade = "F";
			cout << "Result added successfully......." << endl;
			cin.ignore(1);
			return;
		}
	}
	cout << "No student found with ID " << ID << "." << endl;
	cin.ignore();
}
//show exam result //
void showexamresult(vector<Student>& students, int ID)
{
	for (Student& student : students)
	{
		if (student.ID == ID)
		{
			cout << "Computer marks = " << student.computer << endl;
			cout << "English marks = " << student.english << endl;
			cout << "Urdu marks = " << student.urdu << endl;
			cout << "Maths marks = " << student.math << endl;
			cout << "Islamiat marks = " << student.islamiat << endl;
			cout << "Total marks = " << student.total << endl;
			cout << "Percentage = " << student.percentage << endl;
			cout << "CGPA = " << student.CGPA << endl;
			cout << "Grade = " << student.grade << endl;
			return;
		}
	}
	cout << "Student with ID " << ID << " not been founded !!!!!!!";
}
// Function to delete student data //
void deleteStudentData(vector<Student>& students, int ID)
{
	for (auto del = students.begin(); del != students.end(); ++del)
	{
		if (del->ID == ID)
		{
			students.erase(del);
			cout << "Student data with ID " << ID << " has been deleted successfully." << endl;
			cin.ignore();
			return;
		}
	}
	cout << "No student found with ID " << ID << "." << endl;
	cin.ignore();
}
//edit exam result //
void editexamresult(vector<Student>& students, int ID)
{
	for (Student& student : students)
	{
		if (student.ID == ID)
		{
			cout << "What do you want to change.........?" << endl;
			cout << "Press 1 to change Computer Marks." << endl;
			cout << "Press 2 to change Urdu Marks" << endl;
			cout << "Press 3 to change Islamiat Marks." << endl;
			cout << "Press 4 to change Maths Marks." << endl;
			cout << "Press 5 to change English Marks." << endl;
			cout << "Press 6 to go back." << endl;
			int choice;
			cout << "Enter your choice: ";
			cin >> choice;
			cin.ignore();
			switch (choice)
			{
			case 1:
				cout << "Enter new Marks for computer : ";
				cin >> student.computer;
				cout << "\n\nMarks CHANGED SUCCESSFULLY.................press enter to go back";
				cin.ignore();
				break;
			case 2:
				cout << "Enter new Marks for Urdu : ";
				cin >> student.urdu;
				cout << "\n\nMarks CHANGED SUCCESSFULLY.................press enter to go back";
				cin.ignore();
				break;
			case 3:
				cout << "Enter new Marks for Islamiat : ";
				cin >> student.islamiat;
				cout << "\n\nMarks CHANGED SUCCESSFULLY.................press enter to go back";
				cin.ignore();
				break;
			case 4:
				cout << "Enter new Marks for Maths : ";
				cin >> student.math;
				cout << "\n\nMarks CHANGED SUCCESSFULLY.................press enter to go back";
				cin.ignore();
				break;
			case 5:
				cout << "Enter new Marks for computer : ";
				cin >> student.english;
				cout << "\n\nMarks CHANGED SUCCESSFULLY.................press enter to go back";
				cin.ignore();
				break;
			case 6:
				return;
			default:
				cout << "Invalid choice!" << endl;
				break;
			}
			student.total = student.computer + student.math + student.islamiat + student.urdu +
				student.english;
			student.percentage = (student.total / 500) * 100;
			student.CGPA = student.percentage / 25;
			if (student.percentage >= 90)
			{
				student.grade = "A1";
			}
			else if (student.percentage >= 80 && student.percentage < 90)
			{
				student.grade = "A";
			}
			else if (student.percentage >= 70 && student.percentage < 80)
			{
				student.grade = "B";
			}
			else if (student.percentage >= 60 && student.percentage < 70)
			{
				student.grade = "C";
			}
			else if (student.percentage >= 50 && student.percentage < 60)
			{
				student.grade = "D";
			}
			else if (student.percentage >= 40 && student.percentage < 50)
			{
				student.grade = "E";
			}
			else
				student.grade = "F";
			cout << "Exam Edit successfully............press enter to go back";
			cin.ignore();
			return;
		}
	}
	cout << "Student with ID " << ID << " not been founded!!!!!";
}
//show all student result //
void showallresult(vector<Student>& students)
{
	cout << "Student Exam Results:\n";
	for (const Student& student : students)
	{
		cout << "-------------------------------------------------\n\n";
		cout << "Student ID = " << student.ID << endl;
		cout << "Computer marks = " << student.computer << endl;
		cout << "English marks = " << student.english << endl;
		cout << "Urdu marks = " << student.urdu << endl;
		cout << "Maths marks = " << student.math << endl;
		cout << "Islamiat marks = " << student.islamiat << endl;
		cout << "Total marks = " << student.total << endl;
		cout << "Percentage = " << student.percentage << endl;
		cout << "CGPA = " << student.CGPA << endl;
		cout << "Grade = " << student.grade << endl;
	}
	cout << "---------------------\n\n";
}
//add student fees //
void addfees(vector<Student>& students, int ID)
{
	for (Student& student : students)
	{
		if (student.ID == ID)
		{
			float fee = 80000;
			cout << "The origional fee of school is : " << fee << endl;
			cout << "Checking discount for student through percentage of student..........." <<
				endl;;
			if (student.percentage >= 90)
			{
				cout << "checking for scholarship..........." << flush << endl;
				this_thread::sleep_for(chrono::seconds(5));
				cout << "Grade of student is " << student.grade << endl;
				cout << "Student got 50 percent scholar ship...............: " << endl;
				student.fees = fee * 0.50;
				student.fine = 0;
			}
			else if (student.percentage >= 80 && student.percentage < 90)
			{
				cout << "checking for scholarship..........." << flush << endl;
				this_thread::sleep_for(chrono::seconds(5));
				cout << "Grade of student is " << student.grade << endl;;
				cout << "Student got 35 percent scholar ship...............: " << endl;
				student.fees = fee * 0.65;
				student.fine = 0;
			}
			else if (student.percentage >= 70 && student.percentage < 80)
			{
				cout << "checking for scholarship..........." << flush << endl;
				this_thread::sleep_for(chrono::seconds(5));
				cout << "Grade of student is " << student.grade << endl;;
				cout << "Student got 20 percent scholar ship...............: " << endl;
				student.fees = fee * 0.80;
				student.fine = 0;
			}
			else if (student.percentage >= 60 && student.percentage < 70)
			{
				cout << "checking for scholarship..........." << flush << endl;
				this_thread::sleep_for(chrono::seconds(5));
				cout << "Grade of student is " << student.grade << endl;;
				cout << "Student got 12 percent scholar ship...............: " << endl;
				student.fees = fee * 0.88;
				student.fine = 0;
			}
			else if (student.percentage < 40)
			{
				student.fine = 50000;
				cout << "checking for scholarship..........." << flush << endl;
				this_thread::sleep_for(chrono::seconds(5));
				cout << "Grade of student is " << student.grade << endl;
				cout << "Student got fine............: " << endl;
				student.fees = student.fine + fee;
				cin.ignore();
			}
			else
			{
				cout << "checking for scholarship..........." << flush;
				this_thread::sleep_for(chrono::seconds(5));
				cout << "Grade of student is " << student.grade << endl;;
				cout << "Student got no scholorship .......!!" << endl;
				student.fees = fee;
				student.fine = 0;
			}
			cout << "Fees of student added successfully !!!!" << endl;
			cout << "You can check full detail of fees slip on <SHOW FEE SLIP MENU OF STUDENT > ......" << endl;
			cout << "press enter to go out...........!!";
			cin.ignore();
			return;
		}
	}
}
//show student fees //
void showfee(vector<Student>& students, int ID)
{
	for (Student& student : students)
	{
		if (student.ID == ID)
		{
			cout << "\n\n------------------------------------------------------------------------------------------------- - \n\n";
			cout << "NAME = " << student.name << endl;
			cout << "GRADE = " << student.grade << endl;
			cout << "TUTION FEES = 50000" << endl;
			cout << "SECURITY FEES = 10000" << endl;
			cout << "SPORTS FEES = 5000" << endl;
			cout << "MEDICAL FACILITY = 5000" << endl;
			cout << "TRANSPORT FAIR = 10000" << endl;
			cout << "TOTAL FEES = 80000" << endl;
			cout << "FINE = " << student.fine << endl;
			cout << "TOTAL FEES WITH DISCOUNT AND FINE = " << student.fees << endl;
			cout << "\n\n------------------------------------------------------------------------------------------------- - \n\n";
			cout << "\n---Press enter to go out-----";
			cin.ignore();
			return;
		}
	}
	cout << "Student with ID " << ID << " has not been founded...........";
}
//show all student fees //
void allfees(vector<Student>& students)
{
	for (Student student : students)
	{
		cout << "\n----------------------------------------------------------------\n";
		cout << "Student ID = " << student.ID << endl;
		cout << "Student NAME = " << student.name << endl;
		cout << "Student FEES = " << student.fees << endl;
	}
	cout << "press enter to go back ---------------------------------------";
	cin.ignore();
}
//store data into file //
void store(const vector<Student>& students, const string& filename)
{
	ofstream file(filename);
	if (file.is_open())
	{
		for (const Student& student : students)
		{
			file << student.ID << ",";
			file << student.name << ",";
			file << student.age << ",";
			file << student.city << ",";
			file << student.computer << ",";
			file << student.math << ",";
			file << student.english << ",";
			file << student.urdu << ",";
			file << student.islamiat << ",";
			file << student.percentage << ",";
			file << student.total << ",";
			file << student.CGPA << ",";
			file << student.fees << ",";
			file << student.fine << ",";
			file << student.grade << "," << "\n";
		}
		file.close();
		cout << "Data saved to file: " << filename << endl;
		cin.ignore();
	}
	else
		cout << "Error opening file: " << filename << endl;
	cin.ignore();
}
//load student data from a file //
void readfile(vector<Student>& students, const string& filename)
{
	ifstream file(filename);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			Student stu;
			size_t pos = 0;
			string temp;
			int count = 0;
			while ((pos = line.find(',')) != string::npos)
			{
				temp = line.substr(0, pos);
				switch (count)
				{
				case 0:
					stu.ID = stoi(temp);
					break;
				case 1:
					stu.name = temp;
					break;
				case 2:
					stu.age = stoi(temp);
					break;
				case 3:
					stu.city = temp;
					break;
				case 4:
					stu.computer = stof(temp);
					break;
				case 5:
					stu.math = stof(temp);
					break;
				case 6:
					stu.english = stof(temp);
					break;
				case 7:
					stu.urdu = stof(temp);
					break;
				case 8:
					stu.islamiat = stof(temp);
					break;
				case 9:
					stu.percentage = stof(temp);
					break;
				case 10:
					stu.total = stof(temp);
					break;
				case 11:
					stu.CGPA = stof(temp);
					break;
				case 12:
					stu.fees = stof(temp);
					break;
				case 13:
					stu.fine = stof(temp);
					break;
				case 14:
					stu.grade = temp;
					break;
				}
				line.erase(0, pos + 1);
				count++;
			}
			students.push_back(stu);
		}
		file.close();
		cout << "\n.....................DATA LOADED FROM FILE SUCCESSFULLY.............................\n";
	}
	else
		cout << "file is not found with name " << filename;
}
// front end of project
int main()
{
	vector<Student> students;
	int ID;
	int choice;
	readfile(students, "data.txt");
	while (true)
	{
		system("cls");

		cout << "...............................STUDENT MANAGEMENT SYSTEM...................................\n\n";
		cout << "PRESS 1 - Add student data" << endl;
		cout << "PRESS 2 - Edit student data" << endl;
		cout << "PRESS 3 - Show specific student data" << endl;
		cout << "PRESS 4 - Show all students data" << endl;
		cout << "PRESS 5 - Delete student data" << endl;
		cout << "PRESS 6 - Add student exam result" << endl;
		cout << "PRESS 7 - Edit student exam result" << endl;
		cout << "PRESS 8 - Show specific student exam result" << endl;
		cout << "PRESS 9 - Show all students exam result" << endl;
		cout << "PRESS 10 - Add student fees" << endl;
		cout << "PRESS 11 - Show Student fees" << endl;
		cout << "PRESS 12 - Show all Student fees" << endl;
		cout << "PRESS 13 - Save the data" << endl;
		cout << "PRESS 0 - Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
			system("cls");
			addStudent(students);
			cin.ignore();
			break;
		case 2:
			system("cls");
			cout << "Enter ID of student you want to edit: ";
			cin >> ID;
			cin.ignore();
			editStudent(students, ID);
			break;
		case 3:
			system("cls");
			cout << "Enter ID of student to display data: ";
			cin >> ID;
			cin.ignore();
			showStudentData(students, ID);
			cout << "\n\n...........................press enter to go back.................................." << endl;
			cin.ignore();
			break;
		case 4:
			system("cls");
			cout << "...........................All student data....................\n\n";
			showAllStudentData
			(students);
			cout << "\n\n--------------------------Press enter to exit--------------------------------" << endl;
			cin.ignore();
			break;
		case 5:
			system("cls");
			cout << "Enter the ID of student you want to delete: ";
			cin >> ID;
			cin.ignore();
			deleteStudentData(students, ID);
			break;
		case 6:
			system("cls");
			cout << "Enter the ID of student: ";
			cin >> ID;
			cin.ignore();
			showStudentData(students, ID);
			addExamResult(students, ID);
			break;
		case 7:
			system("cls");
			cout << "Enter ID of student that you want to edit: ";
			cin >> ID;
			showexamresult(students, ID);
			editexamresult(students, ID);
			cin.ignore();
			break;
		case 8:
			system("cls");
			cout << "Enter ID of student to display result: ";
			cin >> ID;
			showStudentData(students, ID);
			showexamresult(students, ID);
			cin.ignore();
			break;
		case 9:
			system("cls");
			cout << "Show all students exam result" << endl;
			showallresult(students);
			cin.ignore();
			break;
		case 10:
			system("cls");
			cout << "Enter ID of student to display result: ";
			cin >> ID;
			showStudentData(students, ID);
			showexamresult(students, ID);
			addfees(students, ID);
			cin.ignore();
			break;
		case 11:
			system("cls");
			cout << "Enter ID of student to display result: ";
			cin >> ID;
			showfee(students, ID);
			cin.ignore();
			break;
		case 12:
			system("cls");
			allfees(students);
			break;
		case 13:
			store(students, "data.txt");
			break;
		case 0:
			return 0;
		default:
			cout << "Invalid choice. Please try again." << endl;
			cin.ignore();
			break;
		}
	}
	return 0;
}