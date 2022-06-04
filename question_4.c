#include <stdio.h>
#include <stdlib.h>
#include "adt/queue.h"

typedef struct
{
  char letter;
  Queue *queue;
} Category;

void print_word(char *word)
{
  printf("%s\n", word);
}

int get_index(int ascii_char)
{
  if (ascii_char >= 65 && ascii_char <= 90)
  {

    return ascii_char - 65;
  }
  else if (ascii_char >= 97 && ascii_char <= 122)
  {
    return ascii_char - 97 + 26;
  }
  {
    return 52;
  }
}

void split_words(char *filename, Category *category_arr)
{
  int index;
  FILE *file;
  char *word;

  file = fopen(filename, "r");
  if (!file)
  {
    printf("An error ocurred while opening file");
    exit(1);
  }

  word = (char *)malloc(sizeof(char) * 50);
  while (fscanf(file, "%s", word) != EOF)
  {
    index = get_index(word[0]);
    if (!category_arr[index].queue)
    {
      category_arr[index].queue = create_queue();
      category_arr[index].letter = index < 52 ? word[0] : '#';
    }

    enqueue(category_arr[index].queue, word);

    word = (char *)malloc(sizeof(char) * 50);
  }

  free(word);
}

int main()
{
  Category *category_arr;
  int i;

  category_arr = (Category *)calloc(53, sizeof(Category));

  //  printf("Type filename: ");
  //  scanf(" %[^\n]20s", filename);
  split_words("words.txt", category_arr);

  for (i = 0; i < 53; i++)
  {
    if (!category_arr[i].queue)
      continue;
    printf("\nPrinting category \"%c\"\n", category_arr[i].letter);
    queue_for_each(category_arr[i].queue, (void *)&print_word);
  }

  return 0;
}