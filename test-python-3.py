import sap

matrixstack_read = sap.read("cxx-write.dat")

print matrixstack_read.keys(),"expect ['matrix']"

print matrixstack_read["matrix"].shape,"expect (100,5)"

for i in range(matrixstack_read["matrix"].shape[0]):
    for j in range(matrixstack_read["matrix"].shape[1]):
        print matrixstack_read["matrix"][i][j],"expect %d"%(i*j)
