/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_CFG_H
#define INTCTRL_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/***********************************************************
    SCB_APINT register configuration
************************************************************/
#define SCB_APINT_VECTKEY      0x05FA0000  // Vector key access
#define SCB_APINT_PRIGROUP_XXX 0x00000400  // 8 Group Priority and 1 Subpriorities --> bXXX
#define SCB_APINT_PRIGROUP_XXY 0x00000500  // 4 Group Priority and 2 Subpriorities --> bXXY
#define SCB_APINT_PRIGROUP_XYY 0x00000600  // 2 Group Priority and 4 Subpriorities --> bXYY
#define SCB_APINT_PRIGROUP_YYY 0x00000700  // 1 Group Priority and 8 Subpriorities --> bYYY

/***********************************************************
    SCB_SYS_PRI1, SCB_SYS_PRI2 and SCB_SYS_PRI3 registers configuration
************************************************************/
#define NVIC_SYS_PRI1_USAGE_M   0x00E00000  // Usage Fault Priority Mask
#define NVIC_SYS_PRI1_USAGE_S   21          //                      Start bit
#define NVIC_SYS_PRI1_BUS_M     0x0000E000  // Bus Fault Priority Mask
#define NVIC_SYS_PRI1_BUS_S     13          //                    Start bit    
#define NVIC_SYS_PRI1_MEM_M     0x000000E0  // Memory Management Fault Priority Mask
#define NVIC_SYS_PRI1_MEM_S     5           //                                  Start bit

#define NVIC_SYS_PRI2_SVC_M     0xE0000000  // SVCall Priority Mask
#define NVIC_SYS_PRI2_SVC_S     29          //                 Start bit

#define NVIC_SYS_PRI3_TICK_M    0xE0000000  // SysTick Exception Priority Mask
#define NVIC_SYS_PRI3_TICK_S    29          //                            Start bit
#define NVIC_SYS_PRI3_PENDSV_M  0x00E00000  // PendSV Priority Mask
#define NVIC_SYS_PRI3_PENDSV_S  21          //                 Start bit
#define NVIC_SYS_PRI3_DEBUG_M   0x000000E0  // Debug Priority Mask
#define NVIC_SYS_PRI3_DEBUG_S   5           //                Start bit

#define ACTIVATED_INT_NUM       2
#define Group_System            2

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern const    IntCtrl_CfgType    IntCtrl_Cfg_UserDefined[]; 
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* INTCTRL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/
