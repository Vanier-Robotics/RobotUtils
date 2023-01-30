/**
 * @file EncodereHandle.h
 * @author Jiucheng Zang
 * @brief Encoder Handle
 * @version 0.1
 * @date 2023-01-30
 * 
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 * 
 */

#ifndef _INCLUDE_ROU_ENCODER_HANDLE_H_
#define _INCLUDE_ROU_ENCODER_HANDLE_H_

#include "../Handle.h"
#include <CrcLib.h>
#include <Encoder.h>

namespace rou
{

/**
 * @brief Encoder Handle class
 * 
 * @extends Handle class
 */
class EncoderHandle : public Handle
{
public:
    /**
     * @brief Construct a new Encoder Handle object with one interrupt
     * 
     * @param PinA Singal A
     * @param PinB SIngle B
     */
    EncoderHandle(int8_t pinA, int8_t pinB)
    {
        m_pin_a = pinA;
        m_pin_b = pinB;
        position = 0;
    }

    /**
     * @brief Construct a new Encoder Handle object with one interrupt (Given initial position)
     * 
     * @param pinA 
     * @param pinB 
     * @param initialPositon 
     */
    EncoderHandle(int8_t pinA, int8_t pinB, long int initialPositon) 
    {
        m_pin_a = pinA;
        m_pin_b = pinB;
        position = initialPositon;
    }

    /**
     * @brief Update Status of Encoder
     * 
     */
    void UpdateEncoder()
    {
        if (digitalRead(m_pin_a)) digitalRead(m_pin_b) ? position++ : position--;
        else digitalRead(m_pin_b) ? position-- : position++;
    }
    
    /**
     * @brief Get the Position object
     * 
     * @return long int 
     */
    long int getPosition () {
      return position;
    };

    /**
     * @brief Set the Position object
     * 
     * @param p 
     */
    void setPosition (const long int p) {
      position = p;
    };

    /**
     * @brief Get the Pin object
     * 
     * @return uint8_t* 
     */
    uint8_t * getPin()
	{
        int8_t Pin = {m_pin_a,m_pin_b};
		return Pin;
	}

protected:
    /**
     * @brief Setup For Encoder
     * 
     */
	void setup() override
	{
        pinMode(m_pin_a, INPUT);
        pinMode(m_pin_b, INPUT);
        digitalWrite(m_pin_a, HIGH); // and turn on pull-up resistors
        digitalWrite(m_pin_b, HIGH);
	}

private:
    long int position;
    int8_t m_pin_a;
    int8_t m_pin_b;
};

} // namespace rou

#endif // _INCLUDE_ROU_ENCODER_HANDLE_H_
