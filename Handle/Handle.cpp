#include <stdint.h>
class Handle {
protected:
  uint8_t port;
  bool isOutput;
  bool isReversed;

public:
  Handle() {}
  Handle(uint8_t port, bool isOutput, bool isReversed) {
    this->port = port;
    this->isOutput = isOutput;
    this->isReversed = isReversed;
  }

  uint8_t getport() { return port; }

  bool getisOutput() { return isOutput; }

  bool status() { return isReversed; }

  void use() { this->isReversed = true; }

  void release() { this->isReversed = false; }
};
