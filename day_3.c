#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int stlen(char *p){
    int i=0;
    while(*(p + i) != '\0'){
        i++;
    }
    return i;
}
//For some reason I had to clear the buffer
void empty(char *p){
    int l = stlen(p);
    int i=0;
    while(*(p+i) != '\0'){
        *(p+i) = '\0';
        i++;
    }
}
int main(){
    FILE *file = fopen("day_3.txt", "r"); 
    char line[100];
    int sum =0;
    while(fgets(line, 100 , file)){
        int l = stlen(line) / 2;
        for(int i=0; i< l; i++){
            int flag =0;
            for(int j=l; j< 2*l; j++){
                if(line[i] == line[j]){
                    if(line[i] >= 65 && line[i] <= 90){
                        sum = sum + line[i] - 38;
                    }
                    else if(line[i] >= 97 && line[i] <= 122){
                        sum = sum + line[i] - 96;
                    }
                    flag = 1;
                    break;
                }
            }
            if(flag !=0)
                break;
        }
    }
    printf("%d \n",sum);
    sum = 0;
    rewind(file);
    char buf_1[100],buf_2[100],buf_3[100];
    int count =0;
    while(fgets(line, 100, file)){
        count++;
        if(count == 1)
            memmove(buf_1, line, stlen(line));
        else if(count == 2)
            memmove(buf_2, line, stlen(line));
        else if(count == 3){
            memmove(buf_3, line, stlen(line));
            int l_1 = stlen(buf_1);
            int l_2 = stlen(buf_2);
            int l_3 = stlen(buf_3);
            for(int i = 0; i< l_1; i++){
                int flag =0;
                for(int j=0; j< l_2; j++){
                    if(buf_1[i] == buf_2[j]){
                        for(int k=0; k< l_3; k++){
                            if(buf_2[j] == buf_3[k]){
                                if(buf_2[j] >= 65 && buf_2[j] <= 90)
                                    sum = sum + buf_2[j] - 38;
                                else if(buf_2[j] >= 97 && buf_2[j] <= 122)
                                    sum = sum + buf_2[j] - 96;
                                flag = 1;
                                break;
                            }
                        }
                        if(flag != 0)
                            break;
                    }
                }
                if(flag !=0)
                    break;
            }
            empty(buf_1);
            empty(buf_2);
            empty(buf_3);
            count = 0;
        }
        
    }
    printf("%d \n",sum);
    fclose(file);
}

