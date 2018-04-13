#include<avr/io.h>
#include<util/delay.h>

void main()

{
	
	DDRA = 0b11111111;	//OUTPUT TO PART A (LED)
	//DDRD = 0b00000000; //INPUT TO PART D
	//PORTD = 0b11111111; //PULLING UP INPUT
	//int c;
	int i  = 0b00000000;
	int a  = 0b00000001;
	while(1)
	{
		//c = PIND;
		//PORTA=0b00000000;	//go forward (pulse on)
		//_delay_ms(100);		//T on
		//PORTA=0b00000001;	//stop (pulse off)
		//_delay_ms(100);		//T off
		
		if(i<=0b00000111){	
			while(i<=0b00000111){
				PORTA = i;	
				i = i + a;
			}
		}
		
		if(i == 0b00001000){
			i = 0b00000000;
		}
		
	}
}
