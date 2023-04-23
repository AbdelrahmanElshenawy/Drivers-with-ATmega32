/*=================================================================================
*   @file       hal_gpio.c
*   @brief      Accessing General purpose I/O PORTS
*   @details    hal_gpio.c File 
				contains definitions of the software interfaces used to access I/O ports of the micro-controller 
*   @author     Abdelrahman Ahmed Elshenawy 
===================================================================================*/

/*
*	@brief This includes the file hal_gpio.h to declare functions and use definitions 
*/
#include "hal_gpio.h"




static volatile uint8 *port_reg[4] = {	&PORTA,	/*PORTA is the an address @ref hal_registers.h*/
										&PORTB,	/*PORTB is the an address @ref hal_registers.h*/
										&PORTC,	/*PORTC is the an address @ref hal_registers.h*/
										&PORTD};	/*PORTD is the an address @ref hal_registers.h*/

static volatile uint8 *ddr_reg[4] = {	&DDRA,	/*DDRA is the an address @ref hal_registers.h*/
										&DDRB,	/*DDRB is the an address @ref hal_registers.h*/
										&DDRC,	/*DDRC is the an address @ref hal_registers.h*/
										&DDRD};	/*DDRD is the an address @ref hal_registers.h*/
										
static volatile uint8 *pin_reg[4] = {	&PINA,	/*PINA is the an address @ref hal_registers.h*/
										&PINB,	/*PINB is the an address @ref hal_registers.h*/
										&PINC,	/*PINC is the an address @ref hal_registers.h*/
										&PIND};	/*PIND is the an address @ref hal_registers.h*/
 
/*
*	@brief		Initializing the direction of pin
*	@param		_pin_config pointer to pin configurations @ref	pin_config_t
*	@return		Status of the function
*				(E_OK)		The function works successfully 
*				(E_NOT_OK)	The function has some issues
*/

#if GPIO_PIN_CONFIG == CONFIG_ENABLE

Std_ReturnType gpio_pin_direction_intialize(const pin_config_t *_pin_config){
	Std_ReturnType ret = E_OK;
	if((NULL == _pin_config) ||\
	 (_pin_config->port > MAX_PORT_NUMBER - 1 ) ||\
	 (_pin_config->pin > MAX_PIN_NUMBER - 1) ||\
	 (_pin_config->direction > MAX_DIRECTION_VALUE) ||\
	 (_pin_config->logic > MAX_LOGIC_VALUE)){
		ret = E_NOT_OK;
	}
	else{	
		switch(_pin_config->direction){
			
			case INPUT:
			CLEAR_BIT(*ddr_reg[_pin_config->port], _pin_config->pin); 
			break;
			
			case OUTPUT:
			SET_BIT(*ddr_reg[_pin_config->port], _pin_config->pin);
			break;
			
			default: 
			ret = E_NOT_OK;
			break;
		}
	}
	
	return ret;
}

/*
*	@brief		Getting the direction of pin using a pointer to direction_t enum variable
*	@param		_pin_config			pointer to pin configurations	   @ref	pin_config_t
				direction_status	pointer to direction enum variable @ref direction_t
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config , direction_t * direction_status){
	Std_ReturnType ret = E_OK;
	if((NULL == _pin_config) ||\
	(NULL == direction_status)||\
	(_pin_config->port > MAX_PORT_NUMBER - 1 ) ||\
	(_pin_config->pin > MAX_PIN_NUMBER - 1) ||\
	(_pin_config->direction > MAX_DIRECTION_VALUE) ||\
	(_pin_config->logic > MAX_LOGIC_VALUE)){
		
		ret = E_NOT_OK;
	}
	else{
		*direction_status = READ_BIT(*ddr_reg[_pin_config->port],_pin_config->pin);
	}
	
	return ret;
}
/*
*	@brief		Writing the logic HIGH or LOW to the pin
*	@param		_pin_config			pointer to pin configurations	   @ref	pin_config_t
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config , const logic_t logic){
	Std_ReturnType ret = E_OK;
	if((NULL == _pin_config) ||\
	(logic > MAX_LOGIC_VALUE)||\
	(_pin_config->port > MAX_PORT_NUMBER - 1 ) ||\
	(_pin_config->pin > MAX_PIN_NUMBER - 1) ||\
	(_pin_config->direction > MAX_DIRECTION_VALUE) ||\
	(_pin_config->logic > MAX_LOGIC_VALUE)){
		ret = E_NOT_OK;
	}
	else{
		switch(logic){
			case LOW:
			CLEAR_BIT(*port_reg[_pin_config->port],_pin_config->pin);
			break;
			
			case HIGH:
			SET_BIT(*port_reg[_pin_config->port],_pin_config->pin);
			break;
			
			default: 
			ret = E_NOT_OK;
			break;
		}
	}
	
	return ret;
}
/*
*	@brief		Reading the logic HIGH or LOW of the pin through pointer to logic_t
*	@param		_pin_config			pointer to pin configurations		@ref pin_config_t
*				logic				pointer to logic_t					@ref logic_t
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config , logic_t *logic){
	Std_ReturnType ret = E_OK;
	if((NULL == _pin_config) ||\
	(NULL == logic) ||\
	(_pin_config->port > MAX_PORT_NUMBER - 1 ) ||\
	(_pin_config->pin > MAX_PIN_NUMBER - 1) ||\
	(_pin_config->direction > MAX_DIRECTION_VALUE) ||\
	(_pin_config->logic > MAX_LOGIC_VALUE) ||\
	(*logic > MAX_LOGIC_VALUE)){
		ret = E_NOT_OK;
	}
	else{
		*logic = READ_BIT(*pin_reg[_pin_config->port],_pin_config->pin);
	}
	
	return ret;
}
/*
*	@brief		Toggle the pin logic
*	@param		_pin_config			pointer to pin configurations	   @ref	pin_config_t
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config){
	Std_ReturnType ret = E_OK;
	if((NULL == _pin_config) ||\
	(_pin_config->port > MAX_PORT_NUMBER - 1 ) ||\
	(_pin_config->pin > MAX_PIN_NUMBER - 1) ||\
	(_pin_config->direction > MAX_DIRECTION_VALUE) ||\
	(_pin_config->logic > MAX_LOGIC_VALUE)){
		ret = E_NOT_OK;
	}
	else{
		TOGGLE_BIT(*port_reg[_pin_config->port],_pin_config->pin);
	}
	
	return ret;
}
/*
*	@brief		Initializing the port direction
*	@param		port			pointer to enum type 	  @ref port_index_t
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/
#endif /*#if GPIO_PIN_CONFIG == CONFIG_ENABLE*/


#if GPIO_PORT_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_port_direction_intialize(const port_index_t port , const direction_t direction){
	Std_ReturnType ret = E_OK;
	if((port > MAX_PORT_NUMBER - 1) || (direction > MAX_DIRECTION_VALUE)){
		ret = E_NOT_OK;
	}
	else{
		
		switch(direction){
			case INPUT:
			*ddr_reg[port] = PORT_INPUT;
			break;	
			
			case OUTPUT:
			*ddr_reg[port] = PORT_OUTPUT;
			break;
			
			default:
			ret = E_NOT_OK;
			break;
		}
		 
	}
	return ret;
}
/*
*	@brief		Getting the port direction
*	@param		port				pointer to enum type 	  @ref port_index_t
*				direction_status	pointer to enum type	  @ref direction_t
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/
Std_ReturnType gpio_port_get_direction_status(const port_index_t port , uint8 * direction_status){
	Std_ReturnType ret = E_OK;
	if((port > MAX_PORT_NUMBER - 1) || (NULL == direction_status)){
		ret = E_NOT_OK;
	}
	else{
		
		*direction_status = *ddr_reg[port];
	}
	return ret;
}
/*
*	@brief		Writing logic or value to the port
*	@param		port			pointer to enum type 	  @ref port_index_t
*				logic			the value required to be written
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/
Std_ReturnType gpio_port_write_logic(const port_index_t port, const uint8 value){
	Std_ReturnType ret = E_OK;
	if((port > MAX_PORT_NUMBER - 1)){
		ret = E_NOT_OK;
	}
	else{
		*port_reg[port] = value;
	}
	return ret;
}
/*
*	@brief		Reading the port logic or value
*	@param		port			pointer to enum type 	  @ref port_index_t
*				logic			pointer to enum type	  @ref logic_t
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/
Std_ReturnType gpio_port_read_logic(const port_index_t port, logic_t *value){
	Std_ReturnType ret = E_OK;
	if((port > MAX_PORT_NUMBER - 1)){
		ret = E_NOT_OK;
	}
	else{
		*value = *pin_reg[port];
	}
	return ret;
	
}
/*
*	@brief		Toggling the port logic
*	@param		port			pointer to enum type 	  @ref port_index_t
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/
Std_ReturnType gpio_port_toggle_logic(const port_index_t port){
	Std_ReturnType ret = E_OK;
	if((port > MAX_PORT_NUMBER - 1)){
		ret = E_NOT_OK;
	}
	else{
		*port_reg[port] ^= ALL_ONES;
	}
	return ret;
}

#endif /*#if GPIO_PORT_CONFIG == CONFIG_ENABLE*/