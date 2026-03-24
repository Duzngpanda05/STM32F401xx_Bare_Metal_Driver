/*
 * stm32f401xx.h
 *
 *  Created on: Mar 16, 2026
 *      Author: T14-Gen3
 */

#ifndef INC_STM32F401XX_H_
#define INC_STM32F401XX_H_


#include <stdint.h>
#include <stddef.h>

/* Generic Macros */
#define _vo 					volatile
#define ENABLE 					1
#define DISABLE 				0
#define SET 					ENABLE
#define RESET 					DISABLE
#define GPIO_PIN_SET 			SET
#define GPIO_PIN_RESET 			RESET
#define FLAG_RESET         		RESET
#define FLAG_SET 				SET


/**********************************START:Processor Specific Details **********************************/
/*
 * ARM Cortex Mx Processor NVIC ISERx register Addresses
 */

#define NVIC_ISER0           (_vo uint32_t*) 0xE000E100
#define NVIC_ISER1           (_vo uint32_t*) 0xE000E104
#define NVIC_ISER2           (_vo uint32_t*) 0xE000E108
#define NVIC_ISER3           (_vo uint32_t*) 0xE000E10c

/*
 * ARM Cortex Mx Processor NVIC ICERx register Addresses
 */
#define NVIC_ICER0 			((_vo uint32_t*)0XE000E180)
#define NVIC_ICER1			((_vo uint32_t*)0XE000E184)
#define NVIC_ICER2  		((_vo uint32_t*)0XE000E188)
#define NVIC_ICER3			((_vo uint32_t*)0XE000E18C)

/*
 * ARM Cortex Mx Processor Priority Register Address Calculation
 */
#define NVIC_PR_BASE_ADDR 	((_vo uint32_t*)0xE000E400)

/*
 * ARM Cortex Mx Processor number of priority bits implemented in Priority Register
 */
#define NO_PR_BITS_IMPLEMENTED  4

/*
 * Memory Base Address
 */

#define FLASH_BASEADDR 			0x08000000U		/* Base Address of memory of Flash */
#define SRAM1_BASEADDR			0x20000000U		/* Base Address of memory of SRAM1 */
#define SRAM2_BASEADDR			0x20001C00U		/* Base Address of memory of SRAM2 */
#define ROM 					0x1FFF0000U		/* Base Address of memory of ROM */
#define SRAM					SRAM1_BASEADDR	/* MAIN SRAM is the SRAM1  */

/*
 * APBx and AHBx Base Address
 */

#define PERIPH_BASEADDR 		0x40000000U
#define APB1PERIPH_BASEADDR		0x40000000U
#define APB2PERIPH_BASEADDR		0x40010000U
#define AHB1PERIPH_BASEADDR		0x40020000U
#define AHB2PERIPH_BASEADDR		0x50000000U

/*
 * Base addresses of peripherals which are hanging on AHB1 bus
 */
#define GPIOA_BASEADDR    (AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR    (AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR    (AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR    (AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR    (AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR    (AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR    (AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR    (AHB1PERIPH_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR    (AHB1PERIPH_BASEADDR + 0x2000)

#define RCC_BASEADDR	  (AHB1PERIPH_BASEADDR + 0x3800)

/*
 * Base addresses of peripherals which are hanging on APB1 bus
 */

#define I2C1_BASEADDR     (APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR     (APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR     (APB1PERIPH_BASEADDR + 0x5C00)

#define SPI2_BASEADDR     (APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR     (APB1PERIPH_BASEADDR + 0x3C00)

#define USART2_BASEADDR   (APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR   (APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR    (APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR    (APB1PERIPH_BASEADDR + 0x5000)

/*
 * Base addresses of peripherals which are hanging on APB2 bus
 */

#define EXTI_BASEADDR      (APB2PERIPH_BASEADDR + 0x3C00)
#define SPI1_BASEADDR      (APB2PERIPH_BASEADDR + 0x3000)
#define SPI4_BASEADDR      (APB2PERIPH_BASEADDR + 0x3400)
#define SYSCFG_BASEADDR    (APB2PERIPH_BASEADDR + 0x3800)
#define USART1_BASEADDR    (APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR    (APB2PERIPH_BASEADDR + 0x1400)

/***************** Peripheral Register definition structure **********/
/*
 * Peripheral Register structure for GPIO
 */
typedef struct
{
    volatile uint32_t MODER;      /* Address offset: 0x00 */
    _vo uint32_t OTYPER;     /* Address offset: 0x04 */
    _vo uint32_t OSPEEDR;    /* Address offset: 0x08 */
    _vo uint32_t PUPDR;      /* Address offset: 0x0C */
    _vo uint32_t IDR;        /* Address offset: 0x10 */
    _vo uint32_t ODR;        /* Address offset: 0x14 */
    _vo uint32_t BSRRL;      /* Address offset: 0x18 */
    _vo uint32_t BSRRH;      /* Address offset: 0x1A */
    _vo uint32_t LCKR;       /* Address offset: 0x1C */
    _vo uint32_t AFR[2];     /* Address offset: 0x20 - 0x24 */
} GPIO_RegDef_t;

/*
 * Peripheral register definition structure for SPI
 *
 */
typedef struct {
	_vo uint32_t CR1;        /*Address offset: 0x00 */
	_vo uint32_t CR2;        /*Address offset: 0x04 */
	_vo uint32_t SR;         /*Address offset: 0x08 */
	_vo uint32_t DR;         /*Address offset: 0x0C */
	_vo uint32_t CRCPR;      /*Address offset: 0x10 */
	_vo uint32_t RXCRCR;     /*Address offset: 0x14 */
	_vo uint32_t TXCRCR;     /*Address offset: 0x18 */
	_vo uint32_t I2SCFGR;    /*Address offset: 0x1C */
	_vo uint32_t I2SPR;      /*Address offset: 0x20 */
}SPI_RegDef_t;


/*
 *  Peripheral Register structure for RCC
 */

typedef struct
{
    _vo uint32_t CR;            /* Address offset: 0x00 */
    _vo uint32_t PLLCFGR;       /* Address offset: 0x04 */
    _vo uint32_t CFGR;          /* Address offset: 0x08 */
    _vo uint32_t CIR;           /* Address offset: 0x0C */
    _vo uint32_t AHB1RSTR;      /* Address offset: 0x10 */
    _vo uint32_t AHB2RSTR;      /* Address offset: 0x14 */
    _vo uint32_t AHB3RSTR;      /* Address offset: 0x18 */
    uint32_t     RESERVED0;     /* Reserved, 0x1C Address offset: 0x1C */
    _vo uint32_t APB1RSTR;      /* Address offset: 0x20 */
    _vo uint32_t APB2RSTR;      /* Address offset: 0x24 */
    uint32_t     RESERVED1[2];  /* Reserved, 0x28-0x2C Address offset: 0x28 */
    _vo uint32_t AHB1ENR;       /* Address offset: 0x30 */
    _vo uint32_t AHB2ENR;       /* Address offset: 0x34 */
    _vo uint32_t AHB3ENR;       /* Address offset: 0x38 */
    uint32_t      RESERVED2;    /* Reserved, 0x3C Address offset: 0x3C */
    _vo uint32_t APB1ENR;       /* Address offset: 0x40 */
    _vo uint32_t APB2ENR;       /* Address offset: 0x44 */
    uint32_t     RESERVED3[2];  /* Reserved, 0x48-0x4C Address offset: 0x48 */
    _vo uint32_t AHB1LPENR;     /* Address offset: 0x50 */
    _vo uint32_t AHB2LPENR;     /* Address offset: 0x54 */
    _vo uint32_t AHB3LPENR;     /* Address offset: 0x58 */
    uint32_t     RESERVED4;     /* Reserved, 0x5C Address offset: 0x5C */
    _vo uint32_t APB1LPENR;     /* Address offset: 0x60 */
    _vo uint32_t APB2LPENR;     /* Address offset: 0x64 */
    uint32_t     RESERVED5[2];  /* Reserved, 0x68-0x6C Address offset: 0x68 */
    _vo uint32_t BDCR;          /* Address offset: 0x70 */
    _vo uint32_t CSR;           /* Address offset: 0x74 */
    uint32_t     RESERVED6[2];  /* Reserved, 0x78-0x7C Address offset: 0x78 */
    _vo uint32_t SSCGR;         /* Address offset: 0x80 */
    _vo uint32_t PLL12SCFGR;    /* Address offset: 0x84 */
    _vo uint32_t PLLSAICFGR;    /* Address offset: 0x88 */
    _vo uint32_t DCKCFGR;       /* Address offset: 0x8C */
    _vo uint32_t CKGENR;        /* Address offset: 0x90 */
    _vo uint32_t DCKCFGR2;      /* Address offset: 0x94 */
    } RCC_RegDef_t;

/*
* peripheral register definition structure for EXTI
*/
typedef struct
{
   _vo uint32_t IMR;    		/* Address offset: 0x00 */
   _vo uint32_t EMR;            /* Address offset: 0x04 */
   _vo uint32_t RTSR;   		/* Address offset: 0x08 */
   _vo uint32_t FTSR;   		/* Address offset: 0x0C */
   _vo uint32_t SWIER;  		/* Address offset: 0x10 */
   _vo uint32_t PR;     		/* Address offset: 0x14 */

}EXTI_RegDef_t;

/*
 * peripheral register definition structure for SYSCFG
 */
typedef struct
{
	_vo uint32_t MEMRMP;        /* Address offset: 0x00      */
	_vo uint32_t PMC;           /* Address offset: 0x04      */
	_vo uint32_t EXTICR[4];     /* Address offset: 0x08-0x14 */
	uint32_t     RESERVED1[2];  /* Reserved, 0x18-0x1C    	 */
	_vo uint32_t CMPCR;         /* Address offset: 0x20      */
	uint32_t     RESERVED2[2];  /* Reserved, 0x24-0x28 	     */
	_vo uint32_t CFGR;          /* Address offset: 0x2C   	 */
} SYSCFG_RegDef_t;



/*
* Peripheral Definition
*/

#define GPIOA 				( (GPIO_RegDef_t*) GPIOA_BASEADDR )
#define GPIOB 				( (GPIO_RegDef_t*) GPIOB_BASEADDR )
#define GPIOC 				( (GPIO_RegDef_t*) GPIOC_BASEADDR )
#define GPIOD 				( (GPIO_RegDef_t*) GPIOD_BASEADDR )
#define GPIOE 				( (GPIO_RegDef_t*) GPIOE_BASEADDR )
#define GPIOH 				( (GPIO_RegDef_t*) GPIOH_BASEADDR )

#define RCC 				( (RCC_RegDef_t*) RCC_BASEADDR )

#define EXTI 				( (EXTI_RegDef_t*) EXTI_BASEADDR )

#define SYSCFG				((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

#define SPI1  				((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2  				((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3  				((SPI_RegDef_t*)SPI3_BASEADDR)
#define SPI4				((SPI_RegDef_t*)SPI3_BASEADDR)
/*
 * Clock Enable Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_EN() ( RCC -> AHB1ENR |= ( 1 << 0) )
#define GPIOB_PCLK_EN() ( RCC -> AHB1ENR |= ( 1 << 1) )
#define GPIOC_PCLK_EN() ( RCC -> AHB1ENR |= ( 1 << 2) )
#define GPIOD_PCLK_EN() ( RCC -> AHB1ENR |= ( 1 << 3) )
#define GPIOE_PCLK_EN() ( RCC -> AHB1ENR |= ( 1 << 4) )
#define GPIOH_PCLK_EN() ( RCC -> AHB1ENR |= ( 1 << 7) )

/*
* Clock Disable Macros for GPIOx peripherals
*/

#define GPIOA_PCLK_DI() ( RCC -> AHB1ENR &= ~ (1 << 0) )
#define GPIOB_PCLK_DI() ( RCC -> AHB1ENR &= ~ (1 << 1) )
#define GPIOC_PCLK_DI() ( RCC -> AHB1ENR &= ~ (1 << 2) )
#define GPIOD_PCLK_DI() ( RCC -> AHB1ENR &= ~ (1 << 3) )
#define GPIOE_PCLK_DI() ( RCC -> AHB1ENR &= ~ (1 << 4) )
#define GPIOH_PCLK_DI() ( RCC -> AHB1ENR &= ~ (1 << 7) )

/*
* Clock Enable Macros for I2Cx peripherals
*/

#define I2C1_PCLK_EN() ( RCC -> APB1ENR |= ( 1 << 21) )
#define I2C2_PCLK_EN() ( RCC -> APB1ENR |= ( 1 << 22) )
#define I2C3_PCLK_EN() ( RCC -> APB1ENR |= ( 1 << 23) )

/*
* Clock Disable Macros for I2Cx peripherals
*/

#define I2C1_PCLK_DI() ( RCC -> APB1ENR &= ~ ( 1 << 21) )
#define I2C2_PCLK_DI() ( RCC -> APB1ENR &= ~ ( 1 << 22) )
#define I2C3_PCLK_DI() ( RCC -> APB1ENR &= ~ ( 1 << 23) )

/*
* Clock Enable Macros for SPIx peripherals
*/
#define SPI1_PCLK_EN() ( RCC -> APB2ENR |= ( 1 << 12 ) )
#define SPI2_PCLK_EN() ( RCC -> APB1ENR |= ( 1 << 14 ) )
#define SPI3_PCLK_EN() ( RCC -> APB1ENR |= ( 1 << 15 ) )
#define SPI4_PCLK_EN() ( RCC -> APB1ENR |= ( 1 << 13 ) )

/*
 * Clock Disable Macros for SPIx peripherals
 */
#define SPI1_PCLK_DI() ( RCC -> APB2ENR &= ~ ( 1 << 12 ) )
#define SPI2_PCLK_DI() ( RCC -> APB1ENR &= ~ ( 1 << 14 ) )
#define SPI3_PCLK_DI() ( RCC -> APB1ENR &= ~ ( 1 << 15 ) )
#define SPI4_PCLK_DI() ( RCC -> APB2ENR &= ~ ( 1 << 13 ) )

/*
* Clock Enable Macros for USARTx peripherals
*/
#define USART1_PCLK_EN() (RCC->APB2ENR |= (1 << 4))
#define USART2_PCLK_EN() (RCC->APB1ENR |= (1 << 17))
#define USART6_PCLK_EN() (RCC->APB1ENR |= (1 << 5))

/*
* Clock Enable Macros for SYSCFG peripheral
*/
#define SYSCFG_PCLK_EN() (RCC->APB2ENR |= (1 << 14))

/*
*  Macros to reset GPIOx peripherals
*/
#define GPIOA_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOB_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); }while(0)
#define GPIOC_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); }while(0)
#define GPIOD_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); }while(0)
#define GPIOE_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); }while(0)
#define GPIOH_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7)); }while(0)

/*
*  Macros to reset SPIx peripherals
*/
#define SPI1_REG_RESET()				do{ (RCC->APB2RSTR |= (1 << 12)); (RCC->APB2RSTR &= ~(1 << 12)); }while(0)
#define SPI2_REG_RESET()				do{ (RCC->APB1RSTR |= (1 << 14)); (RCC->APB1RSTR &= ~(1 << 14)); }while(0)
#define SPI3_REG_RESET()				do{ (RCC->APB1RSTR |= (1 << 15)); (RCC->APB1RSTR &= ~(1 << 15)); }while(0)
#define SPI4_REG_RESET()				do{ (RCC->APB2RSTR |= (1 << 13)); (RCC->APB2RSTR &= ~(1 << 13)); }while(0)

/*
* This macro returns a code( between 0 to 7) for a given GPIO base address(x)
*/

#define GPIO_BASEADDR_TO_CODE(x) ((x == GPIOA)?0:\
								 (x == GPIOB)?1:\
								 (x == GPIOC)?2:\
								 (x == GPIOD)?3:\
								 (x == GPIOE)?4:\
								 (x == GPIOH)?7: 0)

/*
 * IRQ(Interrupt Request) Numbers of STM32F407x MCU
 */

#define IRQ_NO_EXTI0 		6
#define IRQ_NO_EXTI1 		7
#define IRQ_NO_EXTI2 		8
#define IRQ_NO_EXTI3 		9
#define IRQ_NO_EXTI4 		10
#define IRQ_NO_EXTI9_5 		23
#define IRQ_NO_EXTI15_10 	40
#define IRQ_NO_SPI1			35
#define IRQ_NO_SPI2         36
#define IRQ_NO_SPI3         51
#define IRQ_NO_SPI4			84
#define IRQ_NO_I2C1_EV      31
#define IRQ_NO_I2C1_ER      32
#define IRQ_NO_USART1	    37
#define IRQ_NO_USART2	    38
#define IRQ_NO_USART3	    39
#define IRQ_NO_UART4	    52
#define IRQ_NO_UART5	    53
#define IRQ_NO_USART6	    71

/*
 * macros for all the possible priority levels
 */
#define NVIC_IRQ_PRI0    0
#define NVIC_IRQ_PRI1	 1
#define NVIC_IRQ_PRI2    2
#define NVIC_IRQ_PRI3    3
#define NVIC_IRQ_PRI4    4
#define NVIC_IRQ_PRI5    5
#define NVIC_IRQ_PRI6    6
#define NVIC_IRQ_PRI7    7
#define NVIC_IRQ_PRI8    8
#define NVIC_IRQ_PRI9    9
#define NVIC_IRQ_PRI10   10
#define NVIC_IRQ_PRI11   11
#define NVIC_IRQ_PRI12   12
#define NVIC_IRQ_PRI13   13
#define NVIC_IRQ_PRI14   14
#define NVIC_IRQ_PRI15   15

/******************************************************************************************
 *Bit position definitions of SPI peripheral
 ******************************************************************************************/

/*
 * Bit position definitions SPI_CR1
 */
#define SPI_CR1_CPHA     				 0
#define SPI_CR1_CPOL      				 1
#define SPI_CR1_MSTR     				 2
#define SPI_CR1_BR   					 3
#define SPI_CR1_SPE     				 6
#define SPI_CR1_LSBFIRST   			 	 7
#define SPI_CR1_SSI     				 8
#define SPI_CR1_SSM      				 9
#define SPI_CR1_RXONLY      		 	10
#define SPI_CR1_DFF     			 	11
#define SPI_CR1_CRCNEXT   			 	12
#define SPI_CR1_CRCEN   			 	13
#define SPI_CR1_BIDIOE     			 	14
#define SPI_CR1_BIDIMODE      			15

/*
 * Bit position definitions SPI_CR2
 */
#define SPI_CR2_RXDMAEN		 			0
#define SPI_CR2_TXDMAEN				 	1
#define SPI_CR2_SSOE				 	2
#define SPI_CR2_FRF						4
#define SPI_CR2_ERRIE					5
#define SPI_CR2_RXNEIE				 	6
#define SPI_CR2_TXEIE					7

/*
 * Bit position definitions SPI_SR
 */
#define SPI_SR_RXNE						0
#define SPI_SR_TXE				 		1
#define SPI_SR_CHSIDE				 	2
#define SPI_SR_UDR					 	3
#define SPI_SR_CRCERR				 	4
#define SPI_SR_MODF					 	5
#define SPI_SR_OVR					 	6
#define SPI_SR_BSY					 	7
#define SPI_SR_FRE					 	8

#endif /* INC_STM32F401XX_H_ */
