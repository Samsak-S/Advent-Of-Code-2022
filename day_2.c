#include<stdio.h>
#include<stdlib.h>
#define ROCK 1
#define PAPER 2
#define SCISSORS 3
#define WIN 6
#define DRAW 3
#define LOSS 0
int main(){
    FILE *file = fopen("day_2.txt", "r");
    char line[4];
    int points = 0;
    if(file == 0){
        printf("Could not open file. \n");
        return 1;
    }
    while(fgets(line, 4, file)){
        if(line[0] == 'A' && line[2] == 'X'){
            points = points + ROCK + DRAW ;
        }
        else if(line[0] == 'B' && line[2] == 'Y'){
            points = points + PAPER + DRAW ;
        }
        else if(line[0] == 'C' && line[2] == 'Z'){
            points = points + SCISSORS + DRAW ;
        }
        else if(line[0] == 'A' && line[2] == 'Y'){
            points = points + PAPER + WIN ;
        }
        else if(line[0] == 'A' && line[2] == 'Z'){
            points = points + SCISSORS + LOSS ;
        }
        else if(line[0] == 'B' && line[2] == 'X'){
            points = points + ROCK + LOSS ;
        }
        else if(line[0] == 'B' && line[2] == 'Z'){
            points = points + SCISSORS + WIN ;
        }
        else if(line[0] == 'C' && line[2] == 'X'){
            points = points + ROCK + WIN ;
        }
        else if(line[0] == 'C' && line[2] == 'Y'){
            points = points + PAPER + LOSS ;
        }
    }
    printf("%d \n",points);
    rewind(file);
    points =0;

    while(fgets(line, 4, file)){
        if(line[0] == 'A' && line[2] == 'X'){
            points = points + SCISSORS + LOSS ;
        }
        else if(line[0] == 'A' && line[2] == 'Y'){
            points = points + ROCK + DRAW ;
        }
        else if(line[0] == 'A' && line[2] == 'Z'){
            points = points + PAPER + WIN ;
        }
        else if(line[0] == 'B' && line[2] == 'X'){
            points = points + ROCK + LOSS;
        }
        else if(line[0] == 'B' && line[2] == 'Z'){
            points = points + SCISSORS + WIN ;
        }
        else if(line[0] == 'B' && line[2] == 'Y'){
            points = points + PAPER + DRAW ;
        }
        else if(line[0] == 'C' && line[2] == 'X'){
            points = points +PAPER + LOSS ;
        }
        else if(line[0] == 'C' && line[2] == 'Y'){
            points = points + SCISSORS + DRAW ;
        }
        else if(line[0] == 'C' && line[2] == 'Z'){
            points = points + ROCK + WIN ;
        }
    }

    printf("%d",points);
    fclose(file);
    return 0;
}
    


