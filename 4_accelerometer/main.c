#include <stdio.h>
#include <stdlib.h>
#include "twi.h"
#include "accel.h"
#include "utility.h"
#include "gpio.h"
#include "uart.h"

int main(){

    uint8_t* data_buffer;
    data_buffer = (uint8_t *)malloc(1 * sizeof(uint8_t));

    data_buffer[0] = 9;

    uart_init();
    twi_init();

    int sleep = 0;


    while(1) {
        twi_multi_read(0x19, 0x0F, 1, data_buffer);
        utility_print(&uart_send, "who am I: %d\n", data_buffer[0]);
        //uart_send((char)data_buffer[0]);
        //uart_send(data_buffer[0]);
        //uart_send('G');


        sleep = 10000;
        while (--sleep);

    }



    free(data_buffer);

    return 0;
}