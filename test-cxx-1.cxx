#include "sap.h"

//using namespace sap;
//using namespace std;

int main(){
  sap::Matrix m(100,5);
  for(unsigned i = 0 ; i < 100 ; i++){
    for(unsigned j = 0 ; j < 5 ; j++){
      m[i][j] = i*j;
    }
  } 
  std::map<std::string,sap::Matrix> mstack;
  mstack["matrix"] = m;
  sap::write_matrix("cxx-write.dat",mstack);
}
