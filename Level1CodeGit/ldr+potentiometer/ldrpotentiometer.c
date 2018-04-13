#include<avr/io.h>
#include<util/delay.h>

void init_adc()

{
	ADCSRA = ADCSRA|(0b00000001<<ADEN);			//enable
	ADMUX = ADMUX|(0b00000001<<REFS0);				//reference voltage
	ADCSRA = ADCSRA|(0b00000001<<ADPS2);			//sampling rate
}

unsigned int read_adc1()							//potentiometer change direction
{
ADMUX &=(0b01100000);	
ADMUX = ADMUX|(0b00000000);							//select input
ADCSRA = ADCSRA|(0b00000001<<ADSC);				//start the conversion
while(ADCSRA&(0b00000001<<ADIF) == 0){				//detect the end point

}
ADCSRA = ADCSRA|(0b00000001<<ADIF);				//clear the ADIF
return(ADCH);										//return output
}




unsigned int read_adc2()							//ldr change speed
{
ADMUX &=(0b01100000);
ADMUX = ADMUX|(0b00000001);							//select input
ADCSRA = ADCSRA|(0b00000001<<ADSC);				//start the conversion
while(ADCSRA&(0b00000001<<ADIF) == 0){				//detect the end point

}
ADCSRA = ADCSRA|(0b00000001<<ADIF);							//clear the ADIF
return(ADCH);											//return output
}


void main()
{

DDRB = 0b11111111;				//output from PORT B
DDRA = 0b00000000;				//input to PORT A					***because we have only PARTA as only input adc(analog) part***
//PORTA = 0b111111111; 			//pull up


init_adc();

unsigned int p,q,a,t,t_on,t_off;

while(1){
			
			
			p = read_adc1();		//ldr change speed
			
				a = (p/40);
				t = 1024/40;
				t_off = a;
				t_on = t - t_off;
				
				
				
				if(p>195){
					PORTB = 0b00000000;
				}
				else{
				q = read_adc2();		//potentiometer change direction
				
				if(q<332){
				
				
				PORTB = 0b00000110;	//left
				_delay_ms(t_on);
				PORTB = 0b00000000;		//stop
				_delay_ms(t_off);
				}
				
				else if((q<642)&&(q>332)){
				
				PORTB = 0b00001010;	//forward
				_delay_ms(t_on);
				PORTB = 0b00000000;		//stop
				_delay_ms(t_off);
				}
				else if(q>642){
				
				PORTB = 0b00001001;	//right
				_delay_ms(t_on);
				PORTB = 0b00000000;		//stop
				_delay_ms(t_off);
				}
				
				}
				
				/*
				
				else if((p>65)&&(p<130)){
				q = read_adc1();		//potentiometer change direction
				
				if(q<332){
				
				PORTB = 0b00000110;	//left
				_delay_ms(t_on);
				PORTB = 0b00000000;		//stop
				_delay_ms(t_off);
				}
				
				else if((q<642)&&(q>332)){
				
				PORTB = 0b00001010;	//forward
				_delay_ms(t_on);
				PORTB = 0b00000000;		//stop
				_delay_ms(t_off);
				}
				else if(q>642){
				
				PORTB = 0b00001001;	//right
				_delay_ms(t_on);
				PORTB = 0b00000000;		//stop
				_delay_ms(t_off);
				
				}
				}
				else if((p>130)&&(p<195)){
				
				if(q<332){
				
				PORTB = 0b00000110;	//left
				_delay_ms(t_on);
				PORTB = 0b00000000;		//stop
				_delay_ms(t_off);
				}
				
				else if((q<642)&&(q>332)){
				
				PORTB = 0b00001010;	//forward
				_delay_ms(t_on);
				PORTB = 0b00000000;		//stop
				_delay_ms(t_off);
				}
				else if(q>642){
				
				PORTB = 0b00001001;	//right
				_delay_ms(t_on);
				PORTB = 0b00000000;		//stop
				_delay_ms(t_off);
				}
				}
				*/
			
										
	
}


}