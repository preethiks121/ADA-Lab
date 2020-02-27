%{
#include<string.h>
#include<stdio.h>
int v =0, c=0,i=0;
char a[100][100];
%}
%%
[aeiou]		{v++;}
[bcdfghjklmnpqrstvwxyz]		{c++;	
				strcpy(a[i],yytext); 
				i++;
			}
%%
int main()
{
	int k;
	printf("Enter a string:\n");
	yylex();
	printf("Vowels = %d consonants = %d\n",v,c);
	for(k=0;k<c;k++)
		printf("%s",a[k]);
	return 0;
}
int yywrap(void){}
