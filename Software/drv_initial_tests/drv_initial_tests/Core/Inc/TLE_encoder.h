
#ifndef INC_TLE_ENCODER_H_
#define INC_TLE_ENCODER_H_

#include "stm32g4xx_hal.h"
#include "stdint.h"
#include "stdbool.h"


#define TLE5012B_CPR 32768.0f


// Encoder registers
#define TLE5012B_READ_REGISTER 0x8000
#define TLE5012B_STATUS_REG (0x00 << 4)
#define TLE5012B_ACTIVATION_REG (0x01 << 4)
#define TLE5012B_ANGLE_REG (0x02 << 4)
#define TLE5012B_SPEED_REG (0x03 << 4)
#define TLE5012B_ANGLE_REV_REG (0x04 << 4)


#define	TLE5012B_ACTIVATE_FIRMWARE_RESET (0x01 << 10)
#define	TLE5012B_ACTIVATE_DSPU_WATCHDOG_HW_RESET (0x01 << 1)
#define	TLE5012B_ACTIVATE_HARDWARE_RESET (0x01 << 0)


typedef struct
{
    float angle;      // Current angle in degrees
    float angle_multi_deg; // Continuous angle in degrees with multiple revolutions
    float prevAngle;  // Previous angle (for diff)
    float fullAngle;  // Continuous angle with revolutions
    float rpm;        // Speed in RPM
    int16_t revs;     // Revolution count
    uint8_t raw[8];   // Raw SPI data for debug
} TLE_EncoderData_t;


typedef struct //probably change to my pins
{
    SPI_HandleTypeDef *spi;
    GPIO_TypeDef *csPort;
    uint16_t csPin;
    TLE_EncoderData_t data;
    float angleZero;  // Offset correction (zero position)
} TLE_Encoder_t;


void TLE_Encoder_Init(TLE_Encoder_t *enc,SPI_HandleTypeDef *spi,GPIO_TypeDef *csPort,uint16_t csPin);

float TLE_Encoder_ReadAngle(TLE_Encoder_t *enc);
float TLE_Encoder_GetAngle(TLE_Encoder_t *enc);
float TLE_Encoder_GetAngleMultiDeg(TLE_Encoder_t *enc);
float TLE_Encoder_GetSpeed(TLE_Encoder_t *enc);
void TLE_Encoder_SetZero(TLE_Encoder_t *enc);
void TLE_Encoder_Reset(TLE_Encoder_t *enc);




#endif /* INC_TLE_ENCODER_H_ */
