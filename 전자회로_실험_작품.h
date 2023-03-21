#include <18F452.h>
#use delay(clock=20000000)
#use RS232(baud=9600, parity=N, xmit=PIN_C6, rcv=PIN_C7)
#fuses NOWDT,NOCPD,HS,NOPROTECT,NOLVP,NOPUT,DEBUG,NOWRT
#include <stdlib.h>
#byte PORTD=0xF83
#byte TRISB=0xF93
#byte TRISD=0xF95
#byte TMR1H=0xfcf
#byte TMR1L=0xfce
#byte T1CON=0xfcd
long int count;
//long sec_count;
unsigned char blue;
//Reset Vector Address
#build(reset=0x200)
//Intterupts Vector Address
#build(interrupt=0x208)
//Bootloader Area
#org 0x0000,0x01ff
void bootloader()
{
#asm
nop //No Operation
#endasm
}
//////////////////////////////////////////시간 설정 함수 부분////////////////////////////////////////////////
void timer1_isr1()
{
if(count==200)
{
printf("1sec");
count=0;
PORTD=0x80;
setup_timer_1(T1_DISABLED);
}
}
void timer1_isr2()
{
if(count==400)
{
printf("2sec");
count=0;
PORTD=0x80;
setup_timer_1(T1_DISABLED);
}
}
void timer1_isr3()
{
if(count==1000)
{
printf("5sec");
count=0;
PORTD=0x80;
setup_timer_1(T1_DISABLED);
}
}
void timer1_isr4()
{
if(count==2000)
{
printf("10sec");
count=0;
PORTD=0x80;
setup_timer_1(T1_DISABLED);
}
}
void timer1_isr5()
{
if(count==6000)
{
printf("30sec");
count=0;
PORTD=0x80;
setup_timer_1(T1_DISABLED);
}
}
void timer1_isr6()
{
if(count==12000)
{
printf("1min");
count=0;
PORTD=0x80;
setup_timer_1(T1_DISABLED);
}
}
void timer1_isr7()
{
if(count==24000)
{
printf("2min");
count=0;
PORTD=0x80;
setup_timer_1(T1_DISABLED);
}
}
void timer1_isr8()
{
printf("ON");
count=0;
PORTD=0xff;
setup_timer_1(T1_DISABLED);
}
void timer1_isr9()
{
printf("OFF");
count=0;
PORTD=0x80;
setup_timer_1(T1_DISABLED);
}
//////////////////////////////////////////////타이머 인터럽트 부분//////////////////////////////////////////////
#int_timer1
void timer1_isr()
{
set_timer1(53036);
count++;
if(blue==0x01)
{
timer1_isr1();
}
else if(blue==0x02)
{
timer1_isr2();
}
else if(blue==0x03)
{
timer1_isr3();
}
else if(blue==0x04)
{
timer1_isr4();
}
else if(blue==0x05)
{
timer1_isr5();
}
else if(blue==0x06)
{
timer1_isr6();
}
else if(blue==0x07)
{
timer1_isr7();
}
else if(blue==0x08)
{
timer1_isr8();
}
else if(blue==0x09)
{
timer1_isr9();
}
}
///////////////////////////////////////////////외부 인트럽트 부분(스위치)/////////////////////////////////////////
#int_ext
void ext_isr()
{
PORTD=0xff;
setup_timer_1(T1_INTERNAL | T1_DIV_BY_2);
set_timer1(53036);
}
//////////////////////////////////////////////////메인함수////////////////////////////////////////////////////
void main()
{ 
unsigned char time;
TRISB=0x01;
TRISD=0x00;
PORTD=0x80;
count=0; //카운트를 0으로 초기화
//sec_count=0;
ext_int_edge(H_TO_L); //외부인터럽트 사용선언(스위치 인가방법 선언)
enable_interrupts(int_ext); //외부인터럽트 들어가는 함수(스위치 인가 시)
enable_interrupts(INT_TIMER1); //타이머 인터럽트 들어가는 함수
enable_interrupts(global); //밖으로 빠져나오는 함수
 while(true)
 { 
time = getc(); //어플을 통해 블루투스 값을 수신
getc();
putc(time); 
if(time=='a')
{
blue = 0x01;
}
else if(time=='b')
{
blue = 0x02;
}
else if(time=='c')
{
blue = 0x03;
}
else if(time=='d')
{
blue = 0x04;
}
else if(time=='e')
{
blue = 0x05;
}
else if(time=='f')
{
blue = 0x06;
}
else if(time=='g')
{
blue = 0x07;
}
else if(time=='h')
{
blue = 0x08;
}
else if(time=='i')
{
blue = 0x09;
}
 }
}
