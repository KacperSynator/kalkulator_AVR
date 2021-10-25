/* klawiatura
M+ M- MC MS C
7  8  9  %  CL
4  5  6  /  *
1  2  3  -  +
0  .  =  ^  sqrt
*/
#include <avr/io.h>
#include <util/delay.h>
#include "GLOBAL.h"
#include "LCD_HD44780.h"
#include "kalkulator.h"

uint8_t getKey() // zwraca wartosc przycisku po jego wciscnieciu. Gdy przycisk jest wciœniêty i trzymany to nic nie robi.
{
	for(uint8_t i=0 ; i<5;i++ )
	{
		cbi(PORTD,i);
		for(uint8_t j=0;j<5;j++)
		{
			if(bit_is_clear(PINC,j))
			{
				loop_until_bit_is_set(PINC,j);
				sbi(PORTD,i);
				return 5*i+(j+1);
			}
		}
		sbi(PORTD,i);
	}
	return 0;
}

// czestotliwosc 1Mhz
int main()
{
	DDRD=0b00011111;
	PORTD=0b00011111;

	DDRC=0x0;
	PORTC=0b00011111;

	LCD_HD44780::init();
	uint8_t sw=0;

	kalkulator kal;
	while(1)
	{
		sw=getKey();
		switch(sw)
		{
			case 1: // M+
			{
				kal.mem_add();
				break;
			}
			case 2: // M-
			{
				kal.mem_sub();
				break;
			}
			case 3: // MC
			{
				kal.mem_clear();
				break;
			}
			case 4: // MS
			{
				kal.mem_show();
				LCD_HD44780::showNumberDouble(kal.get_num());
				break;
			}
			case 5: // C
			{
				kal.clear();
				LCD_HD44780::clear();
				break;
			}

			case 6: //7
			{
				kal.read(7);
				LCD_HD44780::showNumberDouble(kal.get_num());
				break;
			}
			case 7: // 8
			{
				kal.read(8);
				LCD_HD44780::showNumberDouble(kal.get_num());
				break;
			}
			case 8: // 9
			{
				kal.read(9);
				LCD_HD44780::showNumberDouble(kal.get_num());
				break;
			}
			case 9: // %
			{
				kal.set_znak('%');
				break;
			}
			case 10: // CL usuñ ostatni
			{
				kal.clear_last();
				LCD_HD44780::showNumberDouble(kal.get_num());
				break;
			}

			case 11: // 4
			{
				kal.read(4);
				LCD_HD44780::showNumberDouble(kal.get_num());
				break;
			}
			case 12: // 5
			{
				kal.read(5);
				LCD_HD44780::showNumberDouble(kal.get_num());
				break;
			}
			case 13: // 6
			{
				kal.read(6);
				LCD_HD44780::showNumberDouble(kal.get_num());
				break;
			}
			case 14: // /
			{
				kal.set_znak('/');
				break;
			}
			case 15: // *
			{
				kal.set_znak('*');
				break;
			}
			case 16: //1
			{
				kal.read(1);
				LCD_HD44780::showNumberDouble(kal.get_num());
				break;
			}
			case 17: //2
			{
				kal.read(2);
				LCD_HD44780::showNumberDouble(kal.get_num());
				break;
			}
			case 18: // 3
			{
				kal.read(3);
				LCD_HD44780::showNumberDouble(kal.get_num());
				break;
			}
			case 19: // -
			{
				kal.set_znak('-');
				break;
			}
			case 20: // +
			{
				kal.set_znak('+');
				break;
			}
			case 21: // 0
			{
				kal.read(0);
				LCD_HD44780::showNumberDouble(kal.get_num());
				break;
			}
			case 22: // .
			{
				kal.set_point();
				break;
			}
			case 23: // =
			{
				kal.set_znak('=');
				LCD_HD44780::showNumberDouble(kal.get_result());
				break;
			}
			case 24: // ^
			{
				kal.set_znak('^');
				break;
			}
			case 25: // sqrt
			{
				kal._sqrt();
				LCD_HD44780::showNumberDouble(kal.get_result());
				break;
			}
			default:
			{
				break;
			}
		}
		_delay_ms(10);
	}
}


