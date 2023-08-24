#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
int main() {
    char runAgain;
    do {
        int population;  //starting population
        int populationEnd; //target population
        int count = 0; //counter for years

        printf("Enter starting population \n");
        scanf("%d", &population); //storing input
        do {  //handles blank space in user input
            population = getchar();
        } while (isspace(runAgain));

        printf("Enter target population \n");
        scanf("%d", &populationEnd); //storing input

        if (population > populationEnd) {  //checks invalid inputs and restarts if error is invalid
            printf("Invalid input, target population is smaller than starting population \n");
            runAgain = 'y'; //sets the loop to a value where it will run again.
            goto exitLoop; //Used to avoid unnecessary nesting of loops. Brings the code to the end of the loop. exitLoop is on line 59
        }
        do {  //loop for finding number of iterations necessary to reach target population
            population = round(population - (population / 4) + (population / 3));  //specified population growth by LAb 1
            count++;
        }  while(population < populationEnd); //loop condition

        printf("It took %d years \n", count); //prints final population
        count = 0;

        printf("Do you want to run another instance? (y/n) \n");
        scanf("%c", &runAgain);
        do {  //handles blank space in user input
            runAgain = getchar();
        } while (isspace(runAgain));
        switch (runAgain) { //if the user does not want to run another instance, checks for runAgain to be n and exits the program
            case 'n':
                printf("terminating instance");
                sleep(1);
                exit(0);
                break;
            case 'N':
                printf("terminating instance");
                sleep(1);
                exit(0);
                break;
            case 'y': //ensuring default does not trigger if runAgain is y
                break;
            case 'Y':
                break;
            default:
                printf("Invalid input, continuing by default \n");  //by default runs the program again.
                runAgain = 'y';
        }
    exitLoop:
    } while (runAgain == 'y' || runAgain == 'Y'); //condition for restarting the loop.

    return 0;
}
