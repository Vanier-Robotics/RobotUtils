#include <ArduinoExtra.h>
#include <CrcLib.h>

using namespace Crc;


void setup() {
  // put your setup code here, to run once:
  CrcLib::Initialize();
  CrcLib::InitializePwmOutput(CRC_PWM_12);
  // CrcLib::InitializePwmOutput(CRC_PWM_1);
  
  aex::Array<int, 5> test;
  aex::Vector<char> tets2;
  test.at(0) = 2;
  tets2[2] = 2;
}


void loop() {
  // put your main code here, to run repeatedly:
  CrcLib::Update();
  CrcLib::SetPwmOutput(CRC_PWM_12, 200);
  // CrcLib::SetPwmOutput(CRC_PWM_1, 400);
}
