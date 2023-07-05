#include <stdio.h>
#include <stdlib.h>

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int main(){
    FILE *file = fopen("sample.txt", "r");
    if(file == 0){
        printf("Could not open file. \n");
        return 1;
    }
    char line[8];
    int value[2000];
    int value_idx = 0;
    int great_value = 0;
    int number =0;

    for( int i=0; i<2000; i++){
        value[i] =0;
    }
    while(fgets(line, 8, file)){
        number = number + atoi(line);
        if(atoi(line) == 0){
            value[value_idx] = number;
            value_idx++;
            number = 0;
        }

    }
    int swapped;
    for(int i=0; i< 2000-1;i++){
        swapped = 0;
        for(int j = 0; j< 2000 - i - 1; j++){
            if(value[j] < value[j+1]){
                swap(&value[j], &value[j+1]);
                swapped = 1;
            }
        }
        if(swapped == 0){
            break;
        }
    }
    int sum = value[0] + value [1] + value[2];
    printf("%d %d %d \n",value[0],value[1],value[2]);
    printf("%d \n",sum);


       fclose(file);
       return 0;
}

