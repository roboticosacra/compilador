/*

Construção de um analizador lexico que reconhece identificadores, literais numericas
e strings e comentarios.

Alunos: Hugo Santos Dias
        Jeane Durval

Obs: compilado e testado no devc++ 4.9.9.2 rodando o gcc 3.4.2 e  no gcc 3.4.4 no FreeBSD

Saidas esperadas:

       automato.exe
       Entre com os dados
       123455
       numeros

       automato.exe
       Entre com os dados
       12abc
       literais numericos

       automato.exe
       Entre com os dados
       abcdf
       caracteres

       automato.exe
       Entre com os dados
       (** comentarios **)
       comentarios



Este código é de livre distribuição e uso.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

char olhar; /* O caracter lido "antecipadamente" (olha adiante) */


/* protótipos */
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

/* inicialização do compilador */
void init()
{
	proximoChar();
}

/* lê próximo caracter da entrada */
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

/* recebe um número inteiro */
char getNum()
{
	char num;

	if (!edigito(olhar))
		expected("Integer");
	num = olhar;
	proximoChar();

	return num;
}

/* emite uma instrução seguida por uma nova linha */
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


//chamada do aumtomato
void Àr
