#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
Variables in C
*/
/*
int main(){
    char character[] = "Greg";
    char character2[] = "Ethan";
    int age = 21;
    int age2 = 22;

    printf("%s and %s are %d and %d years old.\n", character, character2, age, age2);

    printf("%s will get %.2f%% in %s %d\n", "Gregory", 99.9, "COM SCI", 327);
    return 0;
}
*/

/*
Data Types in C
*/
/*
int main(){
    
    int age = 40;
    double gpa = 3.7;
    char grade = 'A';
    char phrase[] = "Gregory";
    return 0;
}
*/

/*
Getting User Input double
*/
/*
int main() {

    double gpa;
    printf("Enter you gpa: ");
    scanf("%lf", &gpa);
    printf("Your gpa is: %.2f\n", gpa);
    
    return 0;
}
*/

/*
Getting User Input digit
*/
/*
int main() {
    
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Your age is: %d\n", age);
    return 0;
}
*/

/*
Getting User Input character
*/
/*
int main() {
    char grade;
    printf("What is you letter grade: ");
    scanf("%c", &grade);
    printf("You letter grade is: %c\n", grade);
    return 0;
}
*/

/*
Getting User Input string
*/
/*
int main() {
    char name[20];
    printf("What is your name?: ");
    scanf("%s", name);
    printf("Your name is: %s\n", name);
    return 0;
}
*/

/*
Getting User Input string but with spaces using fgets
*/
/*
int main() {
    char name[30];
    printf("What is your name?: ");
    fgets(name, 30, stdin);
    printf("Your name is: %s\n", name);
    return 0;
}
*/

/*
Calculator add 2 numbers together
*/
/*
int main() {
    double num1;
    double num2;
    printf("This program will add 2 of your numbers together.\n");
    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the second number: ");
    scanf("%lf", &num2);
    double result = num1 + num2;
    printf("The sum of you two numbers is: %.2f\n", result);

    // printf("Result: %d\n", num1 + num2);

    return 0;
}
*/

/*
int main() {
    char name[30];
    char college[30];
    char city[10];

    printf("What is your name?: ");
    fgets(name, 30, stdin);

    printf("Where do you go to college: ");
    fgets(college, 30, stdin);

    printf("In what city your located?: ");
    scanf("%s", city);

    printf("Your name is: %s\n", name);
    printf("Your college is: %s\n", college);
    printf("Your college is located in: %s\n", city);
}
*/

/*
Arrays in C
*/
/*
int main() {
    int luckyNumbers[] = {4, 5, 6};
    luckyNumbers[1] = 55;
    printf("%d\n", luckyNumbers[1]);
    return 0;
}
*/
/*
int main() {
    int luckyNumbers[20];

    luckyNumbers[0] = 1;
    luckyNumbers[1] = 2;

    luckyNumbers[0] = 11;
    printf("First number of the array is: %d\n", luckyNumbers[0]);
}
*/

/*
Functions in C
*/
// void means this cuntion is not going to return any information
/*void sayHi(char name[]) {
    printf("Hello %s!\n", name);
}
int main() {
    sayHi("Mike");
    sayHi("Mike");
    sayHi("Mike");
    return 0;
}
*/

/*
Return Type in C
*/
/*
double square(double num) {
    return num * num;
}

int main() {

    printf("Square number is: %.2f\n", square(2.0));
    return 0;
}
*/

/*
If statements in C
*/
/*
int findMax(int num1, int num2, int num3) {
    int result;
    if(num1 >= num2 && num1 >= num3) {
        result = num1;
    } else if(num2 >= num1 && num2 >= num3){
        result = num2;
    } else {
        result = num3;
    }
    return result;
}

int findMin(int num1, int num2, int num3) {
    int minimum;
    if(num1 <= num2 && num1 <= num3) {
        minimum = num1;
    } else if(num2 <= num1 && num2 <= num3){
        minimum = num2;
    } else {
        minimum = num3;
    }
    return minimum;
}

int main() {

    printf("The maximum is: %d\n", findMax(2, 5, 7));
    printf("The minimum is: %d\n", findMin(2, 5, 7));
    return 0;
}
*/

/*
A better Calculator in C
*/
/*
double add(double num1, double num2) {
    return num1 + num2;
}

double subtract(double num1, double num2) {
    return num1 - num2;
}

int main() {
    double num1;
    double num2;
    char op;

    printf("Enter the 1st number: ");
    scanf("%lf", &num1);

    printf("Enter the 2nd number: ");
    scanf("%lf", &num2);

    printf("Enter '+' or '-': ");
    scanf(" %c", &op);

    if(op == '+'){
        printf("Answer: %.2f\n", add(num1, num2));
    } else {
        printf("Answer: %.2f\n", subtract(num1, num2));
    }

    return 0;
}
*/
/*
While loop
*/
/*
int main() {
    int index = 1;

    while(index < 5) {
        printf("%d\n", index);
        index++;
    }
}
*/

/*
Guessing Game in C
*/
/*
int main() {
    int secretNumber = 5;
    int guess;
    int index = 0;

    int guessAmount;
    printf("How many guesses do you want to have? Enter a number 1-4: ");
    scanf("%d", &guessAmount);

    if(guessAmount > 3) {
        printf("Invalid input! The maximum number of guesses is 3. Exiting program...\n");
        return 0;
    } else{
        while(guess != secretNumber && index < guessAmount) {
            printf("Enter a number from 1-5. You have 3 tries: ");
            scanf("%d", &guess);
            index++;
            if(guess != secretNumber && index < guessAmount) {
                printf("Wrong! Try again...\n");
            }
        }
        if(index != 3){
            if(index == 1) {
                printf("You won! You guessed it in %d try! Congrats...\n", index);
            } else {
                printf("You won! You guessed it in %d tries!\n", index);
            }
        } else{
            printf("You lost!!! No guesses left...\n");
        }
    }
    return 0;
}
*/

/*
For Loops in C
*/
/*
int main() {
    int luckyNumbers[] = {2, 4, 6, 8, 10};
    for(int i = 0; i < 5; i++) {
        printf("%d\n", luckyNumbers[i]);
    }
}
*/

/*
2D Arrays and Nested Loops
*/
/*
int main() {
    int MAX = 5;
    int map[MAX][MAX];

    //we need to populate the map
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            map[i][j] = i + j;
        }
    }

    //prints the map values
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
}
*/

/*
Memory Addresses or Accessing the Memory
*/
/*
int main() {
    int age = 21;
    double gpa = 4.0;
    char grade = 'A';
    printf("age: %p\ngpa: %p\ngrade: %p\n", &age, &gpa, &grade);
}
*/

/*
Pointers in C
*/
/*
struct foo {
    int age;
    char name[20];
    double height;
};

void change(struct foo *f) {
    f->age = 22;
    f->height = 5.9;
    strcpy(f->name, "Alice");

    printf("Updated info: Age = %d, Name = %s, Height = %.1f\n", f->age, f->name, f->height);
}

int main(int argc, char *argv[]) {
    struct foo f;

    f.age = 21;
    strcpy(f.name, "John");
    f.height = 5.8;

    printf("Original info: Age = %d, Name = %s, Height = %.1f\n", f.age, f.name, f.height);

    change(&f);

    return 0;
}
*/
