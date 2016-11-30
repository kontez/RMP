#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
// include library of our headers => stringsort.h


// move functions to stringsort.c
void PrintStringliste(char **stringliste){
  for (; strncmp(*stringliste,"",1); ++stringliste) {
    puts(*stringliste);
  }
}

unsigned getNum(char *string) {
  // sscanf sucks for many reasons, but it's still useful for this kind of tasks.
  unsigned ret;
  // `*` ignores a given specification
  sscanf(string, "%*s %u EUR", &ret);
  return ret;
}

// Bubble Sort
void SortiereStrings(char **stringliste){
  if (!*stringliste) {
    return; // if empty, return
  }

  bool swapped;

  do {
    swapped = false;
    char **base = stringliste;
    // if the next item is not the end of the array, then do an iteration
    for (; strncmp(*(base + 1),"",1); ++base) {
      if (getNum(*base) > getNum(*(base+1))) {
        char *tmp = *base;
        *base = *(base + 1);
        *(base + 1) = tmp;

        swapped = true;
      }
    }
  } while (swapped);
}

int main(void) {
  char *pMeineStrings[] = {
    "Haller       25 EUR",
    "Kandinsky    13 EUR",
    "Brombach      5 EUR",
    "Zaluskowski 120 EUR",
    "Osman        17 EUR",
    ""
//    NULL // if you put a NULL here, you can iterate on this pointer with a simple ++
  };

  puts("before: ");
  PrintStringliste(pMeineStrings);
  SortiereStrings(pMeineStrings);
  puts("\nafter:");
  PrintStringliste(pMeineStrings);
  return EXIT_SUCCESS;
}
