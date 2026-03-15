/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define EEPROM_WP_Pin GPIO_PIN_13
#define EEPROM_WP_GPIO_Port GPIOC
#define M_HIZ_Pin GPIO_PIN_14
#define M_HIZ_GPIO_Port GPIOC
#define M_nFault_Pin GPIO_PIN_15
#define M_nFault_GPIO_Port GPIOC
#define M_nFault_EXTI_IRQn EXTI15_10_IRQn
#define PWM_C_Pin GPIO_PIN_0
#define PWM_C_GPIO_Port GPIOC
#define PWM_B_Pin GPIO_PIN_1
#define PWM_B_GPIO_Port GPIOC
#define PWM_A_Pin GPIO_PIN_2
#define PWM_A_GPIO_Port GPIOC
#define PWM_R_Pin GPIO_PIN_3
#define PWM_R_GPIO_Port GPIOC
#define SOA_Pin GPIO_PIN_0
#define SOA_GPIO_Port GPIOA
#define SOB_Pin GPIO_PIN_1
#define SOB_GPIO_Port GPIOA
#define M_EN_Pin GPIO_PIN_2
#define M_EN_GPIO_Port GPIOA
#define CAL_Pin GPIO_PIN_3
#define CAL_GPIO_Port GPIOA
#define DRV_CS_Pin GPIO_PIN_4
#define DRV_CS_GPIO_Port GPIOA
#define DRV_SCLK_Pin GPIO_PIN_5
#define DRV_SCLK_GPIO_Port GPIOA
#define DRV_MISO_Pin GPIO_PIN_6
#define DRV_MISO_GPIO_Port GPIOA
#define DRV_MOSI_Pin GPIO_PIN_7
#define DRV_MOSI_GPIO_Port GPIOA
#define VCP_TX_Pin GPIO_PIN_4
#define VCP_TX_GPIO_Port GPIOC
#define VCP_RX_Pin GPIO_PIN_5
#define VCP_RX_GPIO_Port GPIOC
#define SOC_Pin GPIO_PIN_1
#define SOC_GPIO_Port GPIOB
#define VbatSense_Pin GPIO_PIN_12
#define VbatSense_GPIO_Port GPIOB
#define SPI2_NSS_Pin GPIO_PIN_14
#define SPI2_NSS_GPIO_Port GPIOB
#define TEMP1_Pin GPIO_PIN_8
#define TEMP1_GPIO_Port GPIOA
#define TEMP2_Pin GPIO_PIN_9
#define TEMP2_GPIO_Port GPIOA
#define Endstop_Pin GPIO_PIN_10
#define Endstop_GPIO_Port GPIOA
#define Endstop_EXTI_IRQn EXTI15_10_IRQn
#define FAULT_Pin GPIO_PIN_11
#define FAULT_GPIO_Port GPIOA
#define LINK_Pin GPIO_PIN_12
#define LINK_GPIO_Port GPIOA
#define SPI3_CS_Pin GPIO_PIN_11
#define SPI3_CS_GPIO_Port GPIOC
#define FAN_Pin GPIO_PIN_2
#define FAN_GPIO_Port GPIOD
#define FDCAN_RX_Pin GPIO_PIN_5
#define FDCAN_RX_GPIO_Port GPIOB
#define FDCAN_TX_Pin GPIO_PIN_6
#define FDCAN_TX_GPIO_Port GPIOB
#define BTN_A_Pin GPIO_PIN_7
#define BTN_A_GPIO_Port GPIOB
#define BTN_A_EXTI_IRQn EXTI9_5_IRQn
#define BTN_B_Pin GPIO_PIN_9
#define BTN_B_GPIO_Port GPIOB
#define BTN_B_EXTI_IRQn EXTI9_5_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
