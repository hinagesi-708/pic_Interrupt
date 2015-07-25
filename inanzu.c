//http://www.twitlonger.com/show/n_1sn4srb

#include<htc.h>

#include<xc.h>

// CONFIG
#pragma config FOSC = INTOSCIO 
#pragma config WDTE = OFF 
#pragma config PWRTE = ON 
#pragma config MCLRE = OFF 
#pragma config CP = OFF 
#pragma config CPD = OFF 
#pragma config BOREN = OFF 
#pragma config IESO = OFF 
#pragma config FCMEN = OFF 

int a,b,c;

volatile int flag;

void main(void){
	flag = 0;
	GIE = 1;
	T0IE = 0;
	T0CS = 0;
	PSA = 0;
	PS0 = 1;
	PS1 = 1;
	PS2 = 1;
	TMR0 = 0x00;
	TRISIO = 0xff;
	T0IE = 1;

	while(1){
		c++;
		if(flag > 0){ //タイマ割り込みがあればtimer_interrupt_handlerが呼ばれるのでここが1に変わっている
			flag = 0;
			if(1==T0IF){//したい処理を書いていく
				T0IF = 0;
				if(a == 1){
					GP2 = 1;
					b++;
					a--;
				}else if(b == 1){
					GP2 = 0;
					a++;
					b--;
				}
			}
		}
	}

	void interrupt timer_interrupt_handler(void){//タイマ割り込みがあるごとに1回呼ばれる
		flag = 1;
	}
