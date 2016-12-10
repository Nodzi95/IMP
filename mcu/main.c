/*******************************************************************************
   main.c: LCD + keyboard demo
   Copyright (C) 2012 Brno University of Technology,
                      Faculty of Information Technology
   Author(s): Michal Bidlo <bidlom AT fit.vutbr.cz>

   LICENSE TERMS

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:
   1. Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
   2. Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.
   3. All advertising materials mentioning features or use of this software
      or firmware must display the following acknowledgement:

        This product includes software developed by the University of
        Technology, Faculty of Information Technology, Brno and its
        contributors.

   4. Neither the name of the Company nor the names of its contributors
      may be used to endorse or promote products derived from this
      software without specific prior written permission.

   This software or firmware is provided ``as is'', and any express or implied
   warranties, including, but not limited to, the implied warranties of
   merchantability and fitness for a particular purpose are disclaimed.
   In no event shall the company or contributors be liable for any
   direct, indirect, incidental, special, exemplary, or consequential
   damages (including, but not limited to, procurement of substitute
   goods or services; loss of use, data, or profits; or business
   interruption) however caused and on any theory of liability, whether
   in contract, strict liability, or tort (including negligence or
   otherwise) arising in any way out of the use of this software, even
   if advised of the possibility of such damage.

   $Id$


*******************************************************************************/

#include <fitkitlib.h>
#include <keyboard/keyboard.h>
#include <lcd/display.h>

#define SOUND	BIT0
#define set_sound(on){\
	P6DIR |= SOUND;\
	P6OUT = (on) ? (P6OUT & ~SOUND) : (P6OUT | SOUND);\
}
#define flip() {P6OUT ^= SOUND;}


int count = 0;
int prirustek;
int times;
int notes = -1;
int flipit = 1;

char last_ch; //naposledy precteny znak
char char_cnt = 0;

void print_user_help(void) { }

unsigned char decode_user_cmd(char *cmd_ucase, char *cmd)
{
  return CMD_UNKNOWN;
}

void fpga_initialized()
{
}

void MS100(int t){
	//LCD_append_char(' ');
	flipit = 0;
	count = 0;
	TACTL = TASSEL_1 + MC_2;
	TAR = 0x0000;
	prirustek = 0x07D0;
	CCR0 = 0x07D0;
	times = t;
}

void CDURC(){
	//LCD_append_char('C');
	flipit = 1;  
	count = 0;
	TACTL = TASSEL_1 + MC_2;
	TAR = 0x0000;
	prirustek = 0x003F;
	CCR0 = 0x003F;
	times = 131;
}
void CDURD(){ 
	//LCD_append_char('D');
	flipit = 1;
	count = 0;
	TACTL = TASSEL_1 + MC_2;
	TAR = 0x0000;
	prirustek = 0x0038;
	CCR0 = 0x0038;
	times = 147;
}
void CDURE(){
	//LCD_append_char('E');
	flipit = 1;
	count = 0;
	TACTL = TASSEL_1 + MC_2;
	TAR = 0x0000;
	prirustek = 0x0032;
	CCR0 = 0x0032;
	times = 165;
}
void CDURF(){
	//LCD_append_char('F');
	flipit = 1;
	count = 0;
	TACTL = TASSEL_1 + MC_2;
	TAR = 0x0000;
	prirustek = 47;
	CCR0 = 47;
	times = 175;
}
void CDURG(){
	//LCD_append_char('G');
	flipit = 1;
	count = 0;
	TACTL = TASSEL_1 + MC_2;
	TAR = 0x0000;
	prirustek = 0x002A;
	CCR0 = 0x002A;
	times = 196;
}
void CDURA(){
	//LCD_append_char('A');
	flipit = 1;
	count = 0;
	TACTL = TASSEL_1 + MC_2;
	TAR = 0x0000;
	prirustek = 0x0025;
	CCR0 = 0x0025;
	times = 220;
}
void CDURC2(){
	//LCD_append_char('C2');
	flipit = 1;
	count = 0;
	TACTL = TASSEL_1 + MC_2;
	TAR = 0x0000;  
	prirustek = 0x0021;
	CCR0 = 0x0021;
	times = 247;
}

void strar_wars(){
	notes = -1;
	if(notes == -1){
		
		MS100(1);
		while(1){
			if(notes == 0) break;
		}
		
	}
	if(notes == 0){
		CDURC();
		while(1){
			if(notes == 1) break;
		}
	}
	if(notes == 1){
		
		MS100(1);
		while(1){
			if(notes == 2) break;
		}
		
	}
	if(notes == 2){
		CDURG();
		while(1){
			if(notes == 3) break;
		}
	}
	if(notes == 3){
		
		MS100(1);
		while(1){
			if(notes == 4) break;
		}
		
	}
	if(notes == 4){
		CDURF();
		while(1){
			if(notes == 5) break;
		}
	}
	if(notes == 5){
		CDURE();
		while(1){
			if(notes == 6) break;
		}
	}
	if(notes == 6){
		CDURD();
		while(1){
			if(notes == 7) break;
		}
	}
	if(notes == 7){
		
		MS100(1);
		while(1){
			if(notes == 8) break;
		}
		
	}
	if(notes == 8){
		CDURC2();
		while(1){
			if(notes == 9) break;
		}
	}
	if(notes == 9){
		
		MS100(1);
		while(1){
			if(notes == 10) break;
		}
		
	}
	if(notes == 10){
		CDURG();
		while(1){
			if(notes == 11) break;
		}
	}
	if(notes == 11){
		
		MS100(1);
		while(1){
			if(notes == 12) break;
		}
		
	}
	if(notes == 12){
		CDURF();
		while(1){
			if(notes == 13) break;
		}
	}
	if(notes == 13){
		CDURE();
		while(1){
			if(notes == 14) break;
		}
	}

	if(notes == 14){
		CDURD();
		while(1){
			if(notes == 15) break;
		}
	}
	if(notes == 15){
		
		MS100(1);
		while(1){
			if(notes == 16) break;
		}
		
	}
	if(notes == 16){
		CDURC2();
		while(1){
			if(notes == 17) break;
		}
	}
	if(notes == 17){
		
		MS100(1);
		while(1){
			if(notes == 18) break;
		}
		
	}
	if(notes == 18){
		CDURG();
		while(1){
			if(notes == 19) break;
		}
	}
	if(notes == 19){
		CDURF();
		while(1){
			if(notes == 20) break;
		}
	}
	if(notes == 20){
		CDURE();
		while(1){
			if(notes == 21) break;
		}
	}
	if(notes == 21){
		
		MS100(1);
		while(1){
			if(notes == 22) break;
		}
		
	}
	if(notes == 22){
		CDURF();
		while(1){
			if(notes == 23) break;
		}
	}
	if(notes == 23){
		CDURD();
		while(1){
			if(notes == 24) break;
		}
	}
}

void print_song(int i){
	term_send_str("SONG: ");
	if(i == 0){
		LCD_append_char('S');
		LCD_append_char('T');
		LCD_append_char('A');
		LCD_append_char('R');
		LCD_append_char(' ');
		LCD_append_char('W');
		LCD_append_char('A');
		LCD_append_char('R');
		LCD_append_char('S');
		strar_wars();
	}
	else if(i == 1){
		term_send_str("SONG B");
	}
}
void print_hlaska(){
	term_send_str("UNSUPPORTED KEY");
}

void note(char ch){
	count = 0;
	  	if(ch == '1'){
	  		LCD_append_char('C');
      		CDURC();
      	}
      	else if(ch == '2'){
      		LCD_append_char('D');
      		CDURD();
      	}
      	else if(ch == '3'){
      		LCD_append_char('E');
      		CDURE();
      	}
      	else if(ch == '4'){
      		LCD_append_char('F');
      		CDURF();
      	}
     	else if(ch == '5'){
      		LCD_append_char('G');
      		CDURG();
      	}
      	else if(ch == '6'){
      		LCD_append_char('A');
      		CDURA();
      	}
      	else if(ch == '7'){
      		LCD_append_char('C');
      		LCD_append_char('\'');
      		CDURC2();
      	}
      	else if(ch == 'A'){
      		print_song(0);
      		notes = -1;
      	}
      	else if(ch == 'B'){
      		print_song(1);
      	}
      	else{
      		print_hlaska();
      	}
      	
      	//count++;
	}
	


int keyboard_idle(){
  	char ch;
  	ch = key_decode(read_word_keyboard_4x4());
  	if(ch != last_ch){
  		last_ch = ch;
  		if (ch != 0){		  		
      		LCD_clear();
      		note(ch);
    	}
  	}
  	return 0;
}

int main(void)
{
  char_cnt = 0;
  last_ch = 0;

  initialize_hardware();
  keyboard_init();
  LCD_init();
  LCD_clear();
  CCTL0 = CCIE;
  TACTL = MC_0;
  set_sound(1);
  while (1)
  {
    keyboard_idle();  // obsluha klavesnice
    terminal_idle();  // obsluha terminalu
  }         
}


interrupt (TIMERA0_VECTOR) Timer_A(void){
	if(count < (times*2)){ 	//bude hrat 0,5s (odzkoušet s reprakem)
		if(flipit){			//vytváření "sinusovky"
			flip();	
		}
		count++;			//přičítá dokud platí podmínka
		CCR0 += prirustek;	//nastavit další přerušení
	}
	else{					//už si odevral určitý čas a zruší požadavky na přerušení
		count = 0;			//inicializuje proměnnou pro další stiknutí klávesnice
		notes++;			//nastaví přehrávání další noty v písničce
		TACTL = MC_0;
	}
}
