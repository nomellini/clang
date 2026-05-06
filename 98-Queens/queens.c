#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef enum { CAN_NOT_ATTACK, CAN_ATTACK, INVALID_POSITION } attack_status_t;

typedef struct {
   uint8_t row;
   uint8_t column;
} position_t;

attack_status_t can_attack(position_t queen_1, position_t queen_2);

attack_status_t can_attack(position_t queen_1, position_t queen_2) {

    if (
            queen_1.row > 7 || 
            queen_1.column > 7 || 
            queen_2.row > 7 ||
            queen_2.column > 7 || 
           (queen_1.row == queen_2.row && queen_1.column == queen_2.column)
    ) {
        return INVALID_POSITION;
    }

    if (queen_1.row == queen_2.row || queen_1.column == queen_2.column || abs(queen_1.row - queen_2.row) == abs(queen_1.column - queen_2.column)) {
        return CAN_ATTACK;
    }
    return CAN_NOT_ATTACK;
}

int main() {

   position_t white_queen;
   position_t black_queen;
   white_queen.column = 2;
   white_queen.row = 2;
   black_queen.column = 3;
   black_queen.row = 2;

    attack_status_t status = can_attack(white_queen, black_queen);
    switch (status) {
        case CAN_NOT_ATTACK:
            printf("The queens can not attack each other.\n");
            break;
        case CAN_ATTACK:
            printf("The queens can attack each other.\n");
            break;
        case INVALID_POSITION:
            printf("Invalid position.\n");
            break;
    }

 
}

