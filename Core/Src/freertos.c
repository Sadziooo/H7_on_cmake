/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

osThreadId_t lcdTaskHandle;
const osThreadAttr_t lcdTask_attributes = {
  .name = "lcdTask",
  .stack_size = 2048,
  .priority = (osPriority_t) osPriorityNormal,
};

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

void StartLCDTask(void *argument);

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName);
void vApplicationMallocFailedHook(void);

/* USER CODE BEGIN 4 */
void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName)
{
  __disable_irq();
  while(1);
}
/* USER CODE END 4 */

/* USER CODE BEGIN 5 */
void vApplicationMallocFailedHook(void)
{
  __disable_irq();
  while(1);
}
/* USER CODE END 5 */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  
  lcdTaskHandle = osThreadNew(StartLCDTask, NULL, &lcdTask_attributes);

  /* Infinite loop */
  for(;;)
  {
    HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
    osDelay(200);
    HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
    osDelay(200);
    HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
    osDelay(200);
  }
  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

#include "LCD.h"
#include "ST7789.h"

ST7789_IO_t st7789_hal_io = {
    .set_cs = ST7789_HAL_set_cs,
    .set_dc = ST7789_HAL_set_dc,
    .set_bl = ST7789_HAL_set_bl,
    .spi_transmit = ST7789_HAL_spi_transmit,
    .spi_transmit_dma = NULL,
    .spi_transmit_receive = ST7789_HAL_spi_transmit_receive,
    .delay_ms = ST7789_HAL_delay_ms
};

void StartLCDTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */



  if(0 == ST7789_init(&st7789_hal_io)) {
    ST7789_draw_circle(100, 100, 10, WHITE);
    ST7789_draw_circle(100, 100, 20, RED);
    ST7789_draw_circle(100, 100, 30, GREEN);
    ST7789_draw_circle(100, 100, 40, BLUE);
    ST7789_draw_circle(100, 100, 50, YELLOW);
    ST7789_draw_circle(100, 100, 60, MAGENTA);
    ST7789_draw_circle(100, 100, 70, CYAN);
  }
  osDelay(1000);
  /* Infinite loop */
  for(;;)
  {
    ST7789_fill_box_fast(0, 0, DISPLAY_W, DISPLAY_H, BLACK);
    ST7789_draw_circle(100, 100, 10, WHITE);
    ST7789_draw_circle(100, 100, 20, RED);
    ST7789_draw_circle(100, 100, 30, GREEN);
    ST7789_draw_circle(100, 100, 40, BLUE);
    ST7789_draw_circle(100, 100, 50, YELLOW);
    ST7789_draw_circle(100, 100, 60, MAGENTA);
    ST7789_draw_circle(100, 100, 70, CYAN);
    osDelay(200);
  }
  /* USER CODE END StartDefaultTask */
}
/* USER CODE END Application */

