"""produce data for matrix
example:
2,3,2
00,01,02
10,11,12
00,01
10,11
20,21

means:
A = 2 X 3
B =     3 X 2
A =  0,  1,  2
    10, 11, 12
B =  0,  1
    10, 11
    20, 21
"""

import random
import csv

# max value 1000^3 < 1<<31
MATRIX_MAX_SIZE = 1000
DATA_FILE_NAME = "2.2.data.csv"
ANS_FILE_NAME = "2.2.ans.csv"


def prouce_value():
    """produce a random value in [1, MATRIX_MAX_SIZE]"""
    return random.randint(1, MATRIX_MAX_SIZE)


def produce_matrix(row, column):
    """prodece a random num matrix"""
    return [[prouce_value() for _ in xrange(0, column)] for _ in xrange(0, row)]


def write_data_file(matrix1, matrix2):
    """write two matrix to file"""
    with open(DATA_FILE_NAME, "wb") as outfile:
        head_info = [[len(matrix1), len(matrix1[0]), len(matrix2[0])]]
        csv_writer = csv.writer(outfile)
        csv_writer.writerows(head_info + matrix1 + matrix2)


def cal_ans(matrix1, matrix2):
    """cal the ans matrix"""
    return [[sum(a * b for a, b in zip(row_1, row_2))
             for row_2 in zip(*matrix2)] for row_1 in matrix1]


def write_ans_file(ans):
    """write One matrix to file"""
    with open(ANS_FILE_NAME, "wb") as outfile:
        head_info = [[len(ans), len(ans[0])]]
        csv_writer = csv.writer(outfile)
        csv_writer.writerows(head_info + ans)


if __name__ == "__main__":
    SAME = prouce_value()
    A = produce_matrix(prouce_value(), SAME)
    B = produce_matrix(SAME, prouce_value())
    write_data_file(A, B)
    write_ans_file(cal_ans(A, B))
