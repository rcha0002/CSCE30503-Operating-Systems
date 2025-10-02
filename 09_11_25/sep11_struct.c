#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 64

//Structs work similarly to linked lists 
struct student{
    int id;
    char fName[SIZE];
    char lName[SIZE];

};
typedef struct student Stu;

//Size of the ^ Struct is 64 + 64 (SIZE + SIZE) + 4 (int bytes) = 132 bytes allocated for Struct.
//Function prototypes must be declared after Structs
void showStu(struct student stu);
void showStuRef(struct student *stu);

int main(){
    Stu stu1;
    stu1.id = 1001;
    strcpy(stu1.lName, "Jones");
    strcpy(stu1.fName, "Joe");

    Stu *stu2;
    stu2 = malloc(sizeof(struct student));
    //malloc = memory allocate
    stu2-> id = 1002;
    strcpy(stu2->lName, "Jon");
    strcpy(stu2->fName, "John");

    showStu(stu1);
    printf("\n");
    showStuRef(&stu1);
    printf("\n");
    showStuRef(stu2);
    free(stu2);

    return 0;
}


//function copies contents of stu1 down instead of referencing stu1. Allocates another 132 bytes.
void showStu(struct student stu){
    printf("ID: %d\n" , stu.id);
    printf("First: %s\n" , stu.fName);
    printf("Last: %s\n" , stu.lName);
    printf("Size: %d\n" , sizeof(stu));

}

//This function will pass by reference
void showStuRef(struct student *stu){
    printf("ID: %d\n" , stu->id);
    printf("First: %s\n" , stu->fName);
    printf("Last: %s\n" , stu->lName);
    printf("Size: %d\n" , sizeof(stu));

}