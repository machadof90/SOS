#include <stdio.h>
#include "pico/stdlib.h"

#define LED_R 13
#define LED_G 11
#define LED_B 12

void con_LED (){
    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);
}

void enviar_sinal(int duracao, int gap, int repeticao){
    for(int i = 0; i < repeticao; i++){
    gpio_put(LED_R, 1);
    sleep_ms(duracao);
    gpio_put(LED_R, 0);
    if (i < repeticao) {                      
        sleep_ms(gap);
    }
    } 
}

int main()
{
stdio_init_all();
con_LED();
while (true){
    enviar_sinal(200, 125, 3);     
    enviar_sinal(800, 125, 3);
    enviar_sinal(200, 125, 3);
    sleep_ms(3000);
}
}

