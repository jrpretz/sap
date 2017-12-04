#include "sap.h"

using namespace sap;
using namespace std;

int main(){

  map<string,Matrix> mstack = read_matrix("cxx-write.dat");

  cout<<mstack["matrix"].columns()<<","<<mstack["matrix"].rows()<<endl;
  for(unsigned i = 0 ; i < mstack["matrix"].columns() ; i++){
    for(unsigned j = 0 ; j < mstack["matrix"].rows() ; j++){
      cout<<mstack["matrix"][i][j]<<"=?="<<i*j<<endl;
    }
  } 

  cout<<mstack["matrix_two"].columns()<<","<<mstack["matrix_two"].rows()<<endl;
  for(unsigned i = 0 ; i < mstack["matrix_two"].columns() ; i++){
    for(unsigned j = 0 ; j < mstack["matrix_two"].rows() ; j++){
      cout<<mstack["matrix_two"][i][j]<<"=?="<<i+j<<endl;
    }
  } 
  
}
