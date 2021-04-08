#include<iostream>
#include<fstream>
using namespace std;

// Reads data from file "input2.txt" and print it on console.
int main()
{
	fstream fin("input2.txt");
	while(!fin.eof())
	{
		string s;
		getline(fin, s);
		cout<<s<<endl;
	}
	fin.close();
	return 0;
}
