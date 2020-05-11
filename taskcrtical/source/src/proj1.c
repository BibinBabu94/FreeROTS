#include "board.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#define delay       portMAX_DELAY
xSemaphoreHandle xMutex;                         //Defining xSemaphoreHandle to xMutex
/*Initial state of the LEDs*/
static void prvSetupHardware(void)
{
    SystemCoreClockUpdate();
    Board_Init();
    Board_LED_Set(0, true);
    Board_LED_Set(1, true);
    Board_LED_Set(2, true);
}
/* LED1 toggle thread */
static void vLEDTask1(void *pvParameters)
{
    bool LedState = false;
    while (1)
    {
    	taskENTER_CRITICAL();
        xSemaphoreTake(xMutex, delay);                                //Function to take the value
        Board_LED_Set(0, LedState);
        vTaskDelay(configTICK_RATE_HZ);                  //Delay of 1sec on time
        Board_LED_Set(0, !LedState);
        xSemaphoreGive(xMutex);
             /* Delay of 3.5sec off time */
        taskEXIT_CRITICAL();
        vTaskDelay(3 * configTICK_RATE_HZ + configTICK_RATE_HZ / 2);
    }
}
/* LED2 toggle thread */
static void vLEDTask2(void *pvParameters)
{
    bool LedState = false;
    vTaskDelay(configTICK_RATE_HZ + configTICK_RATE_HZ / 2);        //Green led on after 0.5sec delay at 1.5
    while (1)                                                                                                     //Infinite loop
    {
        xSemaphoreTake(xMutex, delay);
        Board_LED_Set(1, LedState);
        vTaskDelay(configTICK_RATE_HZ);
        Board_LED_Set(1, !LedState);
        xSemaphoreGive(xMutex);
        vTaskDelay(3 * configTICK_RATE_HZ + configTICK_RATE_HZ / 2);
    }
}

static void vLEDTask3(void *pvParameters)
{
    bool LedState = false;
    vTaskDelay(3* configTICK_RATE_HZ);                               //Blue led on at 3sec
    while (1)
    {
        xSemaphoreTake(xMutex, delay);
        Board_LED_Set(2, LedState);
        vTaskDelay(configTICK_RATE_HZ);
        Board_LED_Set(2, !LedState);
        xSemaphoreGive(xMutex);
        vTaskDelay(3 * configTICK_RATE_HZ + configTICK_RATE_HZ / 2);
    }
}

/*****************************************************************************
 * Public functions
 ****************************************************************************/
int main(void)
{
    prvSetupHardware();
    xMutex = xSemaphoreCreateMutex();                                  //Creating Mutex function
    /* LED1 toggle thread */
    xTaskCreate(vLEDTask1, (signed char* ) "vTaskLed1",
    configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 3UL),
    (xTaskHandle *) NULL);

    /* LED2 toggle thread */
    xTaskCreate(vLEDTask2, (signed char* ) "vTaskLed2",
    configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 2UL),
    (xTaskHandle *) NULL);

    /* LED3 toogle thread */
    xTaskCreate(vLEDTask3, (signed char* ) "vTaskLed3",
    configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1UL),
    (xTaskHandle *) NULL);

    /* Start the scheduler */
    vTaskStartScheduler();
    /* Should never arrive here */
    return 1;
}
