#include <stdio.h>

void printJapanese(int num)
{
  const char *ones[] = {"", "ichi", "ni", "san", "yon", "go", "roku", "nana", "hachi", "kyuu"};
  const char *tens[] = {"", "jyuu", "nijyuu", "sanjyuu", "yonjyuu", "gojyuu", "rokujyuu", "nanajyuu", "hachijyuu", "kyuujyuu"};
  const char *hundreds[] = {"", "hyaku", "nihyaku", "sanbyaku", "yonhyaku", "gohyaku", "roppyaku", "nanahyaku", "happyaku", "kuuhyaku"};
  const char *thousands[] = {"", "sen", "nisen", "sanzen", "yonsen", "rokusen", "nanasen", "hassen", "kyuusen"};

  int one = num % 10;
  int ten = (num / 10) % 10;
  int hundred = (num / 100) % 10;
  int thousand = (num / 1000) % 10;

  if (thousand > 0)
  {
    printf("%s ", thousands[thousand]);
  }
  if (hundred > 0)
  {
    printf("%s ", hundreds[hundred]);
  }
  if (ten > 0)
  {
    printf("%s ", tens[ten]);
  }
  if (one > 0)
  {
    printf("%s ", ones[one]);
  }
  printf("\n");
}

int main(void)
{

  printf("This program will count in Japanese from 1 to 9999.\n");

   for (int i = 1; i <= 9999; i++)
   {
     printJapanese(i);
   }
  
  return 0;
}
