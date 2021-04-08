#include<iostream>
#include<fstream>
using namespace std;


// Takes input from console and writes that in file "output1.txt"
int main()
{
	ofstream fout("output1.txt");
	string s;
	cout<<"Enter the data in following format:\n";
	cout<<"Transaction ID Transactions (Separated by spaces)\n";
	cout<<"Enter -1 in new line to end input\n";
	while(true)
	{
		getline(cin, s);
		if(s == "-1") break;
		fout<<s<<endl;
	}
	fout.close();
	return 0;
}
