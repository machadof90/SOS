#include <stdio.h>
#include "pico/stdlib.h"

#define LED_R 13
#define LED_G 11
#define LED_B 12

void con_LED (){
    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_init(LED_B);
    gpio_set_dir(LED_B, GPIO_OUT);
}

void enviar_sinal(int duracao, int gap, int repeticao){
    for(int i = 0; i < repeticao; i++){
    gpio_put(LED_B, 1);
    gpio_put(LED_G, 1);
    gpio_put(LED_R, 1);
    sleep_ms(duracao);
    gpio_put(LED_B, 0);
    gpio_put(LED_G, 0);
    gpio_put(LED_R, 0);
    if (i < repeticao - 1) {                      
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

