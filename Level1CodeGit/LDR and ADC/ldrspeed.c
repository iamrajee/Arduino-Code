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

DDRB = 0b11111111;				//output from PORT B
//DDRA = 0b00000000;				//input to PORT A					***because we have only PARTA as only input adc(analog) part***
//PORTA = 0b111111111; 			//pull up


init_adc();

unsigned int p,a,t,t_on,t_off;

while(1){

	p = read_adc();
	a = (p/195);
	t = 1024/195;
	t_off = a;
	t_on = t - t_off;
	
	if(p>195){
		PORTB = 0b00000000;
	}
	else{
		PORTB = 0b00001010;
		_delay_ms(t_on);										
		PORTB = 0b00000000;
		_delay_ms(t_off);	
	}
	
}
}