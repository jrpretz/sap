# this is not proper testing, but this is the programs
# and the programs to run to see if this is working

if [ ! -f test-cxx-1 ] ; then
echo "need test-cxx-1"
exit
fi

if [ ! -f test-cxx-2 ] ; then
echo "need test-cxx-2"
fi

if [ ! -f test-cxx-3 ] ; then
echo "need test-cxx-3"
fi

./test-cxx-1
python test-python-1.py

./test-cxx-2
python test-python-2.py

./test-cxx-3
python test-python-3.py
