//Run using gcc on shell
%{
int count = 0;
%}

%%
[A-Z] {printf("%s capital letter\n", yytext);
	count++;}
.	 {printf("%s not a capital letter\n", yytext);}
\n {return 0;}
%%

int yywrap(){}
int main(){

char filename[50];
printf("Enter the filename: \n");
scanf("%s",filename);
fp = fopen(filename,"r");
yyin = fp;

yylex();
//Checking the number of capital letters in a file
printf("\nNumber of Capital letters in the given input - %d\n", count);

return 0;
}
