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
        do {
            population = getchar();
        } while (isspace(runAgain));

        printf("Enter target population \n");
        scanf("%d", &populationEnd); //storing input

        if (population > populationEnd) {  //checks invalid inputs and returns error if input is invalid
            printf("Invalid input, target population is smaller than starting population \n");
            sleep(1);
            break;
        }
        do {  //loop for finding number of iterations necessary to reach target population
            population = round(population - (population / 4) + (population / 3));
            count++;
        }  while(population < populationEnd); //loop condition

        printf("It took %d years \n", count); //prints final population
        count = 0;

        printf("Do you want to run another instance? (y/n) \n");
        scanf("%c", &runAgain);
        do {
            runAgain = getchar();
        } while (isspace(runAgain));
        switch (runAgain) {
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
            case 'y':
                break;
            case 'Y':
                break;
            default:
                printf("Invalid input, continuing by default \n");
                runAgain = 'y';
        }

    } while (runAgain == 'y' || runAgain == 'Y');

    return 0;
}
