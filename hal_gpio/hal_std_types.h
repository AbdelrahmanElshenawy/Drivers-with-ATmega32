/*=================================================================================
*   @file       hal_std_types.h
*   @brief		Typedefs and data types used by several modules
*   @details    hal_std_types.h File 
				contains data types and typedefs that used by the software interfaces in several modules 
*   @author     Abdelrahman Ahmed Elshenawy 
===================================================================================*/

#ifndef HAL_STD_TYPES_H
#define HAL_STD_TYPES_H

/*	Section: Includes*/
#include "std_libraries.h"

/*	Section: Data Types Declarations*/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef uint8 Std_ReturnType;


/*	Section: Macro Definitions*/
#define NULL			0x00U

#define CONFIG_ENABLE	0x01U
#define CONFIG_DISABLE	0x00U

#define PORT_INPUT		0x00U
#define PORT_OUTPUT		0xffU

#define ALL_ONES		0xffU

#define	STD_HIGH		0x01U
#define STD_LOW			0x00U

#define STD_ON			0x01U
#define STD_OFF			0x00U

#define STD_ACTIVE		0x01U
#define STD_IDLE		0x00U

#define  E_OK			(Std_ReturnType)0x01
#define  E_NOT_OK		(Std_ReturnType)0x00

/*	Section: Macro Functions Declarations*/


/*	Section: Functions Declarations*/

#endif /*ifndef HAL_STD_TYPES_H*/

