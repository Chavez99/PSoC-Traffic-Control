/*******************************************************************************
* File Name: O1.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_O1_ALIASES_H) /* Pins O1_ALIASES_H */
#define CY_PINS_O1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define O1_0			(O1__0__PC)
#define O1_0_PS		(O1__0__PS)
#define O1_0_PC		(O1__0__PC)
#define O1_0_DR		(O1__0__DR)
#define O1_0_SHIFT	(O1__0__SHIFT)
#define O1_0_INTR	((uint16)((uint16)0x0003u << (O1__0__SHIFT*2u)))

#define O1_INTR_ALL	 ((uint16)(O1_0_INTR))


#endif /* End Pins O1_ALIASES_H */


/* [] END OF FILE */
