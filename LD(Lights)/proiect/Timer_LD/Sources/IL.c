#include <hidef.h> 
#include "derivative.h" 
#include "mc9s08aw60.h"
#include "IL.h"
#include <stddef.h>


#define HIGH 0x00
#define LOW 0xff
#define ON 0xff
#define OFF 0x00
#define L_LED PTFD_PTFD7
#define R_LED PTFD_PTFD0
#define H_btn PTCD_PTCD6  //PTDD_PTDD3
#define L_btn PTCD_PTCD6
#define R_btn PTDD_PTDD2

//static void Default_Mode();


void initPort(void);

int key = 0;




int count = 0;
int cnt = 0;
int cnt_N = 0;
int cnt_LC = 0;
int cnt_H = 0;
int cnt_btn_H = 0;
int flag = 0;
int dis_N = 0;
int f_H = 0;
int ok = 0;
int ok_LC = 0;
int ok_H = 0;


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

void loop()
{ 
  switch(key)
  {
    case 0: 
    {     
      Default_Mode();
      break;
    }
    case 1: 
    {
      LC_Mode(L_LED, L_btn);
   	  break;
    }
    case 2:
    {
      LC_Mode(R_LED, R_btn); 
      break;
    }
    case 3: 
    {
      Hazard_Mode();
      break;
    }
  }

  //delay(10);
}

void Blink(int LED)
{ 
	if(ok == 0)
	{
	  count = 0;
	}
	if(count < 30)
	{
		LED = ON;
		count++;
        ok = 1;
           
	}
	else if(count <100)
	{
		LED = OFF;
		count++;       
	}
	if(count == 100)
	{
		ok = 0;
        if(flag >= 0)
        {
        	flag+= 10;
        }
	}  
 }
	
int Default_Mode()
{   
   L_LED = OFF;
   R_LED = OFF;
   ok = 0; 
   ok_LC = 0;
   ok_H = 0;
   dis_N = 0;
   flag = 0;
   cnt_N = 0;
   cnt_LC = 0;
   cnt_H = 0;
   cnt_btn_H = 0; 
   key_Select();
   return 0;
}

void Normal_Mode(int LED, int btn)
{ 
  if(H_btn == LOW)
  {
      LEDs_Correction(LED); 
	  if(btn == HIGH)
	  {
		flag = -1;
		Blink(LED);		
	  }
	  else 
	  {
		if(dis_N == 10)
		{
		  Default_Mode();
		}
		dis_N++;
	  } 
   }
	else
	{
		Hazard_Mode();
	}
  }

int LC_Mode(int LED, int btn)
{
  if(H_btn == LOW)
  {
    LEDs_Correction(LED);
    if(btn == HIGH)
    {   
      cnt_LC++; 
      ok_LC = 1;
    }
    if(cnt_LC <= 50)
    {
      if(cnt_LC <= 50 && ok_LC == 1)
      {
        if(flag < 30)
        {
          Blink(LED);
        } 
       else if(flag >=30 && btn == LOW)
       {
         Default_Mode();
       }
      }
    }
    else
    {
      Normal_Mode(LED, btn);    
    }
  }
  else
  {
    Hazard_Mode();
  }
  return 0;
}

int Hazard_Mode()
{
  if(H_btn == HIGH)
  {
    if(ok_H == 0)
    {
      cnt_btn_H++;
    }
    if(cnt_btn_H == 20)
    {
      ok_H = 1;
    }
    if(ok_H == 1)
    {
      f_H = 1;
      if(cnt_H < 50)
      {
        L_LED = ON;
        R_LED = ON;
        cnt_H++;    
      }
      else if(cnt_H >=50)
      {
        L_LED = OFF;
        R_LED = OFF;
        cnt_H++; 
      }
      if(cnt_H == 100)
      {
        cnt_H = 0;
      }
    }
  }
  else if(ok_H == 1)
  {
    cnt_btn_H--;
    if(cnt_btn_H == 0)
    {      
      Default_Mode();
    }
  }
  return 0;
  
}
  
int LEDs_Correction(int LED)
{
   if(LED == L_LED)
    {
      R_LED = OFF;
    }
    else if(LED == R_LED)
    {
      L_LED = OFF;
    }  
   return 0;
}

void key_Select()
{
	 if(L_btn == HIGH || (L_btn == LOW && cnt_LC != 0))
   {
     key = 1;       
   }
   else if(R_btn == HIGH || (R_btn == LOW && cnt_LC != 0))
   {
     key = 2;
   }
   else if(H_btn == HIGH)
   {
     key = 3;
   }
   else if(L_btn == LOW && R_btn == LOW && H_btn == LOW)
   {
     key = 0;
   }  
 
}
