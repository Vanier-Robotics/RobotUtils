#include "Handle_Manager.cpp"
#include <iostream>
using namespace std;
int main() {
  Handle_Manager hm = Handle_Manager(12);
  hm.addHandle(8);
  // hm.addHandle(11);
  // hm.release_all();
  // hm.use();
  //   hm.addHandle(11);
  //   cout << hm.status() << endl;
  hm.to_string();
}