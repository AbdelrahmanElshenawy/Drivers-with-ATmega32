/*=================================================================================
*   @file       hal_gpio.h
*   @brief      Accessing General purpose I/O PORTS
*   @details    hal_gpio.h File 
				contains declarations of the software interfaces used to access I/O ports of the micro-controller 
*   @author     Abdelrahman Ahmed Elshenawy 
===================================================================================*/

#ifndef HAL_GPIO_H
#define HAL_GPIO_H

/*	Section: Includes====================================================================*/
/*
*	@brief	This includes hal_std_types.h
*/
#include "hal_std_types.h"
#include "hal_registers.h"

/*	Section: Macro Definitions===========================================================*/
#define BIT_MASK			(uint8)1
#define MAX_PORT_NUMBER		(uint8)4
#define MAX_PIN_NUMBER		(uint8)8
#define MAX_DIRECTION_VALUE (uint8)1
#define MAX_LOGIC_VALUE		(uint8)1

#define GPIO_PORT_CONFIG	CONFIG_ENABLE
#define GPIO_PIN_CONFIG		CONFIG_ENABLE

/*	Section: Macro Functions Declarations*/
#define HWREG8(_X)				 (*((volatile uint8 *)(_X)))
#define SET_BIT(REG,BIT_POSN)	 ((REG) |= (BIT_MASK << (BIT_POSN)))
#define CLEAR_BIT(REG,BIT_POSN)  ((REG) &= ~(BIT_MASK << (BIT_POSN)))
#define TOGGLE_BIT(REG,BIT_POSN) ((REG) ^= (BIT_MASK << (BIT_POSN)))
#define READ_BIT(REG,BIT_POSN)	 (((REG)>>(BIT_POSN)) & (BIT_MASK))

/*	Section: Data Types Declarations=====================================================*/

typedef enum{
	LOW = 0,
	HIGH
	}logic_t;
	
typedef enum{
	INPUT = 0,
	OUTPUT
}direction_t;

typedef enum{
	PIN0 = 0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}pin_index_t;

typedef enum{
	PORTA_INDEX = 0,
	PORTB_INDEX,
	PORTC_INDEX,
	PORTD_INDEX	
}port_index_t;
	

typedef struct{
	port_index_t port : 2; 
	pin_index_t pin	: 3;
	direction_t direction : 1;
	logic_t logic : 1;
	
}pin_config_t;

	

/*	Section: Functions Declarations======================================================*/

/*
*	@brief		Initializing the direction of pin
*	@param		_pin_config pointer to pin configurations @ref	pin_config_t
*	@return		Status of the function
*				(E_OK)		The function works successfully 
*				(E_NOT_OK)	The function has some issues
*/
Std_ReturnType gpio_pin_direction_intialize(const pin_config_t *_pin_config);
/*
*	@brief		Getting the direction of pin using a pointer to direction_t enum variable
*	@param		_pin_config			pointer to pin configurations	   @ref	pin_config_t
				direction_status	pointer to direction enum variable @ref direction_t
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config , direction_t * direction_status);
/*
*	@brief		Writing the logic HIGH or LOW to the pin
*	@param		_pin_config			pointer to pin configurations	   @ref	pin_config_t
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config ,const logic_t logic);
/*
*	@brief		Reading the logic HIGH or LOW of the pin through pointer to logic_t
*	@param		_pin_config			pointer to pin configurations		@ref pin_config_t
*				logic				pointer to logic_t					@ref logic_t
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config , logic_t *logic);
/*
*	@brief		Toggle the pin logic
*	@param		_pin_config			pointer to pin configurations	   @ref	pin_config_t
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config);

/*
*	@brief		Initializing the port direction
*	@param		port			pointer to enum type 	  @ref port_index_t
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/
Std_ReturnType gpio_port_direction_intialize(const port_index_t port , const direction_t direction);
/*
*	@brief		Getting the port direction
*	@param		port				pointer to enum type 	  @ref port_index_t
*				direction_status	pointer to enum type	  @ref direction_t
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/
Std_ReturnType gpio_port_get_direction_status(const port_index_t port , direction_t * direction_status);
/*
*	@brief		Writing logic or value to the port
*	@param		port			pointer to enum type 	  @ref port_index_t
*				logic			the value required to be written
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/
Std_ReturnType gpio_port_write_logic(const port_index_t port, const uint8 value);
/*
*	@brief		Reading the port logic or value
*	@param		port			pointer to enum type 	  @ref port_index_t
*				logic			pointer to enum type	  @ref logic_t
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/
Std_ReturnType gpio_port_read_logic(const port_index_t port, logic_t *value);
/*
*	@brief		Toggling the port logic
*	@param		port			pointer to enum type 	  @ref port_index_t
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/
Std_ReturnType gpio_port_toggle_logic(const port_index_t port);

#endif /*ifndef HAL_GPIO_H*/


