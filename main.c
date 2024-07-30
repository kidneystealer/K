#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "k.h"
#include "hof.h"

struct game game = {
    .board = {
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '}

    },

    
    .score = 0
};

struct player list [10];
struct player player;

int main(){
char buffer[30];
//int k = 0;
int sizelist = load(list);
player.score = 0;
printf("Enter your name:");
fgets(buffer, 30, stdin);

for(int i = 0; i < strlen(buffer) - 1; i++){
   player.name[i] = buffer[i];
}

add_random_tile(&game);
while(is_game_won(game) != 1){

  for(int i = 0; i < SIZE; i++){
    for(int y = 0; y < SIZE; y++){
       printf("'%c'", game.board[i][y]) ;
    }
    printf("\n");
   } 
 
 if(is_move_possible(game) == 0){
    printf("You lose! Game over\n");
    break;
 }

  char tmp[SIZE][SIZE];
    for(int i = 0; i < SIZE; i++){
        strcpy(tmp[i], game.board[i]);
    }

 int choose;
 printf(" 1 - up;\n 2 - down;\n 3 - right;\n 4 - left.\n");
 
 int x, y;

if(scanf("%i", &choose) != 1 || !(choose > 0 && choose < 5)){
   while(getchar()!='\n');
   printf("Do you want to end the game?\nYes - click everywhere\nNo - 0\n");
         
   if(scanf("%i", &choose) != 1 || choose != 0){
      break;
   } else {
            continue;
         }
       }


 if(choose == 1){
    x = 0;
    y = -1;
    update(&game, y, x);
    add_random_tile(&game);
 } else if(choose == 2){
    x = 0;
    y = 1;
    update(&game, y, x);
    add_random_tile(&game);
   } else if(choose == 3){
       x = 1;
       y = 0;
       update(&game, y, x);
       add_random_tile(&game);
      } else if(choose == 4){
       x = -1;
       y = 0; 
       update(&game, y, x);
       add_random_tile(&game); 
       }
   
   int k = 0;
    for(int i = 0; i < SIZE; i++){
     if(strcmp(game.board[i], tmp[i]) == 0){
        k++;
     }  
    }

    if(k == SIZE){
        printf("Choose direction\n");
    } 

 printf("\nScore:%i\n", game.score);
}

player.score = game.score;

if(sizelist < 10){
    sizelist++;
}

if(add_player(list, &sizelist, player) == 0){
   printf("Sorry, you aren't one of the top ten\n");
} else{
   printf("Congratulations to you! You're one of the top ten!\n");
   for(int i = 0; i < sizelist; i++){
    printf("%s %i", list[i].name, list[i].score);
    printf("\n");
}
}



save(list, sizelist);

return 0;
}