#include "pch.h"
#include "SynonymMap.h"
#include <random>

int SynonymMap::findWord(CString word)
{
	for (auto it = indexes.begin(); it != indexes.end(); ++it) {
		int wtf = words.GetAt(*it).Compare(word);

		CString suka = CString(words.GetAt(*it));
		CString blyat = CString(word);
		//костыль по причине Compare не работает
		int sukasuka = suka.GetLength();
		int blyatsuka = blyat.GetLength();
		bool compare = true;
		for (int i = 0; i < suka.GetLength() && i < blyat.GetLength() ; i++) {
			char sukachar = suka[i];
			char blyachar = blyat[i];
			if (suka[i] != blyat[i]) {
				compare = false;
			}
		}

		int wtf2 = suka.Compare(blyat);
		
		if(compare) {
			return std::distance(indexes.begin(), it);
		}
	}
	return -1;
}

SynonymMap::SynonymMap()
{
}

SynonymMap::~SynonymMap()
{
	
	indexes.erase(indexes.begin(), indexes.end());
}

void SynonymMap::clear()
{
	indexes.clear();
}

CString SynonymMap::getRndSynonym(CString word)
{
	int index = findWord(word);
	if (index < 0) {
		return word;
	}

	
	std::mt19937 gen(dev());
	
	
	int firstIndex = indexes[index];
	if (firstIndex == words.GetSize() - 1) {
		return word;
	}
	else {
		firstIndex++;
	}
	int lastIndex;
	
	
	if (index == indexes.size()) {
		lastIndex = words.GetSize() - 1;
	}
	else {
		lastIndex = indexes[index + 1] - 1;
	}
	if (lastIndex - firstIndex < 1) {
		return word;
	}

	
	std::uniform_int_distribution<> dist(firstIndex, lastIndex);
	CString res = words[dist(gen)];
	return res;
}

void SynonymMap::addSynonym(CString word)
{
	words.Add(word);
}

void SynonymMap::addMainWord(CString word)
{
	indexes.push_back(words.GetSize());
	words.Add(word);
}

bool SynonymMap::isEmpty()
{
	return !(words.GetSize() > 0);
}
