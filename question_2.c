#include <stdio.h>
#include <stdlib.h>
#include "adt/stack.h"

typedef struct
{
  char chr;
  int line, column;
} Token;

Token *new_token(char chr, int line, int column)
{
  Token *token = (Token *)malloc(sizeof(Token));

  token->chr = chr;
  token->line = line;
  token->column = column;
}

int in_lexer(char token, char option)
{
  switch (option)
  {
  case 'A':
    return in_lexer(token, 'O') || in_lexer(token, 'C');
  case 'O':
    return token == '{' || token == '[' || token == '(';
  case 'C':
    return token == '}' || token == ']' || token == ')';
  }
}

char get_close(char open)
{
  if (open == '[')
    return ']';
  if (open == '{')
    return '}';
  if (open == '(')
    return ')';
  exit(1);
}

void printErr(Token *token, char type)
{
  if (type == 'O')
  {
    printf("Miss open %c, line %i, column %i\n", token->chr, token->line, token->column);
  }
  else if (type == 'C')
  {
    printf("Miss close %c, line %i, column %i\n", token->chr, token->line, token->column);
  }
}

int parse(char *filename, Stack *open)
{
  FILE *file;
  char chr;
  Token *in_stack, *new;
  int lines = 1, column = 1;

  file = fopen(filename, "r");
  if (!file)
  {
    printf("An error ocurred while opening file");
    exit(1);
  }

  while (fscanf(file, "%c", &chr) != EOF)
  {
    if (in_lexer(chr, 'A'))
    {
      new = new_token(chr, lines, column);
      if (in_lexer(chr, 'O'))
      {
        push_stack(open, new);
      }
      else
      {
        in_stack = ((Token *)pop_stack(open));
        if (!(get_close(in_stack->chr) == chr))
        {
          printErr(in_stack, 'C');
          printErr(new, 'O');
          return -1;
        }
      }
    }

    column++;
    if (chr == '\n')
    {
      lines++;
      column = 1;
    }
  }

  return lines;
}

int main()
{
  char filename[20];
  Stack *open = new_stack();
  int total_lines;

  // printf("type filename: ");
  // scanf(" %[^\n]20s", filename);
  total_lines = parse("teste.txt", open);
  if (total_lines != -1)
  {
    printf("Sucess, %i lines parsed", total_lines);
  }
  return 0;
}