/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c.c
 *        \brief  Digital In/Out (DIO) Driver
 *
 *      \details The driver deals with the read/write operations of digital pins
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

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
* \Syntax          : Dio_ReadChannel(Dio_ChannelType ChannelID)       
* \Description     : Read the level of the specified pin                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelID  Pin index of enum Dio_ChannelType                    
* \Parameters (out): None                                                    
* \Return value:   : Dio_LevelType (High/Low)                                  
*******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelID)
{
    uint8 pinOffset = ChannelID%8;
    uint8 portIndex = ChannelID/8;
    Dio_LevelType level = (((GPIODATA_PORTx_APB_M(portIndex,1,pinOffset)) & (1<<pinOffset))>>pinOffset);
    return  level;
}
/******************************************************************************
* \Syntax          : Dio_WriteChannel(Dio_ChannelType ChannelID, Dio_LevelType Level)       
* \Description     : Write the Level to the specified pin                                
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelID  Pin index of enum Dio_ChannelType   
                     Level      Pin level of enum Dio_LevelType
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelID, Dio_LevelType Level)
{
    uint8 pinOffset = ChannelID%8;
    uint8 portIndex = ChannelID/8;
    switch (Level)
      {
      case DIO_LOW:
        GPIODATA_PORTx_APB_M(portIndex,1,pinOffset) &= (~(1<<pinOffset));
        break;
      case DIO_HIGH:
        GPIODATA_PORTx_APB_M(portIndex,1,pinOffset) |= (1<<pinOffset);
        break;
      default:
        break;
    }
}
/******************************************************************************
* \Syntax          : Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelID)       
* \Description     : Write the Level to the specified pin                                
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelID  Pin index of enum Dio_ChannelType   
                     Level      Pin level of enum Dio_LevelType
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelID)
{
    uint8 pinOffset = ChannelID%8;
    uint8 portIndex = ChannelID/8;
    Dio_WriteChannel(ChannelID, !(Dio_ReadChannel(ChannelID)));
}
/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType PortID)       
* \Description     : Read the level of the specified port                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortID  Port index of enum Dio_PortType                    
* \Parameters (out): None                                                    
* \Return value:   : Dio_PortLevelType      0 —> 255                                 
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortID)
{
    Dio_PortLevelType level = GPIODATA_PORTx_APB_M(PortID,255,0);
    return  level;
}
/******************************************************************************
* \Syntax          : Dio_WritePort(Dio_PortType PortID, Dio_PortLevelType Level)       
* \Description     : Read the level of the specified port                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortID  Port index of enum Dio_PortType                    
* \Parameters (out): None                                                    
* \Return value:   : Dio_PortLevelType      0 —> 255                                 
*******************************************************************************/
void Dio_WritePort(Dio_PortType PortID, Dio_PortLevelType Level)
{
    GPIODATA_PORTx_APB_M(PortID,255,0) |= Level;
}

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
