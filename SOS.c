#include <stdio.h>
#include "pico/stdlib.h"

#define LED_R 13
#define LED_G 11
#define LED_B 12

int main()
{
    stdio_init_all();
    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_init(LED_B);
    gpio_set_dir(LED_B, GPIO_OUT);

while (true){
    for(int i = 0; i < 3; i++){
    gpio_put(LED_B, 1);
    sleep_ms(200);
    }



    sleep_ms(3000);
}





}
