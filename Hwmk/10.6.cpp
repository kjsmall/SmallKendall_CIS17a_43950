// Kendall Small	02/04/15 15:03


#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int vowels(char *,int);
int cnsnts(char *, int);

int main()
{
	char cstring[100];
	char select;
	int size;
	
	cout<<"Hello! Welcome to my word counting program.\n";
	cout<<"Please input a string: \n";
	cin.get(cstring, 100);
	
	size = strlen(cstring);
	char *pointer=cstring;
	
	do
	{
		cout<<"\nPlease select an option: \n"
			<<"A) Count the number of vowels in the string\n"
			<<"B) Count the number of consonants in the string\n"
			<<"C) Count both the vowels and consonants in the string\n"
			<<"D) Enter another string\n"
			<<"E) Exit the program\n";
		cin>>select;
		cout<<endl;
		while(toupper(select) < 'A' || toupper(select) > 'E'){
			cout<<"Wrong! Please select a valid option: \n";
			cin>>select;}
			
		if(toupper(select) == 'A')
		{
			cout<<"The string contains "<<vowels(pointer, size)<<" vowels.\n";
		}
		
		else if(toupper(select) == 'B')
		{
			cout<<"The string contains "<<cnsnts(pointer, size)<<" consonants.\n";
		}
		
		else if(toupper(select) == 'C')
		{
			cout<<"The string contains "<<cnsnts(pointer, size)<<" consonants.\n";
			cout<<"The string contains "<<vowels(pointer, size)<<" vowels.\n";
		}
		
		else if(toupper(select) == 'D')
		{
			cout<<"Please enter your new string: \n";
			cin.ignore();
			cin.get(pointer, 100);
			size = strlen(pointer);		
		}
		
		else if(toupper(select) == 'E')
		{
			cout<<"Exit! Bye!\n";
		}
		
		
		
	}while(toupper(select) != 'E');
	
	system("PAUSE");
	return 0;
}

int vowels(char *pointer, int size)
{
	int count;
	for(int i=0; i<size;i++){
		if(toupper(pointer[i]) == 'A' || toupper(pointer[i]) == 'E' || toupper(pointer[i]) == 'I' || toupper(pointer[i]) == 'O' || toupper(pointer[i]) == 'U')
			count++;
			
	}
			
	return count;
}

int cnsnts(char *pointer, int size)
{
	int count = size;
	for(int i=0;i<size;i++){
		if(toupper(pointer[i]) == 'A' || toupper(pointer[i]) == 'E' || toupper(pointer[i]) == 'I' || toupper(pointer[i]) == 'O' ||  toupper(pointer[i]) == 'U' || toupper(isspace(pointer[i])))
			count--;
		
	}
	return count;
}
