/*
 * stm32f401xc_gpio_driver.c
 *
 *  Created on: Nov 20, 2025
 *      Author: DungNguyen
 */


#include "stm32f401xc_gpio_driver.h"


/****************************************************************
 * @fn - GPIO_PeriClockControl
 *
 * @brief - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in] - base address of the gpio peripheral
 * @param[in] - ENABLE or DISABLE macros
 *
 * @return - none
 *
 * @Note - none
 */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)       { GPIOA_PCLK_EN(); }
		else if (pGPIOx == GPIOB) { GPIOB_PCLK_EN(); }
		else if (pGPIOx == GPIOC) { GPIOC_PCLK_EN(); }
		else if (pGPIOx == GPIOD) { GPIOD_PCLK_EN(); }
		else if (pGPIOx == GPIOE) { GPIOE_PCLK_EN(); }
		else if (pGPIOx == GPIOH) { GPIOH_PCLK_EN(); }
	}
	else
	{
		if(pGPIOx == GPIOA)       { GPIOA_PCLK_DI(); }
		else if (pGPIOx == GPIOB) { GPIOB_PCLK_DI(); }
		else if (pGPIOx == GPIOC) { GPIOC_PCLK_DI(); }
		else if (pGPIOx == GPIOD) { GPIOD_PCLK_DI(); }
		else if (pGPIOx == GPIOE) { GPIOE_PCLK_DI(); }
		else if (pGPIOx == GPIOH) { GPIOH_PCLK_DI(); }
	}
}

/****************************************************************
 * @fn - GPIO_Init
 *
 * @brief - This function initialize the configuration for GPIO pin
 *
 * @param[in] - base address of the gpio peripheral
 *
 * @return - none
 *
 * @Note - none
 */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle) /* Initialise GPIO Pin */
{
	uint32_t temp = 0;

// 1.Configure the Mode
	if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		pGPIOHandle->pGPIOx->MODER &= ~( 0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); //clearing
		temp = ((pGPIOHandle ->GPIO_PinConfig.GPIO_PinMode) << (2* pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber)); //Setting
		pGPIOHandle->pGPIOx->MODER |= temp;
	}

	 else
	 {
		if( pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT)
		{
			// 1. Configure the FTSR
			EXTI -> FTSR |=   (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

			//Clear RTSR
			EXTI -> RTSR &= ~ (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}

		else if (pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT)
		{
			// 1. Configure the RTSR
			EXTI -> RTSR |=   (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

			//Clear RTSR
			EXTI -> FTSR &= ~ (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}

		else if (pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FRT)
		{
			// 1. Configure the FRTSR
			EXTI -> RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

			EXTI -> FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}

			// 2. Configure the GPIO port selection in SYSCFG_EXTICR
			uint8_t temp_1 = pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber / 4;
			uint8_t temp_2 = pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber % 4;
			uint8_t portcode = GPIO_BASEADDR_TO_CODE(pGPIOHandle -> pGPIOx);

			SYSCFG_PCLK_EN();
			SYSCFG -> EXTICR[temp_1] = portcode << (temp_2 * 4);

			// 3. Enable the EXTI Interrupt delivery using IMR
			EXTI -> IMR |=   (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

	 }

	temp = 0;

// 2.Configure the Speed
	temp = (pGPIOHandle -> GPIO_PinConfig.GPIO_PinSpeed << (2* pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~( 0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); //clearing
	pGPIOHandle ->pGPIOx -> OSPEEDR |= temp;

	temp = 0;

// 3.Configure the PuPd settings
	temp = (pGPIOHandle -> GPIO_PinConfig.GPIO_PinPuPdControl << (2* pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~( 0x3 << ( 2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); //clearing
	pGPIOHandle ->pGPIOx -> PUPDR |= temp;

	temp = 0;

// 4.Configure the optype
	temp = (pGPIOHandle -> GPIO_PinConfig.GPIO_PinOPType << (pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OTYPER &= ~( 0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); //clearing
	pGPIOHandle ->pGPIOx -> OTYPER |= temp;

// 5.Configuring the alterante function mode
	if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN) {
	    uint8_t afr_index = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
	    uint8_t afr_position = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;

	    pGPIOHandle->pGPIOx->AFR[afr_index] &= ~(0xF << (4 * afr_position));
	    pGPIOHandle->pGPIOx->AFR[afr_index] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * afr_position));
	}
}

/****************************************************************
* @fn - GPIO_DeInit
*
* @brief - This function initialize the configuration for GPIO pin
*
* @param[in] - base address of the gpio peripheral
*
* @return - none
*
* @Note - none
*/
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx) /* Reset the GPIO port back to its default value  */

{
	if(pGPIOx == GPIOA)
	{
		GPIOA_REG_RESET();
	}else if (pGPIOx == GPIOB)
	{
		GPIOB_REG_RESET();
	}else if (pGPIOx == GPIOC)
	{
		GPIOC_REG_RESET();
	}else if (pGPIOx == GPIOD)
	{
		GPIOD_REG_RESET();
	}
	else if (pGPIOx == GPIOE)
	{
		GPIOE_REG_RESET();
	}

	else if (pGPIOx == GPIOH)
	{
		GPIOH_REG_RESET();
	}

}

/****************************************************************
* @fn -  GPIO_ReadFromInputPin
*
* @brief - This function read data from the pin
*
* @param[in] - base address of the gpio peripheral
*
* @return - none
*
* @Note - none
*/

uint8_t  GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t) ((pGPIOx -> IDR >> PinNumber) & (0x00000001) );
	return value;
}

/*********************************************************************
 * @fn      		  - GPIO_ReadFromInputPort
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;

	value = (uint16_t)pGPIOx->IDR;

	return value;
}

/*********************************************************************
 * @fn      		  - GPIO_WriteToOutputPin
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{

	if(Value == GPIO_PIN_SET)
	{
		//write 1 to the output data register at the bit field corresponding to the pin number
		pGPIOx->ODR |= ( 1 << PinNumber);
	}

	else
	{
		//write 0
		pGPIOx->ODR &= ~( 1 << PinNumber);
	}
}


/*********************************************************************
 * @fn      		  - GPIO_WriteToOutputPort
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR  = Value;
}

/*********************************************************************
 * @fn      		  - GPIO_ToggleOutputPin
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
    pGPIOx->ODR ^= (1 << PinNumber);
}

/*********************************************************************
 * @fn      		  - GPIO_IRQInterruptConfig
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{
	// 1. Enable and disable the NVIC register
	if(EnorDi == ENABLE)
	{
		if(IRQNumber <= 31)
		{
			//program ISER0 register
			*NVIC_ISER0 |= ( 1 << IRQNumber );

		}else if(IRQNumber > 31 && IRQNumber < 64 ) //32 to 63
		{
			//program ISER1 register
			*NVIC_ISER1 |= ( 1 << (IRQNumber % 32) );
		}
		else if(IRQNumber >= 64 && IRQNumber < 96 )
		{
			//program ISER2 register //64 to 95
			*NVIC_ISER2 |= ( 1 << (IRQNumber % 64) );
		}
	}else
	{
		if(IRQNumber <= 31)
		{
			//program ICER0 register
			*NVIC_ICER0 |= ( 1 << IRQNumber );
		}else if(IRQNumber > 31 && IRQNumber < 64 )
		{
			//program ICER1 register
			*NVIC_ICER1 |= ( 1 << (IRQNumber % 32) );
		}
		else if(IRQNumber >= 64 && IRQNumber < 96 )
		{
			//program ICER2 register
			*NVIC_ICER2 |= ( 1 << (IRQNumber % 64) );
		}
	}
}

	// 2.Set the priority level

	/*********************************************************************
	 * @fn      		  - SPI_IRQPriorityConfig
	 *
	 * @brief             -
	 *
	 * @param[in]         -
	 * @param[in]         -
	 * @param[in]         -
	 *
	 * @return            -
	 *
	 * @Note              -

	 */
void GPIO_IRQPriorityConfig(uint8_t IRQNumber,uint32_t IRQPriority)
	{
		//1. first lets find out the ipr register
		uint8_t iprx = IRQNumber / 4;
		uint8_t iprx_section  = IRQNumber %4 ;

		uint8_t shift_amount = ( 8 * iprx_section) + ( 8 - NO_PR_BITS_IMPLEMENTED) ;

		*( NVIC_PR_BASE_ADDR + iprx ) |=  ( IRQPriority << shift_amount );

	}


/*********************************************************************
	 * @fn      		  - SPI_IRQPriorityConfig
	 *
	 * @brief             -
	 *
	 * @param[in]         -
	 * @param[in]         -
	 * @param[in]         -
	 *
	 * @return            -
	 *
	 * @Note              -

	 */

void GPIO_IRQHandling(uint8_t PinNumber){

	//Clear the EXTI PR Register corresponding to the pin number
	if ( (EXTI -> PR) & (1 << PinNumber) ){

		//clear
		EXTI -> PR |= (1 << PinNumber);
	}
}





