/**
 * @file DigitalInputModule.h
 * @author Diana Riscanu
 * @brief DigitalInputModule class
 * 
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_DIGITAL_INPUT_MODULE_H_
#define _INCLUDE_ROU_DIGITAL_INPUT_MODULE_H_

//#include "ArduinoExtra.h"
//#include "DigitalInputHandle.h"
#include "Modules.h"



namespace rou
{
    class DigitalInputModule : public Module
    {
        public:
        DigitalInputModule (DigitalInputHandle& switchHandle)
        {
          m_switchPin = &switchHandle;
        }

        void setup()
        {
          CrcLib::SetDigitalPinMode(switchHandle, INPUT);
        }

        bool switchStatus()
        //verify if switch is on or off
        {
          return (CrcLib::GetDigitalInput(switchHandle) == HIGH);
        }

        private:
        DigitalInputHandle* m_switchHandle;
    };
} // rou

#endif // _INCLUDE_ROU_DIGITAL_INPUT_MODULE_H_
