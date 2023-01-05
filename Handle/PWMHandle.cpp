#include <stdint.h>
#include "Handle.cpp"

class PWMHandle : public Handle 
{
    private:
        uint8_t port;
        bool isOutput;
        bool isReversed;
    public:
    PWMHandle(uint8_t x, bool y, bool z){
        port =x;
        isOutput = y;
        isReversed = z;
    }

    uint8_t getport(){
        return port;
    }

    bool getisOutput(){
        return isOutput;
    }

    bool getisReversed(){
        return isReversed;
    }

};