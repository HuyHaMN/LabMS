#include "main.h"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

int main(void)
{
    /* MCU Configuration */
    HAL_Init();
    SystemClock_Config();

    /* Initialize all configured peripherals */
    MX_GPIO_Init();

    while (1)
    {
        HAL_GPIO_TogglePin(RED_LED_GPIO_Port, RED_LED_Pin);
        HAL_Delay(1000);
    }
}

void SystemClock_Config(void)
{
    /* Configure the system clock */
    // Your system clock configuration code here
}

static void MX_GPIO_Init(void)
{
    /* GPIO initialization code */
    // Your GPIO initialization code here
}
