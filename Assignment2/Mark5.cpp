#include<iostream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
using namespace std;

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

void combinationMaker(vector<string>& line, map<string,int>& mp, string s, int i=1)
{
	if(i == line.size())
	{
		if(s != "")
		mp[s]++;
		return;
	}
	combinationMaker(line, mp, s, i+1);
	combinationMaker(line, mp, s+line[i], i+1);
}

map<string, int> mapMaker(vector<vector<string>>& input)
{
	map<string,int> mp;
	for(int i=0; i<input.size(); i++)
	{
		combinationMaker(input[i], mp, "");
	}
	return mp;
}

void write(map<string,int>& mp)
{
	ofstream fout("output5.txt");
	for(auto i: mp)
	{
		if(i.second >= 2)
		fout<<i.first<<", ";
	}
	fout.close();
}

void solution(vector<vector<string>>& input)
{
	auto mp = mapMaker(input);
	write(mp);
}

int main()
{
	ifstream fin("input5.txt");
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
}
