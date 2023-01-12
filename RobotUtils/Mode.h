/**
 * @file Mode.h
 * @author Elisa Moscato
 * @brief The base of modes
 * 
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_MODE_H_
#define _INCLUDE_ROU_MODE_H_
#include "ArduinoExtra.h"

namespace rou
{
    class Mode
    {
        protected:
        aex::Vector <Module> m_modules;
        Controller m_controller;
        
        public:
        virtual void update(float dt) = 0;
        virtual void setup (float dt) = 0;

    }


} // rou

#endif // _INCLUDE_ROU_MODE_H_
