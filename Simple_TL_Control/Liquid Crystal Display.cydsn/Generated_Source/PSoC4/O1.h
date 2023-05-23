/*******************************************************************************
* File Name: O1.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_O1_H) /* Pins O1_H */
#define CY_PINS_O1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "O1_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} O1_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   O1_Read(void);
void    O1_Write(uint8 value);
uint8   O1_ReadDataReg(void);
#if defined(O1__PC) || (CY_PSOC4_4200L) 
    void    O1_SetDriveMode(uint8 mode);
#endif
void    O1_SetInterruptMode(uint16 position, uint16 mode);
uint8   O1_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void O1_Sleep(void); 
void O1_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(O1__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define O1_DRIVE_MODE_BITS        (3)
    #define O1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - O1_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the O1_SetDriveMode() function.
         *  @{
         */
        #define O1_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define O1_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define O1_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define O1_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define O1_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define O1_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define O1_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define O1_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define O1_MASK               O1__MASK
#define O1_SHIFT              O1__SHIFT
#define O1_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in O1_SetInterruptMode() function.
     *  @{
     */
        #define O1_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define O1_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define O1_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define O1_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(O1__SIO)
    #define O1_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(O1__PC) && (CY_PSOC4_4200L)
    #define O1_USBIO_ENABLE               ((uint32)0x80000000u)
    #define O1_USBIO_DISABLE              ((uint32)(~O1_USBIO_ENABLE))
    #define O1_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define O1_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define O1_USBIO_ENTER_SLEEP          ((uint32)((1u << O1_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << O1_USBIO_SUSPEND_DEL_SHIFT)))
    #define O1_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << O1_USBIO_SUSPEND_SHIFT)))
    #define O1_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << O1_USBIO_SUSPEND_DEL_SHIFT)))
    #define O1_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(O1__PC)
    /* Port Configuration */
    #define O1_PC                 (* (reg32 *) O1__PC)
#endif
/* Pin State */
#define O1_PS                     (* (reg32 *) O1__PS)
/* Data Register */
#define O1_DR                     (* (reg32 *) O1__DR)
/* Input Buffer Disable Override */
#define O1_INP_DIS                (* (reg32 *) O1__PC2)

/* Interrupt configuration Registers */
#define O1_INTCFG                 (* (reg32 *) O1__INTCFG)
#define O1_INTSTAT                (* (reg32 *) O1__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define O1_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(O1__SIO)
    #define O1_SIO_REG            (* (reg32 *) O1__SIO)
#endif /* (O1__SIO_CFG) */

/* USBIO registers */
#if !defined(O1__PC) && (CY_PSOC4_4200L)
    #define O1_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define O1_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define O1_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define O1_DRIVE_MODE_SHIFT       (0x00u)
#define O1_DRIVE_MODE_MASK        (0x07u << O1_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins O1_H */


/* [] END OF FILE */
