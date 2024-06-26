/*
 * stm32f466xx_GPIO_Driver.h
 *
 *  Created on: May 18, 2024
 *      Author: haydencao
 */

#ifndef STM32F446XX_GPIO_DRIVER_H_
#define STM32F446XX_GPIO_DRIVER_H_

#include "stm32f446xx.h"

/*
 * This is a Configuration structure for a GPIO pin
 */
typedef struct
{
	uint8_t GPIO_PinNumber;			/* Holds what Pin to be configured      */
	uint8_t GPIO_PinMode;			/* possible values from @GPIO_PIN_MODES */
	uint8_t GPIO_PinSpeed;			/* possible values from @GPIO_PIN_SPEED */
	uint8_t GPIO_PinPuPdControl;		/* Pull Up / Pull Down / None Control 	*/
	uint8_t GPIO_PinOPType;			/* Pin output type Control		*/
	uint8_t GPIO_PinAltFunMode;		/* Alternate Function Mode for GPIO	*/

}	GPIO_PinConfig_t;

typedef struct
{
	GPIO_RegDef_t *pGPIOx;       		/* This holds the base address of the GPIO port to which the pin belongs */
	GPIO_PinConfig_t GPIO_PinConfig;   	/* This holds GPIO pin configuration settings */

}	GPIO_Handle_t;


/*
 * @GPIO_PIN_MODES
 * GPIO pin possible modes
 */
#define GPIO_MODE_IN 		0
#define GPIO_MODE_OUT 		1
#define GPIO_MODE_ALTFN 	2
#define GPIO_MODE_ANALOG 	3
#define GPIO_MODE_IT_FT     4
#define GPIO_MODE_IT_RT     5
#define GPIO_MODE_IT_RFT    6


/*
 * GPIO pin possible output types
 */
#define GPIO_OP_TYPE_PP   0
#define GPIO_OP_TYPE_OD   1


/*
 * @GPIO_PIN_SPEED
 * GPIO pin possible output speeds
 */
#define GPIO_SPEED_LOW			0
#define GPIO_SPEED_MEDIUM		1
#define GPIO_SPEED_FAST			2
#define GPOI_SPEED_HIGH			3


/*
 * GPIO pin pull up AND pull down configuration macros
 */
#define GPIO_NO_PUPD   		0
#define GPIO_PIN_PU			1
#define GPIO_PIN_PD			2

/*
 * Peripheral Clock setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

/*
 * Init and De-init
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);


/*
 * Data read and write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);


/*
 * IRQ Configuration and ISR handling
 */

void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);

#endif /* STM32F446XX_GPIO_DRIVER_H_ */
