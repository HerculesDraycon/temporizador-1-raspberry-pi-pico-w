#include <stdio.h>
#include "pico/stdlib.h"
// Definicao dos pinos dos LEDs
#define GREEN_PINO 11
#define BLUE_PINO 12
#define RED_PINO 13
// Enum para os estados do semaforo
typedef enum {
    RED,
    YELLOW,
    GREEN
} TrafficState;

volatile TrafficState state = RED; // Estado inicial do semaforo

bool repeating_timer_callback(struct repeating_timer *t){
    // Desliga todos os LEDs antes de mudar o estado
    gpio_put(RED_PINO, false);
    gpio_put(BLUE_PINO, false);
    gpio_put(GREEN_PINO, false);
    // Switch que muda os estados do semaforo
    switch(state){

        case RED:
            gpio_put(RED_PINO, true);
            state = YELLOW;  //Define o proximo estado
            break;
        case YELLOW:
            gpio_put(BLUE_PINO, true);
            state = GREEN;  //Define o proximo estado
            break;
        case GREEN:
            gpio_put(GREEN_PINO, true);
            state = RED;  //Define o proximo estado
            break;

    }

    return true;

}

int main(){

    stdio_init_all();

    gpio_init(GREEN_PINO);
    gpio_init(BLUE_PINO);
    gpio_init(RED_PINO);

    gpio_set_dir(GREEN_PINO, GPIO_OUT);
    gpio_set_dir(BLUE_PINO, GPIO_OUT);
    gpio_set_dir(RED_PINO, GPIO_OUT);

    struct repeating_timer timer;
    // Inicializa o timer repetitivo para chamar a função a cada 2 segundos (2000 ms)
    add_repeating_timer_ms(-3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        tight_loop_contents(); // Mantem o processador em idle enquanto o timer funciona
    }

}
