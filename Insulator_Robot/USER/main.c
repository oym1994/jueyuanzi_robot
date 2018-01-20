#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "dma.h"
#include "timer.h"

   	
extern RC_Ctl_t RC_CtrlData;
int speed=0;

 int main(void)
 { 

	delay_init();	    	
	LED_Init();		  		
  TIM2_PWM_Init(999,1439);	
	uart_init(100000);	 
  delay_ms(1000);
  USART1_DMA_RX();
  TIM_SetCompare2(TIM2,800);
 
	 while(1)
		 
	 {
	 speed=925+(RC_CtrlData.rc.ch3-1024)*0.03;
	 TIM_SetCompare2(TIM2,speed);
	 GPIO_SetBits(GPIOC, GPIO_Pin_7); 
	 GPIO_ResetBits(GPIOC, GPIO_Pin_8);
	 delay_ms(100);
	 GPIO_SetBits(GPIOC, GPIO_Pin_8); 
	 GPIO_ResetBits(GPIOC, GPIO_Pin_7);
	 delay_ms(100);

	 }

}
