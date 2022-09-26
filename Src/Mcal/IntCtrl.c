/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl.c
 *        \brief  Nested Vector Interrupt Controller (NVIC) Driver
 *
 *      \details The driver configure all MCU interrupts priority groups and subgroups 
*                and enables NVIC snterrupt gate for peripherals
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static uint32 intNum;
static uint8 groupPri;
static uint8 subgroupPri;

static uint8 EN_Index;
static uint8 EN_BitOffset;
static uint32 EN_Offset;

static uint8 PRI_Index;
static uint8 PRI_BitOffset;
static uint32 PRI_Offset;

static uint8 priority;
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : GroupSystem_Set(uint8 setNum)        
* \Description     : Set the group/subgroup system                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : groupSys   Number corresponding to group system configuration                     
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/
void Set_GroupSystem(uint8 groupSys)
{
    switch(groupSys)
    {
        case 1:
            SCB_APINT = SCB_APINT_VECTKEY | SCB_APINT_PRIGROUP_XXX;
            break;

        case 2:
            SCB_APINT = SCB_APINT_VECTKEY | SCB_APINT_PRIGROUP_XXY;
            break;

        case 3:
            SCB_APINT = SCB_APINT_VECTKEY | SCB_APINT_PRIGROUP_XYY;
            break;

        case 4:
            SCB_APINT = SCB_APINT_VECTKEY | SCB_APINT_PRIGROUP_YYY;
            break;
    }
}

/******************************************************************************
* \Syntax          : Get_Priority(uint8 groupSys, uint8 groupPriority, uint8 subgroupPriority)       
* \Description     : Set the encoded priority                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : groupSys           Number corresponding to one system  
                     groupPriority      Group priority
                     subgroupPriority   Sub-group priority
* \Parameters (out): priority           Encoded priority                                                       
* \Return value:   : None                                  
*******************************************************************************/

void Get_Priority(uint8 groupSys, uint8 groupPriority, uint8 subgroupPriority)
{
    switch(groupSys)
    {
        case 1:
            priority =  groupPriority;
            break;

        case 2:
            priority = (groupPriority << 1) + subgroupPriority;
            break;

        case 3:
            priority = (groupPriority << 2) + subgroupPriority;
            break;

        case 4:
            priority = subgroupPriority;
            break;
    }
}

/******************************************************************************
* \Syntax          : IntCtrl_Init(void)        
* \Description     : Initialize the NVIC and SCB module by setting the interrupt
                     congiguration                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : None                                
*******************************************************************************/

void IntCtrl_Init(void)
{
    /*Enable the gates to the interrupts using CPS instruction set*/
	__asm__("CPSIE f");	  /*Set FAULTMASK*/
    __asm__("CPSIE i");   /* Set PRIMASK*/  


    /*Configure group/ub-group system in APINT register in SCB*/
    Set_GroupSystem(Group_System);

    for(uint8 i = 0; i < ACTIVATED_INT_NUM; i++)
    {
        intNum = IntCtrl_Cfg_UserDefined[i].interruptNumber;
        groupPri = IntCtrl_Cfg_UserDefined[i].groupPriority;
        subgroupPri = IntCtrl_Cfg_UserDefined[i].subgroupPriority;

        EN_Index = intNum/32;
        EN_BitOffset = intNum%32;
        EN_Offset = NVIC_EN_Base_Offset + 4*EN_Index;

        PRI_Index = intNum/4;
        PRI_BitOffset = (intNum - 4*PRI_Index)*8 + 5;
        PRI_Offset = NVIC_PRI_Base_Offset + 4*PRI_Index;

        Get_Priority(Group_System, groupPri, subgroupPri);

        /*Assign group/ub-group priority in NVIC_PRIx NVIC register*/ 
        (*((volatile uint32 *)(CORTEXM4_PERI_BASE + PRI_Offset))) |= priority << PRI_BitOffset;
        /*TODO: Assign group/ub-group priority in SCB_SYSPRIx register*/ 

        /*Enable/Disable based on user configurations in NVIC_ENx register*/ 
        (*((volatile uint32 *)(CORTEXM4_PERI_BASE + EN_Offset))) |= 1 << EN_BitOffset;
        /*TODO: Enable/Disable based on user configurations in SCB_Sys register*/ 



    }
}

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/
