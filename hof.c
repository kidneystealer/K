#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hof.h"

//
int load(struct player list[]){
    
    int k = 0;
    int counter = 0;
    int j = 0;
    char buffer[30];

    FILE *file = fopen("list.txt", "r");
    if (file == NULL) {
        printf("Cannot open file\n");
        return -1;
    }
  
    while ((buffer[j] = fgetc(file)) != EOF) {
        
        if((buffer[j]) == ' '){    
            fscanf(file, "%d", &list[counter].score);
             k = 0; 
             j = 0;
            for(int i = 0; i < strlen(buffer) - 1; i++){
                 if((buffer[k]) == ' '){ 
                    break;
                 }
                if(buffer[i] == '\n'){
                   k++; 
                }             
                list[counter].name[i] = buffer[k];
                k++;
            
                
                
            }
            counter++;
            memset(buffer, 0, sizeof(buffer));
        } else {j++;}      
    } 

    

    fclose(file);
    return counter;
}

//
bool add_player(struct player list[], int* size, const struct player player){
    if(player.score < list[(*size) - 1].score){
        return false;
        }
    for(int i = *size - 1; i > 0; i--){
        if(player.score >= list[i].score && player.score < list[i - 1].score){
            for(int j = *size - 1; j > i; j--){
                strncpy(list[j].name, list[j - 1].name, sizeof(list[j - 1].name - 2));
                list[j].score = list[j - 1].score;
            }
            list[i].score = player.score;
            strncpy(list[i].name, player.name, sizeof(player.name) - 1);   
        }
        
        }
        if(player.score >= list[0].score){
            for(int j = *size - 1; j > 0; j--){
                strncpy(list[j].name, list[j - 1].name, sizeof(list[j - 1].name - 2));
                list[j].score = list[j - 1].score;
            }
            list[0].score = player.score;
            strncpy(list[0].name, player.name, sizeof(player.name) - 1);
    }
    return true;
}


bool save(const struct player list[], const int size){
    
    FILE *file = fopen("list.txt", "w");
    if (file == NULL) {
        printf("Cannot open file\n");
        return -1;
    }
    
    for(int i = 0; i < size; i++){
        fputs(list[i].name, file);
        fputs(" ", file);
        fprintf(file, "%d", list[i].score);
        if(i < size - 1){
        fputs("\n", file);
        }
    }
    return 1;
}
