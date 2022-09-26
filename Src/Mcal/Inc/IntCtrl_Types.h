/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*
    PROCESSOR EXCEPTIONS
/***************************************************************/
typedef enum
{
    INTCTRL_RESET,                // 1 Reset 
    INTCTRL_NMI,                  // 2 Non Maskable Interrupt  
    INTCTRL_HARD_FAULT,           // 3 Hard Fault
    INTCTRL_MEMORY_MANAGEMENT,    // 4 Memory Management
    INTCTRL_BUS_FAULT,            // 5 Bus Fault
    INTCTRL_USAGE_FAULT,          // 6 Usage Fault
                                  // 7-10 Reserved   
    INTCTRL_SV_Call = 11,         // 11 SV Call
    INTCTRL_DEBUG_MONITOR,        // 12 Debug Monitor
    INTCTRL_RES2,                 // 13 Reserved   
    INTCTRL_PEND_SV,              // 14 Pend SV Interrupt
    INTCTRL_SYS_TICK              // 15 System Tick Interrupt
}IntCtrl_ExceptionType;

/*
    INTERRUPTS
/***************************************************************/
typedef enum
{
    INTCTRL_GPIO_PORTA = 0,          // 16—0 GPIO Port A 
    INTCTRL_GPIO_PORTB,              // 17—1 GPIO Port B    
    INTCTRL_GPIO_PORTC,              // 18—2 GPIO Port C    
    INTCTRL_GPIO_PORTD,              // 19—3 GPIO Port D    
    INTCTRL_GPIO_PORTE,              // 20—4 GPIO Port E    
    INTCTRL_UART0,                   // 21—5 UART0          
    INTCTRL_UART1,                   // 22—6 UART1          
    INTCTRL_SSI0,                    // 23—7 SSI0           
    INTCTRL_I2C0,                    // 24—8 I2C0           
    INTCTRL_PWM0_FAULT,              // 25—9 PWM0 Fault     
    INTCTRL_PWM0_GEN0,               // 26—10 PWM0 Generator 0 
    INTCTRL_PWM0_GEN1,               // 27—11 PWM0 Generator 1 
    INTCTRL_PWM0_GEN2,               // 28—12 PWM0 Generator 2 
    INTCTRL_QEI0,                    // 29—13 Quadrature Encoder 0 
    INTCTRL_ADC0_SEQ0,               // 30—14 ADC0 Sequence 0      
    INTCTRL_ADC0_SEQ1,               // 31—15 ADC0 Sequence 1      
    INTCTRL_ADC0_SEQ2,               // 32—16 ADC0 Sequence 2      
    INTCTRL_ADC0_SEQ3,               // 33—17 ADC0 Sequence 3      
    INTCTRL_WATCHDOG01,              // 34—18 Watchdog Timers 0 and 1 
    INTCTRL_16_32_TIMER0A,           // 35—19 16/32-Bit Timer 0A      
    INTCTRL_16_32_TIMER0B,           // 36—20 16/32-Bit Timer 0B      
    INTCTRL_16_32_TIMER1A,           // 37—21 16/32-Bit Timer 1A      
    INTCTRL_16_32_TIMER1B,           // 38—22 16/32-Bit Timer 1B      
    INTCTRL_16_32_TIMER2A,           // 39—23 16/32-Bit Timer 2A      
    INTCTRL_16_32_TIMER2B,           // 40—24 16/32-Bit Timer 2B      
    INTCTRL_COMP0,                   // 41—25 Analog Comparator 0     
    INTCTRL_COMP1,                   // 42—26 Analog Comparator 1     
                                     // 43—27 Reserved
    INTCTRL_SYS_CTRL = 28,           // 44—28 System Control          
    INTCTRL_FLASH_EEPROM_CTRL,       // 45—29 Flash Memory Control and EEPROM Control 
    INTCTRL_GPIO_PORTF,              // 46—30 GPIO Port F                      
                                     // (47-48)-(31-32) Reserved
    INTCTRL_USART2 = 33,             // 49-33 UART2 
    INTCTRL_SSI1,                    // 50—34 SSI1
    INTCTRL_16_32_TIMER3A,           // 51—35 16/32-Bit Timer 3A
    INTCTRL_16_32_TIMER3B,           // 52—36 16/32-Bit Timer 3B
    INTCTRL_I2C1,                    // 53—37 I2C1
    INTCTRL_QEI1,                    // 54—38 Quadrature Encoder 1             
    INTCTRL_CAN0,                    // 55—39 CAN0                             
    INTCTRL_CAN1,                    // 56—40 CAN1  
                                     // (57-58)-(41-42) Reserved
    INTCTRL_HIBERNATION = 43,        // 59—43 Hibernation Module
    INTCTRL_USB,                     // 60—44 USB                              
    INTCTRL_PWM0_GEN3                 // 61—45 PWM Generator 3                  
}IntCtrl_InterruptType;

typedef struct
{
    IntCtrl_InterruptType   interruptNumber;
    uint8                   groupPriority;
    uint8                   subgroupPriority;
}IntCtrl_CfgType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /*INTCTRL_TYPES_H*/

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
