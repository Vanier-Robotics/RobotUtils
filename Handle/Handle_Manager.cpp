#include "Handle.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Handle_Manager : public Handle {
private:
  vector<Handle> handles;

public:
  Handle_Manager(int lens_ports) {
    for (int i = 1; i <= lens_ports; i++) {
      handles.push_back(Handle(i, false, false));
    }
  }

  void to_string() {
    for (Handle handle : handles) {
      cout << "port: ";
      cout << (int)handle.getport();
      cout << "\nStatus: ";
      cout << handle.status();
      cout << "\n\n";
    }
  }

  void release_all() {
    for (Handle handle : handles) {
      handle.release();
    }
    // handles.erase(handles.begin(), handles.begin() + handles.size());
  }

  void addHandle(uint8_t port) {
    for (Handle handle : handles) {
      if (handle.getport() == port) {
        if (handle.status() == false) {
          handle.use();
          // cout << handle.status() << "Hello";
          break;
        }
      }
    }
  }

  bool status(uint8_t port) {
    for (Handle handle : handles) {
      if (handle.getport() == port) {
        return handle.status();
      }
    }
  }

  void shared_ports(vector<Handle> handles) {
    for (Handle handle : handles) {
      addHandle(handle.getport());
    }
  }
};