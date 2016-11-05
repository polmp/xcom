#include "frame_rx.h"
#include <avr/interrupt.h>
#include <pbn.h>

static block_morse rx;
static missatge missatge_rx;

static void getmessage(void){
	frame_block_get(rx);
	print(rx);
}

int main(void){
	sei();
	frame_init();
	rx=(block_morse)missatge_rx;
	on_frame_received(getmessage);
	while(1);
	return 0;
}