/**
 * @file DigitalInputModule.h
 * @author Diana Riscanu
 * @brief DigitalInputModule class
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_DIGITAL_INPUT_MODULE_H_
#define _INCLUDE_ROU_DIGITAL_INPUT_MODULE_H_

#include "../Handles/DigitalInputHandle.h"
#include "../Module.h"

namespace rou
{

class DigitalInputModule : public Module
{
public:
	DigitalInputModule(DigitalInputHandle& digitalInputHandle)
	{
		m_digitalInputHandle = &digitalInputHandle;
	}

	void setup()
	{
		CrcLib::SetDigitalPinMode(digitalInputHandle, INPUT);
	}

	bool switchStatus()
	{
		return (CrcLib::GetDigitalInput(digitalInputHandle) == HIGH);
	}

private:
	DigitalInputHandle* m_digitalInputHandle;
};

} // namespace rou

#endif // _INCLUDE_ROU_DIGITAL_INPUT_MODULE_H_
