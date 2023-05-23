/*******************************************************************************
* File Name: Blue_Led.c  
* Version 2.5
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Blue_Led.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Blue_Led_PC =   (Blue_Led_PC & \
                                (uint32)(~(uint32)(Blue_Led_DRIVE_MODE_IND_MASK << (Blue_Led_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Blue_Led_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Blue_Led_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void Blue_Led_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Blue_Led_DR & (uint8)(~Blue_Led_MASK));
    drVal = (drVal | ((uint8)(value << Blue_Led_SHIFT) & Blue_Led_MASK));
    Blue_Led_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Blue_Led_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Blue_Led_DM_STRONG     Strong Drive 
*  Blue_Led_DM_OD_HI      Open Drain, Drives High 
*  Blue_Led_DM_OD_LO      Open Drain, Drives Low 
*  Blue_Led_DM_RES_UP     Resistive Pull Up 
*  Blue_Led_DM_RES_DWN    Resistive Pull Down 
*  Blue_Led_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Blue_Led_DM_DIG_HIZ    High Impedance Digital 
*  Blue_Led_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Blue_Led_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Blue_Led__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Blue_Led_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Blue_Led_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Blue_Led_Read(void) 
{
    return (uint8)((Blue_Led_PS & Blue_Led_MASK) >> Blue_Led_SHIFT);
}


/*******************************************************************************
* Function Name: Blue_Led_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Blue_Led_ReadDataReg(void) 
{
    return (uint8)((Blue_Led_DR & Blue_Led_MASK) >> Blue_Led_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Blue_Led_INTSTAT) 

    /*******************************************************************************
    * Function Name: Blue_Led_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Blue_Led_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Blue_Led_INTSTAT & Blue_Led_MASK);
		Blue_Led_INTSTAT = maskedStatus;
        return maskedStatus >> Blue_Led_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
