#ifndef _SCRLIB_H
#define _SCRLIB_H

#include <Arduino.h>

class scr {
	
	private:
		byte cs, rs, wr, rd, db0, db1, db2, db3, db4, db5, db6, db7, rst;
		
		unsigned int ContrastLevel;
		
		//char ChangeTab[8] = {0x00, 0x03, 0x1C, 0x1F, 0xE0, 0xE3, 0xFC, 0xFF};
				
	public:
		
		scr(byte cs, byte rs, byte wr, byte rd, byte db0, byte db1, byte db2, byte db3, byte db4, byte db5, byte db6, byte db7, byte rst);
		
		void init();
		
		void begin();
		
		void Reset();
		
		void WriteScreen(int data1, int data2, int data3, int ln, int cn);
		
		void EmptyScreen();
		
		void Print(String);
		
		void Test();
		
		void Test2();
		
		void Operate(bool rs, bool rd, bool wr, bool d7, bool d6, bool d5, bool d4, bool d3, bool d2, bool d1, bool d0);
		
		void SdCmd(uint8_t Command);
		
		void SdData(uint8_t DData);
		
		void LCD_Darker();
		
		void LCD_Lighter();
		
		//void Clear();
		
		
};

#endif