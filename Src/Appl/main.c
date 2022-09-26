#include "IntCtrl.h"
#include "Dio.h"
#include "Port.h"
#include "SysTick.h"

#define SYS_CLOCK
#define ON_TIME 									4									/* in sec*/
#define OFF_TIME 									1									/* in sec*/
#define ACTIVATED_PORT_NUM				3		

static const onTick = (SYS_CLOCK-1)*ON_TIME;
static const offTick = (SYS_CLOCK-1)*OFF_TIME;
volatile boolean state = 0;
static uint32 count = 0;
void SysTick_Handler(void);

/* User-defined configuration structs */
static Port_CfgType portCfg[]= {
																		{DIO_PF1, PORT_DIO, DIO_LOW, PORT_OUTPUT, PORT_DEFAULT_IA, PORT_DR2R},			/*RED LED*/
																		{DIO_PF4, PORT_DIO, DIO_LOW, PORT_INPUT, PORT_PUR, PORT_DR2R},							/*SW1*/
																		{DIO_PF0, PORT_DIO, DIO_LOW, PORT_INPUT, PORT_PUR, PORT_DR2R}								/*SW2*/
																};

																
static SysTick_CfgType sysTickCfg[]={
																			{0, 0, SYSTICK_EN, SYSTICK_INT_EN, SYSTICK_SYS_CLOCK},
																			{onTick, 0, SYSTICK_EN, SYSTICK_INT_EN, SYSTICK_SYS_CLOCK},
																			{offTick, 0, SYSTICK_EN, SYSTICK_INT_EN, SYSTICK_SYS_CLOCK},
																		};


																		
int main(void)
{
	IntCtrl_Init();
	Port_Init(portCfg,ACTIVATED_PORT_NUM);
	SysTick_Init(sysTickCfg+2);
	
	while(1)
	{	
		
		if(Dio_ReadChannel(portCfg[1].pin) == 0x00)
		{
			/*SW1 is pressed*/
			count ++;
		}
		
		if(Dio_ReadChannel(portCfg[2].pin) == 0x00)
		{
			/*SW2 is pressed*/
			count --;
		}
	}
}

void SysTick_Handler(void)
{
	if(state)
	{
		SetReload(sysTickCfg[2].ReloadValue);
		Dio_FlipChannel(portCfg[0].pin);
		state = 0;
	}
	else
	{
		SetReload(sysTickCfg[1].ReloadValue);
		Dio_FlipChannel(portCfg[0].pin);
		state = 1;
	}
}

