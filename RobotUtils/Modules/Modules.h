/**
 * @file Modules.h
 * @author Diana
 * @brief Base Module class
 * 
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_MODULES_H_
#define _INCLUDE_ROU_MODULES_H_

#include "ArduinoExtra.h"
#include "../Handle/Handle.h"
namespace rou
{


template<uint16_t handleCount>
class Module
{
    public:
   
    void setup()
    {
      for (uint16_t i = 0; i < handleCount; i++)
        {
          m_handles[i]->initialize(); //might not be req
        }
        
    }
   
    virtual void update() = 0;

    private:
    aex::Array<Handle, handleCount> m_handles;

};

} //namespace rou
#endif // _INCLUDE_ROU_MODULES_H_