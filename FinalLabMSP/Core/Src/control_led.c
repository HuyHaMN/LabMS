
#include "control_led.h"

void display7SEG(int k){
    switch (k){
    case 0:
        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin
                                      |SEG4_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG6_Pin, GPIO_PIN_SET);
        break;
    case 1:
        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG1_Pin|SEG2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG0_Pin|SEG3_Pin
                                      |SEG4_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_SET);
        break;
    case 2:
        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG0_Pin|SEG1_Pin|SEG3_Pin
                                      |SEG4_Pin|SEG6_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG2_Pin|SEG5_Pin, GPIO_PIN_SET);
        break;
    case 3:
        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin
                                      |SEG6_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG4_Pin|SEG5_Pin, GPIO_PIN_SET);
        break;
    case 4:
        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG1_Pin|SEG2_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG0_Pin|SEG3_Pin|SEG4_Pin, GPIO_PIN_SET);
        break;
    case 5:
        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG0_Pin|SEG2_Pin|SEG3_Pin
                                      |SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG1_Pin|SEG4_Pin, GPIO_PIN_SET);
        break;
    case 6:
        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG0_Pin|SEG2_Pin|SEG3_Pin
                                      |SEG4_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
        break;
    case 7:
        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG0_Pin|SEG1_Pin|SEG2_Pin , GPIO_PIN_RESET);
        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_SET);
        break;
    case 8:
        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin
                                      |SEG4_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
        break;
    case 9:
        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin
                                      |SEG4_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
        break;
    default:
        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin
                                      |SEG4_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
    }
}
