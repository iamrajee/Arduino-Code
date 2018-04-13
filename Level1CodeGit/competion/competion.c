#include<avr/io.h>
#include<util/delay.h>

void init_adc()

{
	ADCSRA = ADCSRA|(0b00000001<<ADEN);			//enable
	ADMUX = ADMUX|(0b00000001<<REFS0);						//reference voltage
	ADCSRA = ADCSRA|(0b00000001<<ADPS2);						//sampling rate
}

unsigned int read_adc()
{
	
ADMUX = ADMUX|(0b00000000);										//select input
ADCSRA = ADCSRA|(0b00000001<<ADSC);						//start the conversion
while(ADCSRA&(0b00000001<<ADIF) == 0){									//detect the end point

}
ADCSRA = ADCSRA|(0b00000001<<ADIF);							//clear the ADIF
return(ADC);											//return output
}


void main()
{
//DDRA = 0b00000000;

DDRB = 0b11111111;				//output from PORT B

DDRD = 0b00000000;				//input to PORT D for object sensor		
PORTD = 0b111111111; 			//pull up

int d;
int temp = 0;


init_adc();
init_adc();

unsigned int p,a,t,t_on,t_off;

while(1){




	
	temp = temp + 1;
	if(temp == 1){

	
	d = PIND;						//object sensor in PORTD
	
	if(d == 0b11111111){							//#1	NO_OBJECT	NC
		PORTB = 0b00101010;		//Forward and beep
	}
	else if(d == 0b11111110){						//#2	NO_OBJECT	NC
		PORTB = 0b00000110;		//Forward and beep
	}
	else if(d == 0b11111101){						//#3	NO_OBJECT	NC
		PORTB = 0b00001001;
	}
	else if(d == 0b11111100){						//#4	NO_OBJECT	NC
		PORTB = 0b00001010;
	}
	else if(d == 0b11111011){						//#5	NO_OBJECT	YC
		p = read_adc();
		a = (p/40);
		t = 1024/40;
		t_off = a;
		t_on = t - t_off;
		
		
		PORTB = 0b00101010;	//FORWARD and beep
		_delay_ms(t_on);										
		PORTB = 0b00000000;		//stop
		_delay_ms(t_off);
	}
	else if(d == 0b11111010){						//#6	NO_OBJECT	YC
		p = read_adc();
		a = (p/40);
		t = 1024/40;
		t_off = a;
		t_on = t - t_off;
		
		
		PORTB = 0b00000110;	//left
		_delay_ms(t_on);										
		PORTB = 0b00000000;		//stop
		_delay_ms(t_off);
	}
	else if(d == 0b11111001){						//#7	NO_OBJECT	YC
		p = read_adc();
		a = (p/40);
		t = 1024/40;
		t_off = a;
		t_on = t - t_off;
		
		
		PORTB = 0b00001001;	//right
		_delay_ms(t_on);										
		PORTB = 0b00000000;		//stop
		_delay_ms(t_off);
	}
	else if(d == 0b11111000){						//#8	NO_OBJECT	YC
		p = read_adc();
		a = (p/40);
		t = 1024/40;
		t_off = a;
		t_on = t - t_off;
		
		
		PORTB = 0b00001010;	//FORWARD
		_delay_ms(t_on);										
		PORTB = 0b00000000;		//stop
		_delay_ms(t_off);
	}
	else if(d == 0b11110111){						//#9	YES_OBJECT	NC
		PORTB = 0b00100000;	//stop and beep on
	}
	else if(d == 0b11110110){						//#10	YES_OBJECT	NC
		PORTB = 0b00100000;	//stop and beep on
	}
	else if(d == 0b11110101){						//#11	YES_OBJECT	NC
		PORTB = 0b00100000;	//stop and beep on
	}
	else if(d == 0b11110100){						//#12	YES_OBJECT	NC
		PORTB = 0b00100000;	//stop and beep on
	}
	else if(d == 0b11110011){						//#13	YES_OBJECT	YC
		PORTB = 0b00100000;	//stop and beep on
	}
	else if(d == 0b11110010){						//#14	YES_OBJECT	YC
		PORTB = 0b00100000;	//stop and beep on
	}
	else if(d == 0b11110001){						//#15	YES_OBJECT	YC
		PORTB = 0b00100000;	//stop and beep on
	}
	else if(d == 0b11110000){						//#16	YES_OBJECT	YC
		PORTB = 0b00100000;	//stop and beep on
	}
	else{					//#17	default
			PORTB = 0b00000000;	//everything stop
	}


	
	temp = 0;
	}
	
}


}