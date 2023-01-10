#include "Handle.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Handle_Manager {
private:
  vector<Handle> handles;

public:
  Handle_Manager() {}

  void to_string() {
    for (Handle handle : handles) {
      cout << "\nStatus: ";
      cout << handle.isAvailable();
      cout << "\n\n";
    }
  }

  void release_all() {
    for (Handle handle : handles) {
      handle.release();
    }
  }

  void addHandle(Handle handle) { handles.push_back(handle); }
};