/*******************************************************************************
* File Name: BackLight_On_P.h  
* Version 2.5
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_BackLight_On_P_H) /* Pins BackLight_On_P_H */
#define CY_PINS_BackLight_On_P_H

#include "cytypes.h"
#include "cyfitter.h"
#include "BackLight_On_P_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    BackLight_On_P_Write(uint8 value) ;
void    BackLight_On_P_SetDriveMode(uint8 mode) ;
uint8   BackLight_On_P_ReadDataReg(void) ;
uint8   BackLight_On_P_Read(void) ;
uint8   BackLight_On_P_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define BackLight_On_P_DRIVE_MODE_BITS        (3)
#define BackLight_On_P_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - BackLight_On_P_DRIVE_MODE_BITS))
#define BackLight_On_P_DRIVE_MODE_SHIFT       (0x00u)
#define BackLight_On_P_DRIVE_MODE_MASK        (0x07u << BackLight_On_P_DRIVE_MODE_SHIFT)

#define BackLight_On_P_DM_ALG_HIZ         (0x00u << BackLight_On_P_DRIVE_MODE_SHIFT)
#define BackLight_On_P_DM_DIG_HIZ         (0x01u << BackLight_On_P_DRIVE_MODE_SHIFT)
#define BackLight_On_P_DM_RES_UP          (0x02u << BackLight_On_P_DRIVE_MODE_SHIFT)
#define BackLight_On_P_DM_RES_DWN         (0x03u << BackLight_On_P_DRIVE_MODE_SHIFT)
#define BackLight_On_P_DM_OD_LO           (0x04u << BackLight_On_P_DRIVE_MODE_SHIFT)
#define BackLight_On_P_DM_OD_HI           (0x05u << BackLight_On_P_DRIVE_MODE_SHIFT)
#define BackLight_On_P_DM_STRONG          (0x06u << BackLight_On_P_DRIVE_MODE_SHIFT)
#define BackLight_On_P_DM_RES_UPDWN       (0x07u << BackLight_On_P_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define BackLight_On_P_MASK               BackLight_On_P__MASK
#define BackLight_On_P_SHIFT              BackLight_On_P__SHIFT
#define BackLight_On_P_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BackLight_On_P_PS                     (* (reg32 *) BackLight_On_P__PS)
/* Port Configuration */
#define BackLight_On_P_PC                     (* (reg32 *) BackLight_On_P__PC)
/* Data Register */
#define BackLight_On_P_DR                     (* (reg32 *) BackLight_On_P__DR)
/* Input Buffer Disable Override */
#define BackLight_On_P_INP_DIS                (* (reg32 *) BackLight_On_P__PC2)


#if defined(BackLight_On_P__INTSTAT)  /* Interrupt Registers */

    #define BackLight_On_P_INTSTAT                (* (reg32 *) BackLight_On_P__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins BackLight_On_P_H */


/* [] END OF FILE */
