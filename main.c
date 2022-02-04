/*
 * ashraf_test.c
 *
 * Created: 16/11/2021 07:08:44 م
 * Author : ahmed essam
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define D4 eS_PORTD4
#define D5 eS_PORTD5
#define D6 eS_PORTD6
#define D7 eS_PORTD7
#define RS eS_PORTC6
#define EN eS_PORTC7

unsigned char c;

#include "keypad_h.h"
#include "lcd_h.h"


	int main(void)
	{
		DDRD = 0b11111110;
		DDRC = 0xFF;
		DDRB = 0xFF;
		Lcd4_Init();
		while(1)
		{
			Lcd4_Clear();
			Lcd4_Set_Cursor(1,1);
			Lcd4_Write_String("Press a key");
			
			for (unsigned char i =0;i<16;i++)
			{
			Lcd4_Set_Cursor(2,i);
			c = keyfind();
			Lcd4_Write_Char(c);       /* Display which key is pressed */
			if ((c > 0) && (c < 9))
			{
			PORTB |= (1 << c);
			}	
			else if (c == 0)
			{
				PORTB &= 0x00;
			}
		}
	}
	}

