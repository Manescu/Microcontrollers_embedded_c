#include <hidef.h> 
#include "derivative.h" 
#include "mc9s08aw60.h"
#include "CDL.h"
#include <stddef.h>

void initPort(void);

void initPort(void)
{
	PTFDD=0xFF; //->setam ledurile pentru output(sa afiseze)
				//directia datelor este pentru afisare
	PTCDD=0x00; //->setam switch-urile 1 si 2 pentru input
				//directia datelor este pentru intrare
	PTCPE=0xFF; //->activam switch-urile sa mearga
	PTDDD=0x00; //->setam switch-urile 3 si 4 pentru input
				//->directia datelor este pentru intrare
	PTDPE=0xFF; //->activam switch-urile sa mearga
}

#define unlocked 0
#define locked 1
#define doublelocked 2

//Use NAND. button state
#define HIGH 0x00
#define LOW 0xFF


//LED state
#define ON 0xFF
#define OFF 0x00

#define L_LED PTFD_PTFD7
#define R_LED PTFD_PTFD0
#define btn PTCD_PTCD6  //PTDD_PTDD3

int key = 0;
int ok = 0;
int ok1 = 0;
int count = 0;
int cnt_0 = 0;
int cnt_1 = 0;
int cnt_2 = 0;
int flag = 0;
int ok_blink = 0;
int isLocked =0;
int state = unlocked;

void loop()
{
   switch(key)
  {
    case unlocked: 
    {     
      Unlocked_Mode();
      break;
    }
    case locked: 
    {
      Locked_Mode();      
   	  break;
    }
    case doublelocked:
    {
      DoubleLocked_Mode();            
      break;
    }   
  }
}

void Blink()
{ 
	if(ok_blink == 0)
	{
	  count = 0;
	}
	if(count < 30)
	{
        L_LED = ON;
        R_LED = ON;
		count++;
        ok_blink = 1;
           
	}
	else if(count <100)
	{
	    L_LED = OFF;
		R_LED = OFF;
		count++;       
	}
	if(count == 100)
	{
    	ok_blink = 0; 
       	flag+= 10;      
	}  
 }

void Unlocked_Mode()
{  
  if(flag < 20 && ok == 0)
  {
    Blink();
  } 
  if(flag == 20)
  {
    flag = 0;
    ok = 1;
    state = unlocked;
    key = unlocked;

  }
  if(btn == HIGH)
  {
    cnt_0++;
  }
   if(cnt_0 >= 80)
  {
    ok1 = 1;
    cnt_0 = 0;
  }  
  if(ok1 == 1 && btn == LOW)
  {    
    Locked_Mode();
    key = locked;
    ok = 0;
    cnt_0 = 0;
    flag = 0;
  }  
}

void Locked_Mode()
{ 
 if(flag < 10 && state != locked)
 {   
   Blink();
 }
  if(flag == 10)
  {
    state = locked;
    flag = 0;
  } 
  if(btn == HIGH)
  {  
    cnt_1++;      
  }
    if(cnt_1 != 0 && btn == LOW)
    { 
      if(cnt_1 >= 80)
      {
        Unlocked_Mode();
        key = unlocked;
        cnt_1 = 0;
        
      }
      else if ( cnt_1 <= 80 )
      {
        DoubleLocked_Mode();
        key = doublelocked;
        cnt_1 = 0; 
      }
    }      
  }



void DoubleLocked_Mode()
{
 if(flag < 10 && state != doublelocked)
 {   
   Blink();
 }
  if(flag == 10)
  {
    state = doublelocked;
    flag = 0;
  }
 if(btn == HIGH)
  {  
    cnt_2++;      
  }
 if(cnt_2 >= 80)
 {
   ok = 1;
 }
  else
  {
    ok = 0;
  }
    if(cnt_2 != 0 && btn == LOW)
    {  
      if(ok == 1)
      {
        Unlocked_Mode();
        key = unlocked;
        cnt_2 = 0;
      }
  
 }
}
