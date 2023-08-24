#include <stdio.h>
#include <math.h>
int main() {
    int population;  //starting population
    int populationEnd; //target population
    int count = 0; //counter for years
    
    printf("Enter starting population \n");
    scanf("%d", &population); //storing input
    while (getchar() != '\n') {}
    
    printf("Enter target population \n");
    scanf("%d", &populationEnd); //storing input
    
    if (population > populationEnd) {  //checks invalid inputs and returns error if input is invalid
        return 1;
    }
    do {  //loop for finding number of iterations necessary to reach target population
        population = round(population - (population / 4) + (population / 3));
        count++;
    }  while(population < populationEnd); //loop condition
    printf("It took %d years \n", count); //prints final population
    count = 0;
    return 0;
}
