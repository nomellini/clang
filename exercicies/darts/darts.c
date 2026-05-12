#include <stdio.h>
#include <math.h>
#include <stdint.h>


typedef struct {
    double x;
    double y;
} landing_position;

uint8_t score(landing_position pos) {


    double distancia = sqrt(pos.x * pos.x + pos.y * pos.y);

    if (distancia <= 1) {
        return 10;
    } else if (distancia <= 5) {
        return 5;
    } else if (distancia <= 10) {
        return 1;
    } else {
        return 0;
    }

}

int main() {
    landing_position pos = {-0.8, 0.8};
    printf("Score:  %d\n", score(pos));
    return 0;
}