#include<avr/io.h>
#include<util/delay.h>

void main()

{
	
	DDRB = 0b11111111;	//OUTPUT FROM PART B (MOTOR)
	
	while(1)
	{
		PORTB=0b00001010;	//go forward (pulse on)
		_delay_ms(100);		//T on
		PORTB=0b00001111;	//stop (pulse off)
		_delay_ms(1);		//T off
	}
}
