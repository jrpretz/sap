#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class Matrix{
public:
  Matrix(unsigned columns,unsigned rows) : 
    data_(rows*columns),
    columns_(columns),
    rows_(rows){
  }
  
  Matrix() : 
    data_(),
    columns_(0),
    rows_(0){
  }
	 
  double* operator[](unsigned column){
    return data() + rows_ * column;
  }

  const double* operator[](unsigned column) const{
    return data() + rows_ * column;
  }
  
  ~Matrix(){
  }

  unsigned rows() const {return rows_;}
  unsigned columns() const {return columns_;}

  const double* data() const {return &(data_[0]);}
  double* data() {return &(data_[0]);}

private:
  vector<double> data_;
  unsigned columns_;
  unsigned rows_;
};


void write_matrix(const std::string& outfileName,
		  const map<string,Matrix>& data){
  FILE* outfile = fopen(outfileName.c_str(),"w");
  for(map<string,Matrix>::const_iterator iter = data.begin() ; 
      iter != data.end() ; 
      iter++){
    if(sizeof(std::string::value_type) != 1){
      cerr<<"programming needs to improve to handle different OS"<<endl;
      exit(1);
    }
    if(sizeof(double) != 8){
      cerr<<"programming needs to improve to handle different OS"<<endl;
      exit(1);
    }
    if(sizeof(unsigned) != 4){
      cerr<<"programming needs to improve to handle different OS"<<endl;
      exit(1);
    }

    unsigned written_here = 0;
    unsigned name_size = iter->first.size();
    fwrite(&name_size,sizeof(unsigned),1,outfile);
    
    written_here = fwrite(iter->first.c_str(),sizeof(std::string::value_type),iter->first.size(),outfile);
    
    unsigned columns = iter->second.columns();
    written_here = fwrite(&(columns),sizeof(unsigned),1,outfile);

    unsigned rows = iter->second.rows();
    written_here = fwrite(&(rows),sizeof(unsigned),1,outfile);

    written_here = fwrite(iter->second.data(),sizeof(double),rows*columns,outfile);
  }
  fclose(outfile);
}

map<string,Matrix>  read_matrix(const std::string& infileName){
  FILE* infile = fopen(infileName.c_str(),"r");
  
  unsigned strsize = 0;

  map<string,Matrix> returned;

  while(fread(&strsize,sizeof(unsigned),1,infile)){
    if(strsize > 4095){
      cerr<<"strsize too big"<<endl;
      exit(1);
    }
    char name[4096];
    fread(name,sizeof(char),strsize,infile);
    name[strsize] = '\0';

    unsigned columns;
    fread(&columns,sizeof(unsigned),1,infile);

    unsigned rows;
    fread(&rows,sizeof(unsigned),1,infile);

    Matrix m(columns,rows);
    fread(m.data(),sizeof(double),rows*columns,infile);

    returned[name] = m;
  }
  fclose(infile);
  return returned;


}

int main(){
  Matrix m(100,5);
  for(unsigned i = 0 ; i < 100 ; i++){
    m[i][0] = 0+i;
    m[i][1] = 1+i;
    m[i][2] = 2+i;
    m[i][3] = 3+i;
    m[i][4] = 4+i;
  } 
  map<string,Matrix> mstack;
  mstack["w_1"] = m;
  write_matrix("foo.dat",mstack);

  for(map<string,Matrix>::const_iterator iter = mstack.begin() ; 
      iter != mstack.end() ;
      iter++){
    cout<<iter->first<<endl;
  }

  map<string,Matrix> mstack_read = read_matrix("foo.dat");
  for(map<string,Matrix>::const_iterator iter = mstack_read.begin() ; 
      iter != mstack_read.end() ;
      iter++){
    cout<<iter->first<<endl;
  }


  for(map<string,Matrix>::const_iterator iter = mstack.begin() ; 
      iter != mstack.end() ;
      iter++){
    cout<<mstack[iter->first].columns()<<" "<<mstack_read[iter->first].columns()<<endl;
    cout<<mstack[iter->first].rows()<<" "<<mstack_read[iter->first].rows()<<endl;

    for(unsigned i = 0 ; i < 100; i++){
      for(unsigned j = 0 ; j < 5 ; j++){
	cout<<mstack[iter->first][i][j]<<" "<<mstack_read[iter->first][i][j]<<endl;
      }
    }
  }


  //string foo("foo");
  //cout<<foo.size()<<endl;
}
