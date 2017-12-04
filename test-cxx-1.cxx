#include "sap.h"

int main(){
  sap::Matrix m(100,5);
  for(unsigned i = 0 ; i < 100 ; i++){
    for(unsigned j = 0 ; j < 5 ; j++){
      m[i][j] = i*j;
    }
  } 

  std::map<std::string,sap::Matrix> mstack;
  mstack["matrix"] = m;

  sap::Matrix m2(20,50);
  for(unsigned i = 0 ; i < 20 ; i++){
    for(unsigned j = 0 ; j < 50 ; j++){
      m2[i][j] = i+j;
    }
  } 
  mstack["matrix_two"] = m2;

  sap::write_matrix("cxx-write.dat",mstack);



}
