#define F_CPU 1000000UL
#define BAUDRATE 4800
#define myubrr ((F_CPU/(BAUDRATE*16UL))-1)


#include<avr/io.h>
#include<util/delay.h>

void uart_init()

{
	UBRRH=(myubrr>>8);
	UBRRL = myubrr;
	UCSRB|=(1<<RXEN);
}

unsigned int uart_receive()
{
	while((UCSRA & (1<<RXC))==0);

	return(UDR);											//return output
}





void main()
{

unsigned char value;
DDRB = 0b11111111;				//output from PORT B
DDRD = 0b00000000;				//input to PORT A					***because we have only PARTA as only input adc(analog) part***
PORTD = 0b111111111; 			//pull up

uart_init();
_delay_ms(500);

while(1){
	value = uart_receive();
	
	if(value == 'F'){
		PORTB = 0b00001010;
		_delay_ms(100);
		PORTB = 0b00000000;
		
	
	}
	else if(value == 'B'){
		PORTB = 0b00000101;
		_delay_ms(100);
		PORTB = 0b00000000;
	
	
	
	}
	else if(value == 'L'){
		PORTB = 0b00000110;
		_delay_ms(100);
		PORTB = 0b00000000;
	
	}
	else if(value == 'R'){
		PORTB = 0b00001001;
		_delay_ms(100);
		PORTB = 0b00000000;
	}
	else{
	PORTB = 0b00000000;
	}
}
}