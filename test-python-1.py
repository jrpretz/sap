import sap
import numpy as np

matrix = np.zeros(shape=(100,5))

for i in range(100):
    for j in range(5):
        matrix[i][j] = i * j

matrixCollection = {}
matrixCollection["matrix"] = matrix

matrix = np.zeros(shape=(20,50))

for i in range(20):
    for j in range(50):
        matrix[i][j] = i + j

matrixCollection["matrix_two"] = matrix

sap.write("python-write.dat",matrixCollection)
