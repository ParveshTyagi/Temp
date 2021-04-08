#include<fstream>
#include<vector>
#include<map>
#include<set>
using namespace std;

// Splits the input line into atomic strings of transaction and itemsets
vector<string> splitter(string s)
{
	vector<string> input;
	int n = s.length();
	int i=0, j=0;
	set<string> check;
	while(j < n)
	{
		while(i< n && s[i]==' ') i++;
		j = i;
		if(i == n) break;
		while(j<n && s[j]!=' ') j++;
		string x = s.substr(i, j-i);
		if(check.find(x) == check.end())
		{
			input.push_back(x);
			check.insert(x);
		}
		i = j;
	}
	return input;
}

// Map the itemset to the transactions in which it was included.
// Example: a: T1, T2, T4 etc.
map<string, vector<string>> MapMaker(vector<vector<string>>& input)
{
	map<string, vector<string>> mp;
	for(auto a: input)
	{
		for(int i=1; i<a.size(); i++)
		{
			mp[a[i]].push_back(a[0]);
		}
	}
	return mp;
}

//Writes the itemset and transaction it was included in, into file "output4.txt".
void solution(vector<vector<string>>& input)
{
	auto mapped_data = MapMaker(input);
	ofstream fout("output4.txt");
	for(auto i: mapped_data)
	{
		fout<<i.first<<": ";
		for(string s: i.second) fout<<s<<" ";
		fout<<"\n";
	}
	fout.close();
}

//Reads the input from "input4.txt" and prepares it for further processing.
int main()
{
	fstream fin("input4.txt");
	vector<vector<string>> input;
	while(!fin.eof())
	{
		string s;
		getline(fin, s);
		auto line = splitter(s);
		input.push_back(line);
	}
	fin.close();
	solution(input);
	return 0;
}
