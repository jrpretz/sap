import sap

matrixstack_read = sap.read("python-write.dat")

print matrixstack_read.keys(),"expect ['matrix,matrix_two']"
print matrixstack_read["matrix"].shape,"expect (100,5)"
for i in range(matrixstack_read["matrix"].shape[0]):
    for j in range(matrixstack_read["matrix"].shape[1]):
        print matrixstack_read["matrix"][i][j],"expect %d"%(i*j)

print matrixstack_read["matrix_two"].shape,"expect (20,50)"
for i in range(matrixstack_read["matrix_two"].shape[0]):
    for j in range(matrixstack_read["matrix_two"].shape[1]):
        print matrixstack_read["matrix_two"][i][j],"expect %d"%(i+j)
