/**
 * @file Module.h
 * @author Diana Riscanu
 * @brief Base Module class
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_MODULE_H_
#define _INCLUDE_ROU_MODULE_H_

#include "Handle.h"
#include <ArduinoExtra.h>

namespace rou
{

template<uint16_t HandleCount>
class Module
{
public:
	void setup()
	{
		for (uint16_t i = 0; i < HandleCount; i++)
		{
			m_handles[i]->initialize(); //might not be req
		}
	}

	virtual void update() = 0;

private:
	aex::Array<Handle, HandleCount> m_handles;
};

} // namespace rou

#endif // _INCLUDE_ROU_MODULE_H_
