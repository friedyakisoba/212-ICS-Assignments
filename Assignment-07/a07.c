// Hans Cacalda
// September 23 2024
// Purpose: Prints out the japanese roomaji from 1 to 9999 using characters stored in an array.

// input/output header
#include <stdio.h>


// using void as it does not need to return any values
void printJapanese(int num)
{
  // Arrays to store the japanese words for ones, tens, hundreds, and defense respectively
  const char *ones[] = {"", "ichi", "ni", "san", "yon", "go", "roku", "nana", "hachi", "kyuu"};
  const char *tens[] = {"", "jyuu", "nijyuu", "sanjyuu", "yonjyuu", "gojyuu", "rokujyuu", "nanajyuu", "hachijyuu", "kyuujyuu"};
  const char *hundreds[] = {"", "hyaku", "nihyaku", "sanbyaku", "yonhyaku", "gohyaku", "roppyaku", "nanahyaku", "happyaku", "kuuhyaku"};
  const char *thousands[] = {"", "sen", "nisen", "sanzen", "yonsen", "rokusen", "nanasen", "hassen", "kyuusen"};

  // Initializing variables to store digits respectively.
  int one = num % 10;
  int ten = (num / 10) % 10;
  int hundred = (num / 100) % 10;
  int thousand = (num / 1000) % 10;

  /* note to self: thousands goes first as it is checked and printed first even though it is calculated last

  ex: 100,000
  if (hundredThousand)...so on
   */
  // Prints the thousands number if it is corresponding
  if (thousand > 0)
  {
    // thousands[thousand] = looks into the array which 'thousand' roomaji to use
    printf("%s ", thousands[thousand]);
  }
  // Prints the hundreds number if it is corresponding
  if (hundred > 0)
  {
    // hundreds[hundred] = looks into the array which 'hundred' roomaji to use
    printf("%s ", hundreds[hundred]);
  }
  // Prints the tens number if it is corresponding
  if (ten > 0)
  {
    // tens[ten] = looks into the array which 'tens' roomaji to use
    printf("%s ", tens[ten]);
  }
  // Prints the ones number if it is corresponding
  if (one > 0)
  {
    // ones[one] = looks into the array which 'one' roomaji to use
    printf("%s ", ones[one]);
  }

  // Print a newline after each number
  printf("\n");
}


int main(void)
{
  // Prompts the user what the program will do.
  printf("This program will count in Japanese from 1 to 9999.\n");

  // For loop that print their Japanese representation from 1 - 9999
  for (int i = 1; i <= 9999; i++)
  {
    // Function call
    // i is the number to figure out what number is needed to print
    printJapanese(i);
  }

  // returns here if successful
  return 0;
}
