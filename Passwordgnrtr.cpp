#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;


string generatepassword(int length, bool use_uppercase, bool use_lowercase,bool use_digits,bool use_symbols  )
{
	string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string lower_case = "abcdefghijklmnopqrstuvwxyz";
	string digits = "0123456789";
	string symbols = "!@#$%^&*()-_=+[]{}|;:,.<>?";

	string char_pool;

	if(use_uppercase) {
		char_pool+=upper_case;

	}
	if(use_lowercase) {
		char_pool+=lower_case;

	}
	if(use_digits) {
		char_pool+=digits;

	}
	if(use_symbols) {
		char_pool+=symbols;

	}
	if (char_pool.empty()) {
		throw invalid_argument("At least one character type must be enabled!");
	}

	string password;

	for(int i=0; i<length; i++) {
		password+=char_pool[rand()%char_pool.length()];
	}

	return password;

}

int main() {

	srand(time(0));
	cout<<"Welcome to password generator!!"<<endl;
	int length;
	char uppercase,lowercase,digits,symbols;


	cout<<"Enter the length of password"<<endl ;
	cin>>length;



	cout<<"Include uppercase letter?(y /n): " ;
	cin>>uppercase;

	cout<<"Include lowercase letter?(y /n): " ;
	cin>>lowercase;

	cout<<"Include digits?(y /n): " ;
	cin>>digits;

	cout<<"Include symbols?(y /n): " ;
	cin>>symbols;

	try {
		bool use_uppercase=(uppercase=='y'||uppercase=='Y');
		bool use_lowercase=(lowercase=='y'||lowercase=='Y');
		bool use_digits=(digits=='y'||digits=='Y');
		bool use_symbols=(symbols=='y'||symbols=='Y');

		string password=generatepassword( length, use_uppercase,  use_lowercase, use_digits,use_symbols   ) ;


		cout << "Generated Password: " << password << endl;
	}
	catch (const invalid_argument& e) {
		cout << "Error: " << e.what() << endl;
	}

	return 0;

}


