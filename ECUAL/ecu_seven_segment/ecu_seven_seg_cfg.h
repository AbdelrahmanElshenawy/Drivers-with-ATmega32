/*=================================================================================
*   @file       ecu_seven_seg.h
*   @brief		Includes the data types, macros definitions and function prototypes 
*   @details    ecu_seven_seg.h File 
				This file contains data types, macros definitions and function prototypes
*   @author     Abdelrahman Ahmed Elshenawy 
===================================================================================*/

#ifndef ECU_SEVEN_SEG_CFG_H
#define ECU_SEVEN_SEG_CFG_H

/*	Section: Data Types Declarations*/
	
typedef enum{
	SEVEN_SEGMENT_COMMON_ANODE = 0,
	SEVEN_SEGMENT_COMMON_CATHODE
	}seven_seg_type_t;
	
typedef enum{
	SEVEN_SEG_PIN0 = 0,
	SEVEN_SEG_PIN1,
	SEVEN_SEG_PIN2,
	SEVEN_SEG_PIN3
	}seven_seg_pin_t;
	
/*	Section: MACRO Definitions*/

#define MAX_CONFIG_SEG_TYPE 1	/*Two types: SEVEN_SEGMENT_COMMON_ANODE and SEVEN_SEGMENT_COMMON_CATODE*/
#define MAX_PINS_SEG_NUM	4	/*4 pins because pins are input to a decoder, then output of decoder enters the seven segment module*/

#endif /*ifndef ECU_SEVEN_CFG_SEG_H*/

