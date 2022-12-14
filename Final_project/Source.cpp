#include <iostream>
#include <Windows.h>
#include <time.h>
#include <functional>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <map>
using namespace std;



class result {
	int correct, incorrect;
	double procent;
	int mark;
	string roz;
	string tst;
public:
	result() {
		correct = incorrect = 0;
		procent = 0;
		mark = 0;
	}
	result(double procent, int correct, int incorrect, int mark, string r, string t) {
		this->correct = correct;
		this->incorrect = incorrect;
		this->procent = procent;
		this->mark = mark;
		this->roz = r;
		this->tst = t;
	}

	void print() {
		cout << string(20, '-') << "\n";
		cout << "Rozdil: " << roz << "\n";
		cout << "Test: " << tst << "\n";
		cout << string(20, '-') << "\n";
		cout << "Correct: " << correct << "\n";
		cout << "Incorrect: " << incorrect << "\n";
		cout << "Procent: " << procent << "%\n";
		cout << "Mark: " << mark << "\n";
		cout << string(20, '-') << "\n\n";
	}

	string getRozdil() { return roz; }
	string getTest() { return tst; }
};


class tester {
	string login, password;
	string name, surname, fname;
	string adress;
	string number;
	vector<result> results;
public:
	tester() {
		login = "Not set";
		password = "Not set";
		name = "Not set";
		surname = "Not set";
		fname = "Not set";
		adress = "Not set";
		number = "Not set";
	}
	tester(string name, string surname, string fname, string adress, string number) {
		this->name = name;
		this->surname = surname;
		this->fname = fname;
		this->adress = adress;
		this->number = number;
	}
	tester(string login, string password, string name, string surname, string fname, string adress, string number) {
		this->login = login;
		this->password = password;
		this->name = name;
		this->surname = surname;
		this->fname = fname;
		this->adress = adress;
		this->number = number;
	}

	void print() {
		cout << string(20, '-') << "\n";
		cout << "Login: " << login << "\n";
		cout << "Password: " << password << "\n";
		cout << "Name: " << name << "\n";
		cout << "Surame: " << surname << "\n";
		cout << "Fname: " << fname << "\n";
		cout << "Adress: " << adress << "\n";
		cout << "Number: " << number << "\n";
	}
	template <class T>
	void print(T a) {
		cout << string(20, '-') << "\n";
		cout << "Name: " << name << "\n";
		cout << "Surame: " << surname << "\n";
		cout << "Fname: " << fname << "\n";
		cout << "Adress: " << adress << "\n";
		cout << "Number: " << number << "\n";
	}

	void set() {
		cout << string(30, '-') << "\n";
		cout << "Enter login: ";
		cin >> login;
		cout << "Enter password: ";
		cin >> password;
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter surname: ";
		cin >> surname;
		cout << "Enter fname: ";
		cin >> fname;
		cout << "Enter adress: ";
		cin >> adress;
		cout << "Enter number: ";
		cin >> number;
		cout << string(30, '-') << "\n";
	}

	void set(string login, string password) {
		cout << string(20, '-') << "\n";
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter surname: ";
		cin >> surname;
		cout << "Enter fname: ";
		cin >> fname;
		cout << "Enter adress: ";
		cin >> adress;
		cout << "Enter number: ";
		cin >> number;
		this->login = login;
		this->password = password;
		cout << string(20, '-') << "\n";
	}

	void printResults() {
		for (int i = 0; i < results.size(); i++) {

			results[i].print();
		}
	}

	void addResult(result r) { results.push_back(r); }

	string getLogin() { return login; }
	string getPassword() { return password; }
	vector<result> getResults() { return results; }
	result getResult(int i) { return results[i]; }

	string getInfo() {
		string info = name + " " + surname + " " + fname + " " + adress + " " + number + "\n";
		return info;
	}
	string getAll() {
		string all = login + " " + password + " " + name + " " + surname + " " + fname + " " + adress + " " + number;
		return all;
	}
};


// Print
template <class T>
void printVector(vector<T> v) {
	cout << string(50, '-') << "\n\n";
	for (int i = 0; i < v.size(); i++)
		v[i].print();
	cout << string(50, '-') << "\n";

}

void printMap(map<string, string> m) {
	cout << string(20, '-') << "\n";
	for (auto el : m) {
		cout << el.first << " | " << el.second << "\n";
	}
	cout << string(20, '-') << "\n\n";

}

template <class T3>
void printAllTesters(vector<T3> v, map<string, string> m) {

	int i = 0;
	for (auto el : m) {
		cout << string(20, '-') << "\n";
		cout << v[i].getLogin() << " | " << v[i].getPassword() << "\n";
		v[i].print(1);
		i++;
		cout << string(20, '-') << "\n\n";
	}

}


// Reading
void testersReadingFromFile(vector<tester>& testers, map<string, string>& tester_log) {

	fstream read_tester;
	read_tester.open("Test.txt", fstream::in);
	if (!read_tester.is_open()) cout << "Error open file\n";

	string login, password, name, surname, fname, adress, number;

	while (!read_tester.eof()) {
		read_tester >> login >> password >> name >> surname >> fname >> adress >> number;

		tester t(login, password, name, surname, fname, adress, number);
		testers.push_back(t);
		tester_log.insert({ login, password });
	}

	read_tester.close();
}

// Writing
void testersWritingToFile(vector<tester> testers, map<string, string> tester_log) {
	fstream write_tester;
	write_tester.open("Tester.txt", fstream::out);
	if (!write_tester.is_open()) cout << "Error open file\n";


	if (!write_tester.is_open()) cout << "Error open file\n";
	int i = 0;
	for (auto el : tester_log) {
		int length = write_tester.tellg();
		if (length == 0)
			write_tester << testers[i].getAll();
		else
			write_tester << "\n" << testers[i].getAll();
		i++;
	}

	write_tester.close();
}


// Sign in
void testerSignIn(vector<tester>& testers, map<string, string> tester_log, tester& active_tester) {
	string login, password;

	system("cls");
	cout << "Sign in \n";
	cout << string(20, '-') << "\n";
	cout << "Enter login: ";
	cin >> login;
	cout << "Enter password: ";
	cin >> password;
	cout << string(20, '-') << "\n";

	auto res = tester_log.find(login);
	if (res == tester_log.end()) cout << "Incorrect login\n";
	else {
		if (res->second != password) cout << "Incorrect password\n";
		else {
			for (int i = 0; i < testers.size(); i++) {
				if (testers[i].getLogin() == res->first)
					active_tester = testers[i];
			}

			cout << "Correct\n\n";
		}
	}
}


// Sign up
void testerSignUp(vector<tester>& testers, map<string, string>& tester_log, tester& active_tester) {
	string login, password;

	system("cls");
	cout << "Sign up \n";
	cout << string(20, '-') << "\n";
	cout << "Enter login: ";
	cin >> login;
	cout << "Enter password: ";
	cin >> password;
	cout << string(20, '-') << "\n\n";

	auto res = tester_log.find(login);
	if (res != tester_log.end()) cout << "This login is already used\n";
	else {
		tester t;
		t.set(login, password);
		tester_log.insert({ login, password });
		testers.push_back(t);
		active_tester = t;

		cout << "Correct\n\n";
	}

}


// --------------------------- Admin

// Sign up
void adminSignUp() {
	string login, password;

	system("cls");
	cout << "Sign up \n";
	cout << string(20, '-') << "\n";
	cout << "Enter login: ";
	cin >> login;
	cout << "Enter password: ";
	cin >> password;
	cout << string(20, '-') << "\n";


	fstream write_admin;
	write_admin.open("Admin.txt", fstream::out);
	if (!write_admin.is_open()) cout << "Error open file\n";

	write_admin << login << " " << password;

	write_admin.close();
}

// Sign in
void adminSignIn() {
	// Read
	fstream read_admin;
	read_admin.open("Admin.txt", fstream::in);
	if (!read_admin.is_open()) cout << "Error open file\n";

	string admin_login, admin_password;
	read_admin >> admin_login >> admin_password;

	read_admin.close();


	string login, password;

	system("cls");
	cout << "Sign in \n";
	cout << string(20, '-') << "\n";
	cout << "Enter login: ";
	cin >> login;
	cout << "Enter password: ";
	cin >> password;
	cout << string(20, '-') << "\n";

	if (login != admin_login) {
		cout << "Incorrect login\n";
	}
	else {
		if (password != admin_password) {
			cout << "Incorrect password\n";
		}
		else {
			cout << "Correct\n\n";
		}
	}

}






// ------------------------------------------------------- Actoins

// -------------------------- Tester

// -----------Tests

class question {
	string quest;
	vector<string> answers;
	int number_answers;
	int correct;
public:
	question() {
		quest = "Not set";
		correct = 0;
		number_answers = 0;
	}
	question(string quest, vector<string> answers, int number_answers, int correct) {
		this->quest = quest;
		this->answers = answers;
		this->number_answers = number_answers;
		this->correct = correct;
	}

	void print() {
		cout << string(50, '-') << "\n";
		cout << quest << "\n";
		cout << string(50, '-') << "\n";
		for (int i = 1; i < answers.size(); i++) {
			cout << i << ". " << answers[i] << "\n";
		}
		cout << string(50, '-') << "\n\n";
	}

	void setQuestion(vector<question> questions) {

		system("cls");
		cout << string(30, '-') << "\n";
		cout << "Enter question name: ";
		cin >> quest;

		cout << "Enter number of answers: ";
		cin >> number_answers;

		for (int i = 1; i <= number_answers; i++)
		{
			string a;
			cout << "Enter " << i << " answer: ";
			cin >> a;
			answers.push_back(a);
			if (i == 1)
				answers.push_back(a);
		}


		cout << "Enter number of correct answer: ";
		cin >> correct;


		cout << string(30, '-') << "\n";

	}

	int getCorrect() { return correct; }
};


void printQuestions(vector<question> questions) {
	for (int i = 0; i < questions.size(); i++) {
		questions[i].print();
	}
}


void readQuestions(vector<question>& questions) {
	fstream read_qustions;
	read_qustions.open("Tests.txt", fstream::in);
	if (!read_qustions.is_open()) cout << "Error open file\n";

	while (!read_qustions.eof()) {
		string quest, line;
		vector<string> answers;
		int number_answers, correct;

		getline(read_qustions, quest);
		read_qustions >> number_answers >> correct;
		for (int i = 0; i <= number_answers; i++) {
			getline(read_qustions, line);
			answers.push_back(line);
		}

		question q(quest, answers, number_answers, correct);
		questions.push_back(q);
	}

	read_qustions.close();
}


class test {
	string name;
	vector<question> questions;
	int number_questions;
public:
	test() {
		name = "Not set";
		number_questions = 0;
	}
	test(string name, vector<question> questions, int number_questions) {
		this->name = name;
		this->questions = questions;
		this->number_questions = number_questions;
	}

	void addQuestion(question qq) {
		system("cls");
		cout << "Number questions: " << number_questions << "\n";
		cout << "Questions size: " << questions.size() << "\n";
		questions.push_back(qq);
		number_questions++;
		cout << "\nNumber questions: " << number_questions << "\n";
		cout << "Questions size: " << questions.size() << "\n";
		system("pause");
	}

	void print() {
		system("cls");
		cout << "\nNumber questions: " << number_questions << "\n";
		cout << "Questions size: " << questions.size() << "\n";
		system("pause");
		cout << "Test name: " << name << "\n";
		cout << string(50, '-') << "\n\n";
		for (int i = 0; i < number_questions; i++) {
			questions[i].print();
		}
		cout << string(50, '-') << "\n";
	}

	void set(string name, vector<question> questions, int number_questions) {
		this->name = name;
		this->questions = questions;
		this->number_questions = number_questions;
	}

	void setTest(vector<question> quests, vector<test> tests) {

		system("cls");
		cout << string(30, '-') << "\n";
		cout << "Enter test name: ";
		cin >> name;

		cout << "Enter number of questions: ";
		cin >> number_questions;

		for (int i = 1; i <= number_questions; i++)
		{
			question q;
			q.setQuestion(questions);
			questions.push_back(q);

			quests.push_back(q);
		}

		cout << string(30, '-') << "\n";
	}

	string getName() { return name; }
	int getNumber() { return number_questions; }
	vector<question> getQuestions() { return questions; }
};

void readTests(vector<question>& questions, vector<test>& tests) {
	fstream read_tests;
	read_tests.open("Tests.txt", fstream::in);
	if (!read_tests.is_open()) cout << "Error open file\n";

	while (!read_tests.eof()) {

		string name;
		int number_questions;
		getline(read_tests, name);
		read_tests >> number_questions;

		vector<question> qwer;
		for (int i = 0; i < number_questions; i++) {
			string quest, line;
			vector<string> answers;
			int number_answers, correct;

			if (i == 0)
				getline(read_tests, quest);
			getline(read_tests, quest);
			read_tests >> number_answers >> correct;
			for (int j = 0; j <= number_answers; j++) {
				getline(read_tests, line);
				answers.push_back(line);
			}

			question q(quest, answers, number_answers, correct);
			questions.push_back(q);


			qwer.push_back(q);
		}

		test t(name, qwer, number_questions);

		tests.push_back(t);

	}

	read_tests.close();
}


// ------------------------------
class rozdil {
	string name;
	vector<test> tests;
	int number_tests;
public:
	rozdil() {
		name = "Not set";
		number_tests = 0;
	}
	rozdil(string name, vector<test> tests, int number_tests) {
		this->name = name;
		this->tests = tests;
		this->number_tests = number_tests;
	}

	void print() {
		cout << "Rozdil name: " << name << "\n";
		cout << string(50, '-') << "\n\n";
		for (int i = 0; i < number_tests; i++) {
			tests[i].print();
		}
		cout << string(50, '-') << "\n";
	}

	void setRozdil(vector<question> quests, vector<test> tsts, vector<rozdil> rozs) {

		cout << string(30, '-') << "\n";
		cout << "Enter name: ";
		cin >> name;

		cout << "Enter number of tests: ";
		cin >> number_tests;

		for (int i = 0; i < number_tests; i++)
		{
			test ttt;
			ttt.setTest(quests, tsts);

			tests.push_back(ttt);
		}

	}

	void addTest(test& t) { this->tests.push_back(t); number_tests++; }

	string getName() { return name; }
	int getNumber() { return number_tests; }
	vector<test> getTests() { return tests; }
	test getTest(int i) { return tests[i]; }
};


void readRozdil(vector<question>& questions, vector<test>& tests, vector<rozdil>& rozdils) {
	fstream read_rozdil;
	read_rozdil.open("Test.txt", fstream::in);
	if (!read_rozdil.is_open()) cout << "Error open file\n";

	
	while (!read_rozdil.eof()) {

		string name;
		int number_tests;
		getline(read_rozdil, name);
		read_rozdil >> number_tests;

		vector<test> tst;
		for (int i = 0; i < number_tests; i++) {
			string name_test;
			int number_questions;

			if (i == 0)
				getline(read_rozdil, name_test);
			getline(read_rozdil, name_test);
			read_rozdil >> number_questions;

			vector<question> qwer;
			for (int k = 0; k < number_questions; k++) {
				string quest, line;
				vector<string> answers;
				int number_answers, correct;

				if (k == 0)
					getline(read_rozdil, quest);
				getline(read_rozdil, quest);
				read_rozdil >> number_answers >> correct;
				for (int j = 0; j <= number_answers; j++) {
					getline(read_rozdil, line);
					answers.push_back(line);
				}

				question q(quest, answers, number_answers, correct);
				questions.push_back(q);


				qwer.push_back(q);
			}

			test t(name_test, qwer, number_questions);
			tests.push_back(t);
			tst.push_back(t);
		}

		rozdil r(name, tst, number_tests);

		rozdils.push_back(r);

	}

	read_rozdil.close();
}



void passTest(test t, tester& active_tester, rozdil roz, vector<tester>& testers) {
	int number = t.getNumber();
	vector<question> questions = t.getQuestions();
	vector<int> correct_ansewrs;
	vector<int> choice_ansewrs;
	int correct = 0, incorrect = 0;

	for (int i = 0; i < number; i++) {
		system("cls");
		cout << string(30, '-') << "\n";
		cout << "Name: " << t.getName() << "\n";
		cout << string(30, '-') << "\n\n";

		int choice;
		questions[i].print();
		cout << "Eneter choice: ";
		cin >> choice;
		choice_ansewrs.push_back(choice);
		correct_ansewrs.push_back(questions[i].getCorrect());

		cout << string(30, '-') << "\n\n";

	}

	for (int i = 0; i < number; i++) {
		if (choice_ansewrs[i] == correct_ansewrs[i])
			correct++;
		else
			incorrect++;
	}

	system("cls");
	double procent = 100 / number * correct;
	int mark = 12 / number * correct;
	result r(procent, correct, incorrect, mark, roz.getName(), t.getName());

	r.print();
	active_tester.addResult(r);
	for (int i = 0; i < testers.size(); i++)
	{
		if (testers[i].getLogin() == active_tester.getLogin()) {
			testers[i].addResult(r);
		}
	}


	system("pause");

}




// --------------------- Menu
int m1() {
	int choice;
	system("cls");
	cout << string(20, '-') << "\nTester - 0 \nAdmin  - 1\n" << string(20, '-') << "\nEnter choice: ";
	cin >> choice;
	return choice;
}
int m2() {
	fstream read_admin;
	read_admin.open("Admin.txt", fstream::in);
	if (!read_admin.is_open()) cout << "Error open file\n";


	int admin_length = read_admin.tellg();

	read_admin.close();

	int choice = m1();
	switch (choice)
	{
	case 0:
		// Tester
		system("cls");
		cout << "Tester\n";
		cout << string(20, '-') << "\nSign in - 0\n";
		cout << "Sign up - 1\n" << string(20, '-');
		cout << "\nEnter choice: ";
		cin >> choice;
		return choice;
		break;
	case 1:
		// Admin
		system("cls");
		cout << "Admin\n";
		cout << string(20, '-') << "\n";

		if (admin_length == 0)
			cout << "Sign in - 0";
		else
			cout << "Sign up - 1";

		cout << "\n" << string(20, '-');
		cout << "\nEnter choice: ";
		cin >> choice;
		return choice + 10;
		break;
	default:
		break;
	}
}
int m3(vector<tester>& testers, map<string, string>& tester_log, tester& active_tester) {

	int choice = m2();
	switch (choice)
	{
	case 0:
		testerSignIn(testers, tester_log, active_tester);
		return 1;
		break;
	case 1:
		testerSignUp(testers, tester_log, active_tester);
		return 1;
		break;
	case 10:
		adminSignIn();
		return 2;
		break;
	case 11:
		adminSignUp();
		return 2;
		break;
	default:
		break;
	}

}
int m4(vector<tester>& testers, map<string, string>& tester_log, tester& active_tester) {

	int choice = m3(testers, tester_log, active_tester);


	switch (choice)
	{
	case 1:
		system("cls");
		cout << string(20, '-') << "\n";
		cout << "Make test - 1\n";
		cout << "See result - 2\n";
		cout << string(20, '-') << "\n\n";
		cout << "Enter choice: ";
		cin >> choice;
		return choice;
		break;
	case 2:
		system("cls");
		cout << string(20, '-') << "\n";
		cout << "Eddit testers - 1\n";
		cout << "See statistic - 2\n";
		cout << "Add tests     - 3\n";
		cout << string(20, '-') << "\n\n";
		cout << "Enter choice: ";
		cin >> choice;
		return choice + 10;
		break;
	default:
		break;
	}

}

void menu(vector<tester>& testers, map<string, string>& tester_log, tester& active_tester, vector<rozdil>& rozdils, vector<test>& tests, vector<question>& questions) {

	int c = m4(testers, tester_log, active_tester);

	switch (c)
	{
	case 1:
		// Rozdil
		int r;
		system("cls");
		cout << string(20, '-') << "\n";
		for (int i = 1; i <= rozdils.size(); i++)
		{
			cout << rozdils[i - 1].getName() << " - " << i << "\n";
		}
		cout << string(20, '-') << "\n\n";
		cout << "Enter choice: ";
		cin >> r;

		// Test
		int t;
		system("cls");
		cout << string(20, '-') << "\n";
		for (int i = 1; i <= rozdils[r - 1].getNumber(); i++)
		{
			cout << rozdils[r - 1].getTest(i - 1).getName() << " - " << i << "\n";
		}
		cout << string(20, '-') << "\n\n";
		cout << "Enter choice: ";
		cin >> t;


		system("cls");
		passTest(rozdils[r - 1].getTest(t - 1), active_tester, rozdils[r - 1], testers);
		break;
	case 2:
		system("cls");
		cout << "See results " << active_tester.getLogin() << "\n";
		cout << string(50, '-') << "\n\n";
		for (int i = 0; i < active_tester.getResults().size(); i++)
			active_tester.getResult(i).print();
		cout << string(50, '-') << "\n\n";
		break;
	case 11:
		int tr;
		system("cls");
		cout << string(50, '-') << "\n\n";
		for (int i = 1; i <= testers.size(); i++)
		{
			cout << testers[i - 1].getLogin() << " - " << i << "\n";
		}
		cout << "\n" << string(50, '-') << "\n\n";

		cout << "Enter choice: ";
		cin >> tr;

		system("cls");
		testers[tr - 1].set();

		break;
	case 12:
		int ch;
		system("cls");
		cout << string(50, '-') << "\n";
		cout << "Tester result - 1\n";
		cout << "Rozdil result - 2\n";
		cout << "Test result   - 3\n";
		cout << string(50, '-') << "\n\n";

		cout << "Enter choice: ";
		cin >> ch;


		switch (ch)
		{
		case 1:
			int cho;
			system("cls");
			cout << string(50, '-') << "\n\n";
			for (int i = 1; i <= testers.size(); i++)
			{
				cout << testers[i - 1].getLogin() << " - " << i << "\n";
			}
			cout << "\n" << string(50, '-') << "\n\n";

			cout << "Enter choice: ";
			cin >> cho;

			system("cls");
			cout << string(50, '-') << "\n\n";
			for (int i = 0; i < testers[cho - 1].getResults().size(); i++)
				testers[cho - 1].getResult(i).print();
			cout << string(50, '-') << "\n\n";
			break;
		case 2:
			system("cls");
			cout << string(50, '-') << "\n\n";
			for (int i = 1; i <= rozdils.size(); i++)
			{
				cout << rozdils[i - 1].getName() << " - " << i << "\n";
			}
			cout << "\n" << string(50, '-') << "\n\n";

			cout << "Enter choice: ";
			cin >> cho;

			system("cls");
			for (int i = 0; i < testers.size(); i++)
			{
				for (int j = 0; j < testers[i].getResults().size(); j++)
				{
					if (testers[i].getResult(j).getRozdil() == rozdils[cho - 1].getName())
					{
						testers[i].getResult(j).print();
					}
				}
			}
			break;
		case 3:
			system("cls");
			cout << string(50, '-') << "\n";
			for (int i = 1; i <= rozdils.size(); i++)
			{
				vector<test> ttt = rozdils[i - 1].getTests();
				for (int j = 0; j < ttt.size(); j++)
				{
					cout << ttt[j].getName() << " - " << (i - 1) * ttt.size() + 1 + j << "\n";
				}
			}
			cout << string(50, '-') << "\n\n";

			cout << "Enter choice: ";
			cin >> cho;

			system("cls");
			for (int i = 0; i < testers.size(); i++)
			{
				for (int j = 0; j < testers[i].getResults().size(); j++)
				{
					if (testers[i].getResult(j).getTest() == tests[cho - 1].getName())
					{
						testers[i].getResult(j).print();
					}
				}
			}
			break;
		default:
			break;
		}


		break;
	case 13:
		system("cls");
		cout << string(50, '-') << "\n";
		cout << "Add rozdil   - 1\n";
		cout << "Add test     - 2\n";
		cout << "Add question - 3\n";
		cout << string(50, '-') << "\n\n";

		cout << "Enter choice: ";
		cin >> ch;

		system("cls");

		if (ch == 1) {

			rozdil r;
			r.setRozdil(questions, tests, rozdils);
			rozdils.push_back(r);

			for (int i = 0; i < rozdils.size(); i++)
			{
				rozdils[i].print();
			}

		}
		// -----------------
		if (ch == 2) {
			int rzd;
			system("cls");
			cout << string(30, '-') << "\n";
			for (int i = 1; i <= rozdils.size(); i++)
			{
				cout << rozdils[i - 1].getName() << " - " << i << "\n";
			}
			cout << string(30, '-') << "\n\n";
			cout << "Enter rozdil: ";
			cin >> rzd;

			test tt;
			tt.setTest(questions, tests);
			tests.push_back(tt);

			vector<test> vt = rozdils[rzd - 1].getTests();
			vt.push_back(tt);

			rozdil new_r(rozdils[rzd - 1].getName(), vt, vt.size());
			rozdils[rzd - 1] = new_r;
		}
		// -----------------
		if (ch == 3) {
			int cr;
			system("cls");
			cout << string(30, '-') << "\n";
			for (int i = 1; i <= rozdils.size(); i++)
			{
				cout << rozdils[i - 1].getName() << " - " << i << "\n";
			}
			cout << string(30, '-') << "\n\n";
			cout << "Enter rozdil: ";
			cin >> cr;
			int ct;
			system("cls");
			cout << string(30, '-') << "\n";

			for (int j = 1; j <= rozdils[cr - 1].getTests().size(); j++)
			{
				cout << rozdils[cr - 1].getTest(j - 1).getName() << " - " << j << "\n";
			}
			cout << string(30, '-') << "\n\n";
			cout << "Enter test: ";
			cin >> ct;

			question q;
			q.setQuestion(questions);

			test new_t = rozdils[cr - 1].getTest(ct - 1);
			new_t.getQuestions().push_back(q);

			rozdils[cr - 1].getTest(ct - 1) = new_t;
		}



		break;
	default:
		break;
	}


}



int main() {
	srand(time(0));


	// Create tester
	vector<tester> testers;
	map<string, string> tester_log;
	tester active_tester;


	// Create admin
	string admin_login;
	string admin_password;


	// Create questions
	vector<question> questions;

	// Create test
	vector<test> tests;

	// Create rozdil
	vector<rozdil> rozdils;
	readRozdil(questions, tests, rozdils);


	// Testers reading from file
	testersReadingFromFile(testers, tester_log);



	// Menu
	menu(testers, tester_log, active_tester, rozdils, tests, questions);









	return 0;
}