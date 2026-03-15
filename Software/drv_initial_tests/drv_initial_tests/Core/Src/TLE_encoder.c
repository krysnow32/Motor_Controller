

#include "TLE_encoder.h"
#include "math.h"

void TLE_Encoder_ReadBytes(TLE_Encoder_t* enc, uint16_t reg, uint8_t* data, uint8_t len)
{
	HAL_GPIO_WritePin(enc->csPort, enc->csPin, GPIO_PIN_RESET); //if errors try cs.port cs.pin

	reg |= TLE5012B_READ_REGISTER + (len >> 1);
	uint8_t txbuffer[2] = { (uint8_t)(reg >> 8), (uint8_t)(reg & 0x00FF) };
	HAL_SPI_Transmit(enc->spi, txbuffer, 2, 100);
	HAL_SPI_Receive(enc->spi, data, len + 2, 100);

	HAL_GPIO_WritePin(enc->csPort, enc->csPin, GPIO_PIN_SET);
}

void TLE_Encoder_WriteBytes(TLE_Encoder_t* enc, uint16_t reg, uint16_t data)
{
	HAL_GPIO_WritePin(enc->csPort, enc->csPin, GPIO_PIN_RESET);

	uint8_t txbuffer[4] = { (uint8_t)(reg >> 8), (uint8_t)(reg & 0x00FF), (uint8_t)(data >> 8), (uint8_t)(data & 0x00FF) };
	HAL_SPI_Transmit(enc->spi, txbuffer, sizeof(txbuffer), 100); // TODO check return value for error

	HAL_GPIO_WritePin(enc->csPort, enc->csPin, GPIO_PIN_SET);
}

void TLE_Encoder_Init(TLE_Encoder_t *enc,
                      SPI_HandleTypeDef *spi,
                      GPIO_TypeDef *csPort,
                      uint16_t csPin)
{
    enc->spi = spi;
    enc->csPort = csPort;
    enc->csPin = csPin;
    enc->angleZero = 0.0f;
    enc->data.angle = 0.0f;
    enc->data.angle_multi_deg = 0.0f;
    enc->data.fullAngle = 0.0f;
    enc->data.revs = 0;
    enc->data.rpm = 0.0f;

    TLE_Encoder_Reset(enc);
}

uint16_t TLE_Encoder_ReadRawAngle(TLE_Encoder_t* enc)
{
	return (((uint16_t)enc->data.raw[0] << 8) | enc->data.raw[1]) & 0x7FFF;
}

int16_t TLE_Encoder_ReadRawSpeed(TLE_Encoder_t* enc)
{
	int16_t speed = enc->data.raw[3];
	speed |= ((uint16_t)enc->data.raw[2] << 8) & 0x3FFF;
	speed |= ((enc->data.raw[2] & 0x40) == 0 ? 0x00 : 0xC0) << 8;
	return speed;
}


void TLE_Encoder_Reset(TLE_Encoder_t *enc)
{
    HAL_GPIO_WritePin(enc->csPort, enc->csPin, GPIO_PIN_RESET);
    uint8_t txbuf[4] = { (uint8_t)(TLE5012B_ACTIVATION_REG >> 8),
                         (uint8_t)(TLE5012B_ACTIVATION_REG & 0xFF),
                         (uint8_t)(TLE5012B_ACTIVATE_HARDWARE_RESET >> 8),
                         (uint8_t)(TLE5012B_ACTIVATE_HARDWARE_RESET & 0xFF) };
    HAL_SPI_Transmit(enc->spi, txbuf, 4, 100);
    HAL_GPIO_WritePin(enc->csPort, enc->csPin, GPIO_PIN_SET);
    HAL_Delay(10);
}



float TLE_Encoder_ReadAngle(TLE_Encoder_t *enc)
{
    // Read 6 bytes of data from angle register
    TLE_Encoder_ReadBytes(enc, TLE5012B_ANGLE_REG, enc->data.raw, 6);

    uint16_t rawAngle = TLE_Encoder_ReadRawAngle(enc);
    //int16_t rawSpeed = TLE_Encoder_ReadRawSpeed(enc);

    //enc->data.prevAngle = enc->data.angle;
    enc->data.angle = (360.0f / TLE5012B_CPR) * rawAngle;

    // Wraparound handling for continuous angle
    /*
    float delta = enc->data.angle - enc->data.prevAngle;
    if (delta > 180.0f)
        enc->data.revs--;
    else if (delta < -180.0f)
        enc->data.revs++;
     */
    //enc->data.fullAngle = enc->data.angle + 360.0f * enc->data.revs;

    // Speed conversion (depends on internal sensor rate, adjust if needed)
    //float deg_scale = 360.0f / TLE5012B_CPR;
    //float speed = rawSpeed * deg_scale;
    //enc->data.rpm = speed / 6.0f; // ~Deg/s to RPM

    return TLE_Encoder_GetAngle(enc);
}

float TLE_Encoder_GetAngle(TLE_Encoder_t *enc)
{
    //return enc->data.fullAngle - enc->angleZero;
		return enc->data.angle - enc->angleZero;
}
float TLE_Encoder_GetAngleMultiDeg(TLE_Encoder_t *enc)
{
    return enc->data.angle_multi_deg;
}

float TLE_Encoder_GetSpeed(TLE_Encoder_t *enc)
{
    return enc->data.rpm;
}

void TLE_Encoder_SetZero(TLE_Encoder_t *enc)
{
   // enc->angleZero = enc->data.fullAngle;
		enc->angleZero = enc->data.angle;
}
