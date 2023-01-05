/**
 * @file ModeManager.h
 * @author Elisa Moscato
 * @brief ??
 * 
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_MODE_MANAGER_H_
#define _INCLUDE_ROU_MODE_MANAGER_H_
#include "Arduino.Extra.h"
#include "CrcLib.h"
#include "ArxSmartPtr.h"

namespace rou
{
    class ModeManager
    {
        private:
        Mode* m_nextMode = nullptr;
        Mode* m_curentMode = nullptr;


        public:
        void update(float dt)
        {
            if(m_currentMode)
            {
                m_currentMode->update(dt);
            }

            if(m_nextMode)
            {
                if(m_curentMode)
                m_currentMode-> unload();

                m_currentMode = m_nextMode;
                m_currentMode-> load();
                m_nextMode = nullptr;
            }
        }
        
        void changeMode(Mode*nextMode)
        {
            m_nextMode = nextMode;
        }

    }

} // rou

#endif // _INCLUDE_ROU_MODE_MANAGER_H_
