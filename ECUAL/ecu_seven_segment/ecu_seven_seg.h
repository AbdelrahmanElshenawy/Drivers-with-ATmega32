/*=================================================================================
*   @file       ecu_seven_seg.h
*   @brief		Includes the data types, macros definitions and function prototypes 
*   @details    ecu_seven_seg.h File 
				This file contains data types, macros definitions and function prototypes
*   @author     Abdelrahman Ahmed Elshenawy 
===================================================================================*/

#ifndef ECU_SEVEN_SEG_H
#define ECU_SEVEN_SEG_H



/*	Section: Includes*/
#include "ecu_seven_seg_cfg.h"
#include "../../MCAL/hal_gpio/hal_gpio.h"


/*	Section: Data Types Declarations*/
	
typedef struct{
	pin_config_t seven_seg_pins_config[4];
	seven_seg_type_t seven_seg_type;
	}seven_seg_config_t; 
	
	
/*	Section: Macro Definitions*/



/*	Section: Macro Functions Declarations*/


/*	Section: Functions Declarations*/

/*
*	@brief		Initializing the seven segment
*	@param		seven_seg_config	pointer to seven segment configurations	   @ref	seven_seg_config_t
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/
Std_ReturnType ecu_seven_seg_initialize(seven_seg_config_t *seven_seg_config);
/*
*	@brief		Writing a specific number to the seven segment
*	@param		seven_seg_config	pointer to seven segment configurations	   @ref	seven_seg_config_t
*				number				number to be written	(note that number must be from 0 to 9, else will return E_NOT_OK)
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/

Std_ReturnType ecu_seven_seg_write_number(seven_seg_config_t *seven_seg_config , uint8 number);



#endif /*ifndef ECU_SEVEN_SEG_H*/

