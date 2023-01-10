// #include <stdint.h>
class Handle {
protected:
  bool available;

public:
  Handle() { available = true; }

  bool isAvailable() { return available; }

  void use() { this->available = true; }

  void release() { this->available = false; }
};
