# sap
simple array persistency

This library, if it deserves that name, is an attempt to solve a problem
I've had a dozen times, gluing numpy and c++. There are good file formats
for simple array persistency (hd5 or npz for example) but they kinda fail when 
going cross-language. HD5 is probably the most suitable, but it's a 
drill when I need a screwdriver. 

The files are lists of key/value pairs. The keys are strings. The values
are MxN matricies. 

The test-python-1.py and test-cxx-1 programs create a file written 
in python and c++ respectively. The XXX-2 programs read them back in to 
check. 

It also achieves one of my main design criteria. To not have a new crazy
library to link to. The "libraries" are one file each, sap.h and sap.py. 
Can be dropped in pretty much anywhere
