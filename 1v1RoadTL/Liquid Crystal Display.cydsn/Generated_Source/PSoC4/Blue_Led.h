/*******************************************************************************
* File Name: Blue_Led.h  
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

#if !defined(CY_PINS_Blue_Led_H) /* Pins Blue_Led_H */
#define CY_PINS_Blue_Led_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Blue_Led_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Blue_Led_Write(uint8 value) ;
void    Blue_Led_SetDriveMode(uint8 mode) ;
uint8   Blue_Led_ReadDataReg(void) ;
uint8   Blue_Led_Read(void) ;
uint8   Blue_Led_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Blue_Led_DRIVE_MODE_BITS        (3)
#define Blue_Led_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Blue_Led_DRIVE_MODE_BITS))
#define Blue_Led_DRIVE_MODE_SHIFT       (0x00u)
#define Blue_Led_DRIVE_MODE_MASK        (0x07u << Blue_Led_DRIVE_MODE_SHIFT)

#define Blue_Led_DM_ALG_HIZ         (0x00u << Blue_Led_DRIVE_MODE_SHIFT)
#define Blue_Led_DM_DIG_HIZ         (0x01u << Blue_Led_DRIVE_MODE_SHIFT)
#define Blue_Led_DM_RES_UP          (0x02u << Blue_Led_DRIVE_MODE_SHIFT)
#define Blue_Led_DM_RES_DWN         (0x03u << Blue_Led_DRIVE_MODE_SHIFT)
#define Blue_Led_DM_OD_LO           (0x04u << Blue_Led_DRIVE_MODE_SHIFT)
#define Blue_Led_DM_OD_HI           (0x05u << Blue_Led_DRIVE_MODE_SHIFT)
#define Blue_Led_DM_STRONG          (0x06u << Blue_Led_DRIVE_MODE_SHIFT)
#define Blue_Led_DM_RES_UPDWN       (0x07u << Blue_Led_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define Blue_Led_MASK               Blue_Led__MASK
#define Blue_Led_SHIFT              Blue_Led__SHIFT
#define Blue_Led_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Blue_Led_PS                     (* (reg32 *) Blue_Led__PS)
/* Port Configuration */
#define Blue_Led_PC                     (* (reg32 *) Blue_Led__PC)
/* Data Register */
#define Blue_Led_DR                     (* (reg32 *) Blue_Led__DR)
/* Input Buffer Disable Override */
#define Blue_Led_INP_DIS                (* (reg32 *) Blue_Led__PC2)


#if defined(Blue_Led__INTSTAT)  /* Interrupt Registers */

    #define Blue_Led_INTSTAT                (* (reg32 *) Blue_Led__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins Blue_Led_H */


/* [] END OF FILE */
