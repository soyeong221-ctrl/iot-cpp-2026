#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <string>
#include <iostream>
using namespace std;

class Tokenizer {
private:
	string target;
	string delimiters;
	int begin;
	int end;
public:
	Tokenizer(const string& target, const string& delimiters);
	bool hasNextToken();
	string nextToken();
	~Tokenizer();
};

#endif
