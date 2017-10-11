#include <stdio.h> //못풀겠당
#include <stdlib.h>

int input();

int main()
{
	int row, column;
	row = input();
	column = input();



}

int input()
{
	char in[1000];
	fgets(in, 999, stdin);
	return atoi(in);
}
