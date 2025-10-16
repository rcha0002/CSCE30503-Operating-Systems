#include <stdio.h>

#define SIZE 1024

int Strlen(char *str);
int main(){

char str[SIZE] = "Hello";
int len;

len = Strlen(str);
printf("%s: %d\n" , str , len);

return 0;
}


int Strlen(char *str){
    int count = 0;
    while(*str != '\0'){
        count++;
        str++;
    }
    return count;
}