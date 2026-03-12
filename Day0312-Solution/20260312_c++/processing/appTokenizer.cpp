#include "tokenizer.h"
int main()
{
	string str = "Passion is genesis of genius. - Galilleo Galilei";
	string delimiters = " \n"; // 공백과 줄바꿈을 구분자로 지정
	Tokenizer tokenizer(str, delimiters);

	while (tokenizer.hasNextToken())
	{
		cout << tokenizer.nextToken() << endl;
	}
	return 0;
}