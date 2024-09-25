#include <stdio.h>

void printJapanese (int num) {
  const char *ones[] = {"","ichi","ni","san","yon","go","roku","nana","hachi", "kyuu"};
  const char *tens[] = {"","jyuu", "nijyuu", "sanjyuu", "yonjyuu", "gojyuu", "rokujyuu", "nanajyuu","hachijyuu","kyuujyuu"};
  const char *hundreds[] = {"","hyaku", "nihyaku", "sanbyaku", "yonhyaku", "gohyaku", "roppyaku", "nanahyaku", "happyaku", "kuuhyaku"};
  const char *thousands[] = {"","sen", "nisen", "sanzen","yonsen", "rokusen","nanasen","hassen", "kyuusen"};

  int one = num % 10;

  printf("%d\n", num);
}


int main(void)
{




  printf("This program will count in Japanese from 1 to 9999.\n");

  

    //for (int i = 0; i <= 9999; i++)
    //{
    //    printf("Hell World!\n");
    //}
    
    return 0;
}
