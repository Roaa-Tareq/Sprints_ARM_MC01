/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  -
 *
 *  Description:  Header file of micro-controller registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint32  VECACT      :8;
    uint32              :3;
    uint32  RETBASE     :1;
    uint32  VECPEND     :8;
    uint32              :2;
    uint32  ISRPEND     :1;
    uint32  ISRPRE      :1;
    uint32              :1;
    uint32  PENDSTCLR   :1;
    uint32  PENDSTSET   :1;
    uint32  UNPENDSV    :1;
    uint32  PENDSV      :1;
    uint32              :2;
    uint32  NMISET      :1;
}INTCTRL_BF;

typedef union
{
    uint32 R;
    INTCTRL_BF B;
}INCTRL_TAG;

typedef struct 
{
    uint32  VECTRESET   :1;
    uint32  VECTCLRACT  :1;
    uint32  SYSRESREQ   :1;
    uint32              :5;
    uint32  PRIGROUP    :3;
    uint32              :4;
    uint32  ENDIANESS   :1;
    uint32  VECTKEY     :16;
}APINT_BF;

typedef union
{
    uint32 R;
    APINT_BF B;
}APINT_TAG;


/**********************************************************************************************************************
 *  GLOBAL CONSTANT 
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE 0xE000E000 //Cortex-M4 Peripherals Base Address
///System Timer (SysTick) Register///
#define SysTick_STCTRL         (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x010)))
#define SysTick_STRELOAD       (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x014)))
#define SysTick_STCURRENT      (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x018)))
///Nested Vectored Interrupt Controller (NVIC) Registers///
#define NVIC_EN_Base_Offset    0x100             
#define NVIC_EN0               (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x100)))
#define NVIC_EN1               (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x104)))
#define NVIC_EN2               (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x108)))
#define NVIC_EN3               (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x10C)))
#define NVIC_EN4               (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x110)))
#define NVIC_DIS0              (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x180)))
#define NVIC_DIS1              (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x184)))
#define NVIC_DIS2              (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x188)))
#define NVIC_DIS3              (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x18C)))
#define NVIC_DIS4              (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x190)))
#define NVIC_PEND0             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x200)))
#define NVIC_PEND1             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x204)))
#define NVIC_PEND2             (*((volatile uint32 *)(CORTEXM4_P_BASE + 0x208)))
#define NVIC_PEND3             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x20C)))
#define NVIC_PEND4             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x210)))
#define NVIC_UNPEND0           (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x280)))
#define NVIC_UNPEND1           (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x284)))
#define NVIC_UNPEND3           (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x28C)))
#define NVIC_UNPEND4           (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x290)))
#define NVIC_ACTIVE0           (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x300)))
#define NVIC_ACTIVE1           (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x304)))
#define NVIC_ACTIVE2           (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x308)))
#define NVIC_ACTIVE3           (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x30C)))
#define NVIC_ACTIVE4           (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x310)))
#define NVIC_PRI_Base_Offset    0x400
#define NVIC_PRI0              (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x400)))
#define NVIC_PRI1              (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x404)))
#define NVIC_PRI2              (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x408)))
#define NVIC_PRI3              (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x40C)))
#define NVIC_PRI4              (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x410)))
#define NVIC_PRI5              (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x414)))
#define NVIC_PRI6              (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x418)))
#define NVIC_PRI7              (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x41C)))
#define NVIC_PRI8              (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x420)))
#define NVIC_PRI9              (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x424)))
#define NVIC_PRI10             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x428)))
#define NVIC_PRI11             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x42C)))
#define NVIC_PRI12             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x430)))
#define NVIC_PRI13             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x434)))
#define NVIC_PRI14             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x438)))
#define NVIC_PRI15             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x43C)))
#define NVIC_PRI16             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x440)))
#define NVIC_PRI17             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x444)))
#define NVIC_PRI18             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x448)))
#define NVIC_PRI19             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x44C)))
#define NVIC_PRI20             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x450)))
#define NVIC_PRI21             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x454)))
#define NVIC_PRI22             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x458)))
#define NVIC_PRI23             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x45C)))
#define NVIC_PRI24             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x460)))
#define NVIC_PRI25             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x464)))
#define NVIC_PRI26             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x468)))
#define NVIC_PRI27             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x46C)))
#define NVIC_PRI28             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x470)))
#define NVIC_PRI29             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x474)))
#define NVIC_PRI30             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x478)))
#define NVIC_PRI31             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x47C)))
#define NVIC_PRI32             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x480)))
#define NVIC_PRI33             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x484)))
#define NVIC_PRI34             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0x488)))
///System Control Block (SCB) Registers///
#define SCB_INTCTRL           (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0xD0C))) 
#define SCB_APINT             (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0xD0C))) 
#define SCB_SYS_CTRL          (*((volatile uint32 *)(CORTEXM4_P_BASE + 0xD10)))
#define SCB_SYS_PRI1          (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0xD18)))
#define SCB_SYS_PRI2          (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0xD1C)))
#define SCB_SYS_PRI3          (*((volatile uint32 *)(CORTEXM4_PERI_BASE + 0xD20)))

///GPIO Registers///
#define GPIO_APB_BASE        0X40004000
#define GPIO_AHB_BASE        0X40058000

#define GPIODATA_OFFSET      0x000
#define GPIODIR_OFFSET       0x400
#define GPIOFSEL_OFFSET      0x420
#define GPIODR2R_OFFSET      0x500
#define GPIODR4R_OFFSET      0x504
#define GPIODR8R_OFFSET      0x508
#define GPIOODR_OFFSET       0x50C
#define GPIOPUR_OFFSET       0x510
#define GPIOPDR_OFFSET       0x514
#define GPIODEN_OFFSET       0x51C
#define GPIOLOCK_OFFSET      0x520
#define GPIOCR_OFFSET        0x524

#define GPIO_PORTx_APB_BASE(n)   (*((volatile uint32 *)(GPIO_APB_BASE + (n%4)*0x1000 + (n/4)*0x20000)))
#define GPIODATA_PORTx_APB(n)    (*((volatile uint32 *)(GPIO_APB_BASE + (n%4)*0x1000 + (n/4)*0x20000 + GPIODATA_OFFSET)))
#define GPIODATA_PORTx_APB_M(n,v,m)    (*((volatile uint32 *)(GPIO_APB_BASE + (n%4)*0x1000 + (n/4)*0x20000 + GPIODATA_OFFSET + (v<<(m+2))))) //n: Port number, v: set bits, m: offset of set bits
                                                                                                                                             //v<<(m+2) to add the mask, 4 = 1<<2
#define GPIODIR_PORTx_APB(n)     (*((volatile uint32 *)(GPIO_APB_BASE + (n%4)*0x1000 + (n/4)*0x20000 + GPIODIR_OFFSET)))
#define GPIOFSEL_PORTx_APB(n)    (*((volatile uint32 *)(GPIO_APB_BASE + (n%4)*0x1000 + (n/4)*0x20000 + GPIOFSEL_OFFSET)))
#define GPIODR2R_PORTx_APB(n)    (*((volatile uint32 *)(GPIO_APB_BASE + (n%4)*0x1000 + (n/4)*0x20000 + GPIODR2R_OFFSET)))
#define GPIODR4R_PORTx_APB(n)    (*((volatile uint32 *)(GPIO_APB_BASE + (n%4)*0x1000 + (n/4)*0x20000 + GPIODR4R_OFFSET)))
#define GPIODR8R_PORTx_APB(n)    (*((volatile uint32 *)(GPIO_APB_BASE + (n%4)*0x1000 + (n/4)*0x20000 + GPIODR8R_OFFSET)))
#define GPIOODR_PORTx_APB(n)     (*((volatile uint32 *)(GPIO_APB_BASE + (n%4)*0x1000 + (n/4)*0x20000 + GPIOODR_OFFSET)))
#define GPIOPUR_PORTx_APB(n)     (*((volatile uint32 *)(GPIO_APB_BASE + (n%4)*0x1000 + (n/4)*0x20000 + GPIOPUR_OFFSET)))
#define GPIOPDR_PORTx_APB(n)     (*((volatile uint32 *)(GPIO_APB_BASE + (n%4)*0x1000 + (n/4)*0x20000 + GPIOPDR_OFFSET)))
#define GPIODEN_PORTx_APB(n)     (*((volatile uint32 *)(GPIO_APB_BASE + (n%4)*0x1000 + (n/4)*0x20000 + GPIODEN_OFFSET)))
#define GPIOLOCK_PORTx_APB(n)    (*((volatile uint32 *)(GPIO_APB_BASE + (n%4)*0x1000 + (n/4)*0x20000 + GPIOLOCK_OFFSET)))
#define GPIOCR_PORTx_APB(n)      (*((volatile uint32 *)(GPIO_APB_BASE + (n%4)*0x1000 + (n/4)*0x20000 + GPIOCR_OFFSET)))

#define GPIO_PORTx_AHB_BASE(n)   (*((volatile uint32 *)(GPIO_AHB_BASE + (n%4)*0x1000)))
#define GPIODATA_PORTx_AHB(n)    (*((volatile uint32 *)(GPIO_AHB_BASE + (n%4)*0x1000 + GPIODATA_OFFSET)))
#define GPIODIR_PORTx_AHB(n)     (*((volatile uint32 *)(GPIO_AHB_BASE + (n%4)*0x1000 + GPIODIR_OFFSET)))
#define GPIOFSEL_PORTx_AHB(n)    (*((volatile uint32 *)(GPIO_AHB_BASE + (n%4)*0x1000 + GPIOFSEL_OFFSET)))
#define GPIODR2R_PORTx_AHB(n)    (*((volatile uint32 *)(GPIO_AHB_BASE + (n%4)*0x1000 + GPIODR2R_OFFSET)))
#define GPIODR4R_PORTx_AHB(n)    (*((volatile uint32 *)(GPIO_AHB_BASE + (n%4)*0x1000 + GPIODR4R_OFFSET)))
#define GPIODR8R_PORTx_AHB(n)    (*((volatile uint32 *)(GPIO_AHB_BASE + (n%4)*0x1000 + GPIODR8R_OFFSET)))
#define GPIOODR_PORTx_AHB(n)     (*((volatile uint32 *)(GPIO_AHB_BASE + (n%4)*0x1000 + GPIOODR_OFFSET)))
#define GPIOPUR_PORTx_AHB(n)     (*((volatile uint32 *)(GPIO_AHB_BASE + (n%4)*0x1000 + GPIOPUR_OFFSET)))
#define GPIOPDR_PORTx_AHB(n)     (*((volatile uint32 *)(GPIO_AHB_BASE + (n%4)*0x1000 + GPIOPDR_OFFSET)))
#define GPIODEN_PORTx_AHB(n)     (*((volatile uint32 *)(GPIO_AHB_BASE + (n%4)*0x1000 + GPIODEN_OFFSET)))

///System Control Registers (SysCtl)///
#define SYSCTL_RCGCGPIO       (*((volatile uint32 *)0x400FE608))
//Clock Gating Control
#define SYSCTL_RCGC_GPIOF      0x00000020  
#define SYSCTL_RCGC_GPIOE      0x00000010  
#define SYSCTL_RCGC_GPIOD      0x00000008  
#define SYSCTL_RCGC_GPIOC      0x00000004  
#define SYSCTL_RCGC_GPIOB      0x00000002  
#define SYSCTL_RCGC_GPIOA      0x00000001 

///General Purpose Timer Module (GPTM) Registers///
#define GPT_BASE                0x40030000
#define GPT_16_32_TIMERx(x)     (*((volatile uint32 *)(GPT_BASE + x*0x10000)))
#define GPT_32_64_TIMERx(x)     (*((volatile uint32 *)(GPT_BASE + 0x60000 + x*0x10000)))

#define GPTMCFG_OFFSET          0X000
#define GPTMTxMR_OFFSET(n)      0X004*(n+1)         // x = A —> n = 0 and x = B —> n = 1
#define GPTMCTL_OFFSET          0X00C
#define GPTMIMR_OFFSET          0X018
#define GPTMTxILR_OFFSET(n)     0X028 + 0X004*n
#define GPTMTxPR_OFFSET(n)      0X038 + 0X004*n
#define GPTMTxV_OFFSET(n)       0X050 + 0X004*n
#define GPTMTxPV_OFFSET(n)      0X064 + 0X004*n
#define GPTMPP_OFFSET           0XFC0


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /*MCU_HW_H*/

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
