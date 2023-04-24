/*=================================================================================
*   @file       ecu_seven_seg.c
*   @brief		Controlling the seven segment module 
*   @details    ecu_seven_seg.c File 
				This file contains function definitions that control the seven segment module
*   @author     Abdelrahman Ahmed Elshenawy 
===================================================================================*/


/*
*	@brief		Initializing the seven segment
*	@param		seven_seg_config	pointer to seven segment configurations	   @ref	seven_seg_config_t
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/
/*section : Includes*/
#include "ecu_seven_seg.h"

Std_ReturnType ecu_seven_seg_initialize(const seven_seg_config_t *seven_seg_config){
	Std_ReturnType ret = E_OK;
	if((NULL == seven_seg_config) || (seven_seg_config->seven_seg_type  > MAX_CONFIG_SEG_TYPE)){
		ret = E_NOT_OK;
	}
	
	else{
		for(uint8 pin_num = 0;pin_num < MAX_PINS_SEG_NUM ;pin_num++){	
			
			ret = gpio_pin_direction_intialize(&(seven_seg_config->seven_seg_pins_config[pin_num]));
		}
	}
	return ret;
}
/*
*	@brief		Writing a specific number to the seven segment
*	@param		seven_seg_config	pointer to seven segment configurations	   @ref	seven_seg_config_t
*				number				number to be written	(note that number must be from 0 to 9, else will return E_NOT_OK)
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/

Std_ReturnType ecu_seven_seg_write_number(const seven_seg_config_t *seven_seg_config , const uint8 number){
	Std_ReturnType ret = E_OK;
	if((NULL == seven_seg_config) ||\
	 (seven_seg_config->seven_seg_type > MAX_CONFIG_SEG_TYPE)||\
	 (number > 9)){
		ret = E_NOT_OK;
	}
	else{
		for(uint8 pin_num = 0;pin_num < MAX_PINS_SEG_NUM ;pin_num++){
			ret = gpio_pin_write_logic(&(seven_seg_config->seven_seg_pins_config[pin_num]) , (number) & (uint8)(1<<pin_num));
			if(ret == E_NOT_OK){
				break;
			}
			else{
				/*DO NOTHING*/
			}
		}
	}
	return ret;
}

