/**
 * @file EncodereHandle.h
 * @author Jiucheng Zang
 * @brief Handle for managing an encoder object, using Paul Stoffergen's Encoder library
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
 * @brief Handle for managing an encoder
 *
 * @extends Handle
 */
class EncoderHandle : public Handle
{
public:
    /**
     * @brief Create a new EncoderHandle using two pins
     *
     * @param pinA first signal pin
     * @param pinB second signal pin
	 *
	 * @see https://robocrc.atlassian.net/wiki/spaces/AR/pages/560464130/CrcDuino+Hardware+Details#Encoder-Port for more details
	 * For best performance, both pins should have interrupt capabilities. For good performance, at least one of them should.
     */
    EncoderHandle(int8_t pinA, int8_t pinB)
	: m_encoder(pinA, pinB) // unfortunatly, this cannot go in the setup() method
    {
        m_pinA = pinA;
        m_pinB = pinB;
    }

    /**
     * @brief Get the position of the motor
     *
     * @return int32_t the value read directly from the encoder object
     */
    int32_t getValue() const
	{
		m_encoder.read();
    }

    /**
     * @brief Get the first signal pin number
     *
     * @return uint8_t the CrcLib pin number
     */
    uint8_t getPinA()
	{
        return m_pinA;
	}

	/**
	 * @brief Get the second signal pin number
	 *
	 * @return uint8_t the CrcLib pin number
	 */
	uint8_t getPinB()
	{
		return m_pinB;
	}

private:
    Encoder m_encoder; ///< encoder object that measures the rotation based on the two signal pins supplied

    int8_t m_pinA; ///< first CrcLib signal pin to which this object is associated
    int8_t m_pinB; ///< second CrcLib signal pin to which this object is associated
};

} // namespace rou

#endif // _INCLUDE_ROU_ENCODER_HANDLE_H_
