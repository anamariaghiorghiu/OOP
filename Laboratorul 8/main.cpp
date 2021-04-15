#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

void read_string(string message, string &s)
{
	cout << message;
	getline(cin, s);
}

void read_string_from_file(string file_name, string& s)
{
	ifstream fin;
	char c;
	s.clear();
	fin.open(file_name);
	while (fin.get(c))
		s.push_back(c);
	fin.close();
}

void create_word_map(string text, map<string,int> &word_map)
{
	string word;
	string separators = " ,.?!\n";
	bool is_separator;
	int i;
	i = 0;
	word_map.clear();
	while (i < text.length())
		if (separators.find(text[i]) != string::npos)
			i++;
		else
		{
			word.clear();
			is_separator = false;
			while (!is_separator && i < text.length())
				if (separators.find(text[i]) == string::npos)
				{
					if (text[i] >= 'A' && text[i] <= 'Z')
						text[i] = 'a' + text[i] - 'A';
					word += text[i];
					i++;
				}
				else
					is_separator = true;
			word_map[word]++;
		}
	/*
	for(map<string, int>::const_iterator i = word_map.begin(); i != word_map.end(); i++)
		cout << i->first << " " << i->second << "\n";
	*/
}

bool less_than(pair<string, int> p1, pair<string, int> p2)
{
	if (p1.second < p2.second)
		return true;
	else
		if (p1.second == p2.second)
			if (p1.first.compare(p2.first) > 0)
				return true;
			else
				return false;
		else
			return false;
}

void print_in_order(map<string,int> word_map)
{
	map<string, int>::const_iterator i;
	pair<string, int> p;
	priority_queue<pair<string, int>, vector<pair<string, int>>,
		function<bool(pair<string, int>, pair<string, int>)>> pq(less_than);
	for (i = word_map.begin(); i != word_map.end(); i++)
	{
		p.first = i->first;
		p.second = i->second;
		pq.push(p);
	}
	while (!pq.empty())
	{
		p = pq.top();
		cout << p.first << " => " << p.second << endl;
		pq.pop();
	}
}

int main()
{
	string file_name;
	string text;
	map<string, int> word_map;
	read_string("Name of the text file:", file_name);
	read_string_from_file(file_name, text);
	create_word_map(text, word_map);
	print_in_order(word_map);
	return 0;
}