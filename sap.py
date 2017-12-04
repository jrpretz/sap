import struct
import numpy as np


def read(infileName):
    infile = open(infileName,"rb")
    infile_data = infile.read()

    start = 0

    returned = {}

    while start < len(infile_data):
        strlen = struct.unpack('I',infile_data[start:start+4])[0]
        start += 4

        name = infile_data[start:start + strlen]
        start += strlen

        columns,rows = struct.unpack('II',infile_data[start:start+8])
        start += 8

        data = np.array(struct.unpack('d'*(columns*rows),infile_data[start:start+rows*columns*8]))
        start += rows*columns*8

        data = data.reshape(columns,rows)

        returned[name] = data
    return returned

def write(outfileName,data):
    outfile = open(outfileName,"wb")

    keys = data.keys()

    for k in keys:
        packed = ""
        packed = packed + struct.pack('I',len(k))
        packed = packed + k

        matrix = data[k]

        columns = matrix.shape[0]
        rows = matrix.shape[1]
        packed = packed + struct.pack('I',columns)
        packed = packed + struct.pack('I',rows)

        m = matrix.reshape(columns*rows).tolist()
        packed = packed + struct.pack('d'*rows*columns,*m)

        outfile.write(packed)
