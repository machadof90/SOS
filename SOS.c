#include <stdio.h>
#include "pico/stdlib.h"

 // Define o pino GPIO 13 para o LED vermelho
#define LED_R 13

// Função para configurar o LED vermelho como saída
void con_LED (){
    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);
}

// Função para enviar um sinal ao LED vermelho
void enviar_sinal(int repeticao, int duracao, int gap, int intervalo){
    for(int i = 0; i < repeticao; i++){  // Loop para controlar o número de repetições
    gpio_put(LED_R, 1);
    sleep_ms(duracao);
    gpio_put(LED_R, 0);
    if (i < repeticao) {     // Se não for a última repetição, aguarda o tempo do gap                
        sleep_ms(gap);
    }
    }
// Aguarda o intervalo final após todas as repetições
sleep_ms(intervalo); 
}

int main()
{
stdio_init_all();
con_LED();
while (true){
    // 3 pulsos rápidos com 200 ms de duração, 125 ms de intervalo, e 250 ms após o padrão
    enviar_sinal(3, 200, 125, 250); 

    //3 pulsos longos com 800 ms de duração, 125 ms de intervalo, e 250 ms após o padrão
    enviar_sinal(3, 800, 125, 250);

    // 3 pulsos rápidos com 200 ms de duração, 125 ms de intervalo, e 250 ms após o padrão  
    enviar_sinal(3, 200, 125, 250);

    // Pausa final de 3000 ms antes de reiniciar os sinais
    sleep_ms(3000); 
}
}

