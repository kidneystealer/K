#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "k.h"

void add_random_tile(struct game *game){
    int row, col;

    // find random, but empty tile
    for(int i = 0; i < SIZE; i++){        
        for(int j = 0; j < SIZE; j++){
            if(game->board[i][j] == ' '){
             do{
                row = rand() % SIZE;
                col = rand() % SIZE;
             }while(game->board[row][col] != ' ');
                if(rand() % 2 == 0){
                    game->board[row][col] = 'A';
                }else{
                 game->board[row][col] = 'B';
                }       
             return;
            } 
        }
    }

   
}
//
bool is_game_won(const struct game game) {
    
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(game.board[i][j] == 'K'){
                return true;
               
            } 
        }
    }
    return false;
}
//
bool is_move_possible(const struct game game) {
    for(int i = 0; i < SIZE; i++){        
        for(int j = 0; j < SIZE; j++){
            if(game.board[i][j] == ' '){
                return true;
               
            } 
        }
    }
    for(int i = 0; i < SIZE; i++){        
        for(int j = 0; j < SIZE - 1; j++){
            if(game.board[i][j] == game.board[i][j + 1]){
                return true;
               
            } 
        }
    }

    for(int j = 0; j < SIZE; j++){        
        for(int i = 0; i < SIZE - 1; i++){
            if(game.board[i][j] == game.board[i + 1][j]){
                return true;
               
            } 
        }
    }
    return false;
}
//
bool update(struct game *game, int dy, int dx){
    if((dy != 0 && dx != 0) || (dy == 0 && dx == 0)){
        return false;
    }
  
    if(dy == 0){
        //left
        if(dx == -1){
            for(int i = 0; i < SIZE; i++){     
                for(int j = 0; j < SIZE - 1; j++){
                    int k = j + 1;
                    while (game->board[i][k] == ' '){
                        k++; 
                        if (k == SIZE){
                            break;
                        }
                    }       
                    
                    if (k == SIZE){
                            break;
                        }

                    char tmp = game->board[i][k];

                   if(game->board[i][j] != ' ' && game->board[i][j] == tmp){
                     game->board[i][j]++;
                     game->board[i][k] = ' '; 
                     game->score += pow(2, (int)game->board[i][j] - 64);
                    }
                   
                    if(game->board[i][j] == ' '){
                     game->board[i][j] = tmp;
                     game->board[i][k] = ' '; 
                     j--;                           
                    }   
                } 
            }
        } 
        //right
        if(dx == 1){
            for(int i = 0; i < SIZE; i++){     
                for(int j = SIZE - 1; j > 0; j--){
                    int k = j - 1;
                    while (game->board[i][k] == ' '){
                        k--; 
                        if (k == -1){
                            break;
                        }
                    }       
                    
                    if (k == -1){
                        break;
                    }

                    char tmp = game->board[i][k];
                    
                   if(game->board[i][j] != ' ' && game->board[i][j] == tmp){
                     game->board[i][j]++;
                     game->board[i][k] = ' '; 
                     game->score += pow(2, (int)game->board[i][j] - 64);
                    }
                   
                    if(game->board[i][j] == ' '){
                     game->board[i][j] = tmp;
                     game->board[i][k] = ' '; 
                     j++;                      
                    }   
                } 
            }
        } 
    }   

    if(dx == 0){
        //up
        if(dy == -1){
            for(int j = 0; j < SIZE; j++){     
                for(int i = 0; i < SIZE - 1; i++){
                    int k = i + 1;
                    while (game->board[k][j] == ' '){
                        k++; 
                        if (k == SIZE){
                            break;
                        }
                    }       
                    
                    if (k == SIZE){
                            break;
                        }

                    char tmp = game->board[k][j];
                    
                   if(game->board[i][j] != ' ' && game->board[i][j] == tmp){
                     game->board[i][j]++;
                     game->board[k][j] = ' '; 
                     game->score += pow(2, (int)game->board[i][j] - 64);                     
                    }
                   
                    if(game->board[i][j] == ' '){
                     game->board[i][j] = tmp;
                     game->board[k][j] = ' ';    
                     i--;                        
                    }   
                } 
            }
        } 
        //down
        if(dy == 1){
            for(int j = 0; j < SIZE; j++){     
                for(int i = SIZE - 1; i > 0; i--){
                    int k = i - 1;
                    while (game->board[k][j] == ' '){
                        k--; 
                        if (k == -1){
                            break;
                        }
                    }       
                    
                    if (k == -1){
                            break;
                        }

                    char tmp = game->board[k][j];
                    
                   if(game->board[i][j] != ' ' && game->board[i][j] == tmp){
                     game->board[i][j]++;
                     game->board[k][j] = ' '; 
                     game->score += pow(2, (int)game->board[i][j] - 64);
                    }
                   
                    if(game->board[i][j] == ' '){
                     game->board[i][j] = tmp;
                     game->board[k][j] = ' '; 
                     i++;                            
                    }   
                } 
            }
        } 

    }  

    
    return true;
} 
