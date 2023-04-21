#include <iostream>
#include <time.h>
#include <cstdio>
#include <fstream>
#include <string>

using namespace std;



int main() {

    int value1, value2, lines, columns;

    cout << "Enter number of values of first matrix" << endl;
    cin >> value1;
    cout << "Enter number of values of second matrix" << endl;
    cin >> value2;
    cout << "enter number of lines of matrices: " << endl;
    cin >> lines;
    cout << "enter number of columns of matrices " << endl;
    cin >> columns;


    int values1[value1];
    int line_umbers1[value1];
    int column_numbers1[value1];

    int values2[value2];
    int line_umbers2[value2];
    int column_numbers2[value2];


    ifstream file1("C:/files/file1.txt");
    ifstream file2("C:/files/file2.txt");

    if (file1.is_open()) {
        for (int i = 0; i < value1; i++) {
            file1 >> values1[i];
        }
        cout << endl;
        for (int i = 0; i < value1; i++) {
            file1 >> line_umbers1[i];
        }
        cout << endl;
        for (int i = 0; i < value1; i++) {
            file1 >> column_numbers1[i];
        }

        file1.close();
    }
    else cout << "file is not open" << endl;

    if (file2.is_open()) {
        for (int i = 0; i < value2; i++) {
            file2 >> values2[i];
        }
        cout << endl;
        for (int i = 0; i < value2; i++) {
            file2 >> line_umbers2[i];
        }
        cout << endl;
        for (int i = 0; i < value2; i++) {
            file2 >> column_numbers2[i];
        }

        file1.close();
    }
    else cout << "file is not open" << endl;


    int matrix1[lines][columns];
    int matrix2[lines][columns];

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            matrix1[i][j] = 0;
        }
    }
    for (int i = 0; i < value1; i++) {
        matrix1[line_umbers1[i] - 1][column_numbers1[i] - 1] = values1[i];
    }

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            matrix2[i][j] = 0;
        }
    }
    for (int i = 0; i < value2; i++) {
        matrix2[line_umbers2[i] - 1][column_numbers2[i] - 1] = values2[i];
    }

    cout << "the first matrix :" << endl;
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "the second matrix :" << endl;
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int matrix3[lines][columns];
    int count = 0;

    cout << "Matrix3 = matrix1 * matrix2: " << endl;
    cout << endl;
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < lines; j++) {
            matrix3[i][j] = 0;
            for (int k = 0; k < lines; k++) {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            cout << matrix3[i][j] << " ";
            if (matrix3[i][j] != 0) {
                count = count + 1;
            }

        }
        cout << endl;
    }

    cout << endl;

    int values3[count];
    int lines_number3[count];
    int first_element[lines + 1];
    int n = lines;
    int k = 0;

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < lines; j++) {
            if (matrix3[i][j] != 0) {
                values3[k] = matrix3[i][j];
                lines_number3[k] = i + 1;
                k += 1;
            }
        }
    }

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < lines; j++) {
            if (matrix3[j][i] != 0) {
                if (j <= n) {
                    first_element[i] = matrix3[j][i];
                    n = j;
                }
            }

        }
        n = lines;
    }

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < lines; j++) {
            if (first_element[i] == values3[j]) {
                first_element[i] = j + 1;
            }
        }

    }

    first_element[lines] = count;

    cout << "the final CCS of the matrix: " << endl;
    cout << "array of values: ";

    for (int i = 0; i < count; i++) {
        cout << values3[i] << " ";
    }

    cout << endl;

    cout << "array of line numbers: ";

    for (int i = 0; i < count; i++) {
        cout << lines_number3[i] << " ";
    }

    cout << endl;

    cout << "array of the first elements of each column: ";

    for (int i = 0; i < lines + 1; i++) {
        cout << first_element[i] << " ";
    }



    return 0;
}


