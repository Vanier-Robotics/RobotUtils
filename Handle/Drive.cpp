#include "Handle_Manager.cpp"
#include <iostream>
using namespace std;
int main() {
  Handle_Manager hm = Handle_Manager();
  Handle handle = Handle();
  hm.addHandle(handle);
  hm.to_string();
}