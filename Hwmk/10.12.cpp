// Kendall Small	03/04/15 10:00

#include<iostream>
#include<cstring>
#include<string>
using namespace std;

bool charLen(string pass, int size);
bool up(string pass, int size);
bool low(string pass, int size);
bool dig(string pass, int size);

int main()
{
	string passWrd;
	int size, length, upper, lower, digit;
	
	cout<<"This is a password verifier."
		<<"Your password must contain the following: \n"
		<<"-It must be at least 6 characters long\n"
		<<"It must contain at least one uppercase letter\n"
		<<"It must contain at least two lowercase letters\n"
		<<"It must contain at least one digit\n"
		<<"Please enter your password: \n";
	
	getline(cin, passWrd);
	size = passWrd.size();
	
	length = charLen(passWrd, size);
	upper = up(passWrd, size);
	lower = low(passWrd, size);
	digit = dig(passWrd, size);
	
	if(length == 1 && upper == 1 && lower == 1 && digit == 1)
		cout<<"\nCongratulations! Your password is valid!\n";
		
	else
	{
		cout<<"\nError! Your password is invalid.\n"
			<<"Here's what you did wrong: \n";
			
		if(length == 0)
			cout<<"Your password was not at least 6 characters long.\n";
			
		if(upper == 0)
			cout<<"Your password did not contain at least one uppercase letter.\n";
			
		if(lower == 0)
			cout<<"Your password did not contain at least two lowercase letters.\n";
			
		if(digit == 0)
			cout<<"Your password did not contain at least one digit.\n";
	}
	
	system("PAUSE");
	return 0;		
		
}


bool charLen(string pass, int size)
{
	bool length;
	int letter=0;
	
	for(int i=0; i<size;i++){
		if(isalpha(pass.at(i)))
		{
			letter++;
			if(letter == 6)
				return length = true;
		}
	}
	return length = false;
}

bool up(string pass, int size)
{
	bool upper;
	for(int i=0; i<size;i++){
		if(isupper(pass.at(i)))
		{
			return upper = true;
		}
	}
	return upper = false;
}

bool low(string pass, int size)
{
	bool lower;
	int low =0;
	for(int i=0; i<size;i++){
		if(islower(pass.at(i)))
		{
			low++;
			if(low==2)
				return lower = true;
		}
	}
	return lower = false;
}


bool dig(string pass, int size)
{
	bool digit;
	for(int i=0; i<size;i++){
		if(isdigit(pass.at(i)))
		{
			return digit = true;
		}
	}
	return digit = false;
}
