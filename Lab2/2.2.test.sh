python2.7 2.2.produce_data.py
gcc 2.2.matrix.c -o matrix -pthread
./matrix > 2.2.ans
# if #define READ_TEST 1 and comment ANS_TEST then uncomment data and comment ans
# diff --strip-trailing-cr 2.2.ans 2.2.data.csv
diff --strip-trailing-cr 2.2.ans 2.2.ans.csv
rm matrix 2.2.ans 2.2.data.csv 2.2.ans.csv