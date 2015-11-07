#include"reg51.h"
sbit   DU=P2^6;
sbit   WE=P2^7;
unsigned char  code figure[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
delay(int h)
{int i,j;
for(i=0;i<=h;i++)
for(j=0;j<=h;j++);
}
 void play( unsigned int num)
 { 
 DU=1;
 P0=figure[num];
 DU=0;
 WE=1;
 P0=0xfe;
 WE=0;
 }
 void  key()
 {unsigned  char temp,keys;
   P3=0xfe;
   temp=P3;
   temp=temp&0xf0;
 if(temp!=0xf0)
  {
  delay(10);
  temp=P3;	 
  temp=temp&0xf0;	
  temp=P3; //赋值变量
 switch(temp)
  {case 0xee:
	  keys=0;
	  break;

  case 0xde:
	  keys=1;
	  break;

  case 0xbe:
     keys=2;
     break;
  case 0x7e:
     keys=3;
     break;
  }
 while(temp!=0xf0)	//消除连发影响
 {
  temp=P3;
  temp=temp&0xf0;
 } 		
  play(keys);
 
 }	}
 void main()
 {
   while(1)
   {key();
   }
 }