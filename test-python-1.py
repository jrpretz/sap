import sap
import numpy as np

matrix = np.zeros(shape=(100,5))

for i in range(100):
    for j in range(5):
        matrix[i][j] = i * j

matrixCollection = {}
matrixCollection["matrix"] = matrix

sap.write("python-write.dat",matrixCollection)
