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
					PORTB = 0b00001010;		//Forward
			}

			if(c == 0b11111110){			//Obstacle to right
					PORTB = 0b00000110;		//turn left
			}

			if(c == 0b11111101){			//Obstacle to centre
					PORTB = 0b00000101;		//go back
					_delay_ms(300);
					PORTB = 0b00001001;		//turn right
					_delay_ms(300);

			}

			if(c == 0b11111100){		//Obstacle to centre and right
					PORTB = 0b00000101;	//go back
					_delay_ms(300);
					PORTB = 0b00000110;		//turn left
					_delay_ms(300);
			}

			if(c == 0b11111011){			//Obstacle to left
					PORTB = 0b00001001;		//turn right
			}

			if(c == 0b11111010){			//Obstacle to left and right
					PORTB = 0b00000101;			// go back
					_delay_ms(300);
					PORTB = 0b00001001;			//turn right
					_delay_ms(300);
			}

			if(c == 0b11111001){				//Obstacle to centre and left
					PORTB = 0b00000101;			 // go back
					_delay_ms(300);
					PORTB = 0b00001001;			//turn right
					_delay_ms(300);
			}

			if(c == 0b11111000){				//Obstacle to all sides
					PORTB = 0b00000101;				//go back
					_delay_ms(300);
					PORTB = 0b00001001;		//U-TURN
					_delay_ms(800);
			}

	temp = 0;
}
}

}
