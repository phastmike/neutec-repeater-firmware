#include <stdio.h>


void main(void) {
   char *t;
   char text[] = " CQ0UGMR IN51UK\0";

   printf("*******************************\n");
   printf("TEXT = %s\n", text);
   printf("*******************************\n");

   for (t = text; *t != '\0'; t++) {
      printf("%c", *t);
   }

   printf("\n");
}
