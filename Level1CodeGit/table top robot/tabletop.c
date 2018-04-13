#include<avr/io.h>
#include<util/delay.h>

void main(){

DDRD = 0b00000000;	//INPUT TO PART D
DDRB = 0b11111111;	//OUTPUT FROM PART B (MOTOR)
PORTD = 0b11111111;	//PULL UP THE INPUT TO THE ATMEGA16 i.e here PARTD

int c;
int temp =0;
while(1){

	c = PIND;
	temp = temp + 1;
	if(temp == 10000){
	
	
		if(c == 0b11110000){			//SENSOR OUT OF TABLE = no one
			PORTB = 0b00001010;		//Forward
		}
			
		if(c == 0b11110001){			//SENSOR OUT OF TABLE =	4
			PORTB = 0b00001010;		//Go Forward
			_delay_ms(300);
			PORTB = 0b00000110;		//turn left
			_delay_ms(1);
		}
			
		if(c == 0b11110010){			//SENSOR OUT OF TABLE =	3
			PORTB = 0b00001010;		//Go Forward
			_delay_ms(300);
			PORTB = 0b00001001;		//turn right
			_delay_ms(1);					
		}
			
		if(c == 0b11110011){				//SENSOR OUT OF TABLE =	3,4
			PORTB = 0b00001010;			//Forward
		}
			
		if(c == 0b11110100){			//SENSOR OUT OF TABLE =	2
			PORTB = 0b00000101;			 // go back
			_delay_ms(1
			);
			PORTB = 0b00000110;		//turn left
			_delay_ms(1);
		}
			
		if(c == 0b11110101){			//SENSOR OUT OF TABLE =	2,4					****WONT OCCUR*****
			PORTB = 0b00001111;			// stop
		}
			
		if(c == 0b11110110){				//SENSOR OUT OF TABLE =2,3
			PORTB = 0b00000110;			//turn left
			_delay_ms(100);
		}
			
		if(c == 0b11110111){				//SENSOR OUT OF TABLE =	2,3,4
			PORTB = 0b00000110;			//turn left
			_delay_ms(100);
		}
			
		if(c == 0b11111000){			//SENSOR OUT OF TABLE =	1
			PORTB = 0b00000101;			// go back 
			_delay_ms(1);	
			PORTB = 0b00001001;			//turn right
			_delay_ms(1);
		}
			
		if(c == 0b11111001){			///SENSOR OUT OF TABLE =	1,4
			PORTB = 0b00001001;			//turn right
			_delay_ms(100);
		}
			
		if(c == 0b11111010){			//SENSOR OUT OF TABLE =	1,3					****WONT OCCUR****
			PORTB = 0b00001111;		//stop
		}
			
		if(c == 0b11111011){			//SENSOR OUT OF TABLE =	1,3,4
			PORTB = 0b00001001;			//turn right
			_delay_ms(100);
		}
			
		if(c == 0b11111100){			//SENSOR OUT OF TABLE =	1,2
			PORTB = 0b00000101;			//go back
			_delay_ms(300);
			PORTB = 0b00001001;			//turn right
			_delay_ms(350);
			
		}
			
		if(c == 0b11111101){			//SENSOR OUT OF TABLE =	1,2,4
			PORTB = 0b00001001;			//turn right
			_delay_ms(100);
		}
			
		if(c == 0b11111110){			//SENSOR OUT OF TABLE =	1,2,3
			PORTB = 0b00000110;			//turn left
			_delay_ms(100);			
		}
			
		if(c == 0b11111111){			//SENSOR OUT OF TABLE =	1,2,3,4				***WONT OCCUR***
			PORTB = 0b00001111;		//stop
		}
		temp = 0;
	}
}

}