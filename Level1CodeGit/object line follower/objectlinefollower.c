#include<avr/io.h>
#include<util/delay.h>

void main(){

DDRD = 0b00000000;	//INPUT TO PART D
DDRB = 0b11111111;	//OUTPUT FROM PART B (MOTOR)
PORTD = 0b11111111;	//PULL UP THE INPUT TO THE ATMEGA16 i.e here PARTD

int c;
int temp =0;
while(1){
	temp = temp + 1;
	if(temp == 32000){
	c = PIND;
	
			if(c == 0b11111111){			//No Obstacle
					PORTB = 0b00101010;		//Forward and beep
			}
			
			
			if(c == 0b11111110){			//no Obstacle
					PORTB = 0b00000110;		//turn left
					_delay_ms(1);
			}
			
			
			if(c == 0b11111101){			//yes Obstacle
					PORTB = 0b00100101;		//reverse and beep
					
			}
			
			
			if(c == 0b11111100){		//yes Obstacle
					PORTB = 0b00001001;		//right		PORTB = 0b00000101;			//reverse	
					_delay_ms(10);
			}
			
			if(c == 0b11111011){			//no Obstacle
					PORTB = 0b00001001;		//turn right
					_delay_ms(1);
			}
			
			if(c == 0b11111010){			//no Obstacle
					PORTB = 0b00001010;		//forward 
			}
			
			if(c == 0b11111001){				//yes Obstacle
				 	PORTB = 0b00000110;			//left			PORTB = 0b00000101;			//reverse
					_delay_ms(10z);
			}
			
			if(c == 0b11111000){				//yes Obstacle
					PORTB = 0b00000101;			//reverse
			}
			
			
	temp = 0;
	
}
}

}