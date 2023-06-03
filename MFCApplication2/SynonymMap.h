#pragma once
#include <vector>
#include <cstring>
#include <random>

class SynonymMap
{
private:
	std::random_device dev;
	CStringArray words;
	std::vector<int> indexes;

private:
	int findWord(CString word);
public:
	SynonymMap();
	~SynonymMap();
	
	void clear();
	CString getRndSynonym(CString word);
	void addSynonym(CString word);
	void addMainWord(CString word);
	bool isEmpty();

};

