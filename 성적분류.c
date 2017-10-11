#include<stdio.h>
void main()
{
	int score;
	scanf("%i", &score);
	if (90 <= score) {
		puts("A");
	}
	else if(80<=score){
		puts("B");
	}
	else if (70 <= score) {
		puts("C");
	}
	else if (60 <= score) {
		puts("D");
	}
	else {
		puts("F");
	}
}