#include "sap.h"

using namespace sap;
using namespace std;

int main(){
  map<string,Matrix> mstack = read_matrix("python-write.dat");

  cout<<mstack["matrix"].columns()<<","<<mstack["matrix"].rows()<<endl;
  for(unsigned i = 0 ; i < mstack["matrix"].columns() ; i++){
    for(unsigned j = 0 ; j < mstack["matrix"].rows() ; j++){
      cout<<mstack["matrix"][i][j]<<"=?="<<i*j<<endl;
    }
  } 
  
}
