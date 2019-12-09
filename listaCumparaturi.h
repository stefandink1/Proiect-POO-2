#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class listaCumparaturi
{
	string numeLista;
	vector<pair<string, float>> produse;
public:
	listaCumparaturi();
	listaCumparaturi(string nume, vector<pair<string, float>> l);
	listaCumparaturi(vector<pair<string, float>> l);
	listaCumparaturi(const listaCumparaturi& l);
	listaCumparaturi(string l);
	~listaCumparaturi();

	string getName();
	vector<pair<string, float>> getList();
	void setList(vector<pair<string, float>>);

	friend ostream & operator << (ostream &out, const listaCumparaturi &l);
	friend istream & operator >> (istream &in, listaCumparaturi &l);
};

