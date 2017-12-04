import sap

matrixstack_read = sap.read("cxx-write.dat")

print matrixstack_read.keys(),"expect ['matrix']"

print matrixstack_read["matrix"].shape,"expect (100,5)"

for i in range(matrixstack_read["matrix"].shape[0]):
    for j in range(matrixstack_read["matrix"].shape[1]):
        print matrixstack_read["matrix"][i][j],"expect %d"%(i*j)
# #include "sap.h"

# using namespace sap;
# using namespace std;

# int main(){

#   map<string,Matrix> mstack = read_matrix("cxx-write.dat");

#   cout<<mstack["matrix"].columns()<<","<<mstack["matrix"].rows()<<endl;
#   for(unsigned i = 0 ; i < mstack["matrix"].columns() ; i++){
#     for(unsigned j = 0 ; j < mstack["matrix"].rows() ; j++){
#       cout<<mstack["matrix"][i][j]<<"=?="<<i*j<<endl;
#     }
#   } 
  
# }
