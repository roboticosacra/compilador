#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

//teste de mudança de arquivo

char olhar; /* O caracter lido "antecipadamente" (olha adiante) */


/* prot�tipos */
void init();
void proximoChar();
void error(char *fmt, ...);
void fatal(char *fmt, ...);
void expected(char *fmt, ...);
void match(char c);
void expression();

void automato();
//void literal();

char getNome();
char getNum();
void emit(char *fmt, ...);


/* PROGRAMA PRINCIPAL */
int main()
{
	printf ("Entre com os dados \n");

	init();
    automato();
	return 0;
}

/* inicializa��o do compilador */
void init()
{
	proximoChar();
}

/* l� pr�ximo caracter da entrada */
void proximoChar()
{
	olhar = getchar();
}

/* exibe uma mensagem de erro formatada */
void error(char *fmt, ...)
{
	va_list args;

	fputs("Error: ", stderr);

   	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);

	fputc('\n', stderr);
}

/* exibe uma mensagem de erro formatada e sai */
void fatal(char *fmt, ...)
{
	va_list args;

	fputs("Error: ", stderr);

	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);

	fputc('\n', stderr);

	exit(1);
}

/* alerta sobre alguma entrada esperada */
void expected(char *fmt, ...)
{
	va_list args;

	fputs("Error: ", stderr);

	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);

	fputs(" expected!\n", stderr);

	exit(1);
}



/* verifica se entrada combina com o esperado */
void match(char c)
{
	if (olhar != c)
		expected("'%c'", c);
	proximoChar();
}

/* recebe o nome de um identificador */
char getNome()
{
	char name;

	if (!isalpha(olhar))
		expected("Name");
	name = toupper(olhar);
	proximoChar();

	return name;
}

/* recebe um n�mero inteiro */
char getNum()
{
	char num;

	if (!edigito(olhar))
		expected("Integer");
	num = olhar;
	proximoChar();

	return num;
}

/* emite uma instru��o seguida por uma nova linha */
void emit(char *fmt, ...)
{
	va_list args;

	putchar('\t');

	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);

	putchar('\n');
}


//ideia do analizador de bruno usada para literais + numeros
int letra (char letra)
{
  if ((letra>='a')&&(letra<='z')||(letra>='A')&&(letra<='Z'))
  return 1;
  else return 0;
}

int i=1; //primeiro estado do automato

