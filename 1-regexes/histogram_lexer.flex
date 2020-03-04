%option noyywrap

%{
#include "histogram.hpp"



// This is to work around an irritating bug in Flex
// https://stackoverflow.com/questions/46213840/get-rid-of-warning-implicit-declaration-of-function-fileno-in-flex
extern "C" int fileno(FILE *stream);

/* End the embedded code section. */
%}


/*定义部分*/ 
SPACE       [ \n\t\v\f\r]
INT         "int"
MAIN        "main"
VOID        "void"
RETURN      "return"
IF          "if"
ID          [_a-zA-Z][0-9_a-zA-Z]*

%%

{SPACE}     {return Space;}
{INT}       {return Int;}
{MAIN}      {return Main;}
{VOID}      {return Void;}
{RETURN}    {return Return;}
{IF}        {return If;}
{ID}        {return Id;}


%%

/* Error handler. This will get called if none of the rules match. */
void yyerror (char const *s)
{
  fprintf (stderr, "Flex Error: %s\n", s); /* s is the text that wasn't matched */
  exit(1);
}
