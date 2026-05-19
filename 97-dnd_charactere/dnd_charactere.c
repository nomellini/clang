
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
char *name;
   int strength;
   int dexterity;
   int constitution;
   int intelligence;
   int wisdom;
   int charisma;
   int hitpoints;
} dnd_character_t;

int ability(void);
int modifier(int score);
dnd_character_t make_dnd_character(void);

char *name(void) {
    char *names[] = {"Aragorn", "Legolas", "Gimli", "Frodo", "Gandalf", "Boromir"};
    int index = rand() % 6;
    return names[index];
}

int ability(void) {
    // lançar 4 dados de 6 faces, descartar o menor e somar os outros 3

    int dice[4];
    for (int i = 0; i < 4; i++) {
        dice[i] = rand() % 6 + 1;
    }
    // ordenar os dados para descartar o menor
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (dice[j] > dice[j + 1]) {
                int temp = dice[j];
                dice[j] = dice[j + 1];
                dice[j + 1] = temp;
            }
        }
    }
    
    return dice[1] + dice[2] + dice[3];
       

}

int modifier(int score) {
    int x = floor((score - 10)/2.0);
    return  x;
}

dnd_character_t make_dnd_character(void) {

    dnd_character_t character;
    character.name = name();
    character.strength = ability();
    character.dexterity = ability();
    character.constitution =ability();
    character.wisdom = ability();
    character.charisma = ability();
    character.intelligence = ability();    
    character.hitpoints = 10 + modifier(character.constitution);
 
    return character;
}


int main() {
    srand(time(NULL));
    dnd_character_t character = make_dnd_character();
    printf("Name: %s\n", character.name);
    printf("Strength: %d\n", character.strength);
    printf("Dexterity: %d\n", character.dexterity);
    printf("Constitution: %d\n", character.constitution);
    printf("Intelligence: %d\n", character.intelligence);
    printf("Wisdom: %d\n", character.wisdom);
    printf("Charisma: %d\n", character.charisma);
    printf("Hitpoints: %d\n", character.hitpoints);
    return 0;
}