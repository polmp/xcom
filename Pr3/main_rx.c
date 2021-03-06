#include "frame_rx.h"
#include <avr/interrupt.h>
#include <pbn.h>

static block_morse rx;
static missatge missatge_rx;

void getmessage(void){
	frame_block_get(rx);
	serial_put('R');
	serial_put('|');
	print((char *)rx);
}

int main(void){
	sei();
	frame_init();
	rx=(block_morse)missatge_rx;
	on_frame_received(getmessage);
	print("OK");
	while(1);
	return 0;
}
