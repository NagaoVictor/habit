#include <stdio.h>

typedef struct {
  char name[20];
  int score;
} Player;


int main(){
  Player players[] = {
    {"Victor1", 100},
    {"Victor2", 150},
    {"Victor3", 120}
  };

  int n = sizeof(players)/sizeof(players[0]);
  
  for (int i = 0; i < n; i++){
    printf("%s -> %d\n", players[i].name, players[i].score);
  }
  return 0;

}
