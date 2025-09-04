#include <stdio.h>


int Strlen(char *str);
int main(){

char str[] = "Hello";
Strlen(*str);

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