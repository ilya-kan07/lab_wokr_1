#include <iostream>
#include <time.h>
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;

void clear_memory(int* arr);
void clear_memory(int** arr, int lines);

void fill_array(string path, int* values, int* line, int* column, int value);

void create_matrix(int** matrix, int line, int column);
void fill_matrix(int** matrix, int line, int column, int value, int* lines, int* columns, int* values);
void print_matrix(int** matrix, int line, int column);

void print_array(int* arr, int count);


int main() {

    setlocale(LC_ALL, "ru");

    int value1, value2, lines, columns;
    string path_file1 = "C:/files/file1.txt";
    string path_file2 = "C:/files/file2.txt";


    cout << "Введите кол-во ненулевых значений 1-ой и 2-ой матрицы: "; cin >> value1 >> value2;
    cout << "Введите кол-во строк и столбцов матриц: "; cin >> lines >> columns; 

    int* values1 = new int[value1];
    int* line_umbers1 = new int[value1];
    int* column_numbers1 = new int[value1];

    int* values2 = new int[value2];
    int* line_umbers2 = new int[value2];
    int* column_numbers2 = new int[value2];


    fill_array(path_file1, values1, line_umbers1, column_numbers1, value1);
    fill_array(path_file2, values2, line_umbers2, column_numbers2, value2);

    int** matrix1 = new int* [lines];
    int** matrix2 = new int* [lines];
    int** matrix3 = new int* [lines];
    create_matrix(matrix1, lines, columns);
    create_matrix(matrix2, lines, columns);
    create_matrix(matrix3, lines, columns);

    fill_matrix(matrix1, lines, columns, value1, line_umbers1, column_numbers1, values1);
    fill_matrix(matrix2, lines, columns, value2, line_umbers2, column_numbers2, values2);

    cout << "Первая матрица: " << endl;
    print_matrix(matrix1, lines, columns);
    cout << "Вторая матрица: " << endl;
    print_matrix(matrix2, lines, columns);

    int count = 0;

    cout << "Матрица произведения: " << endl;
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < lines; j++) {
            matrix3[i][j] = 0;
            for (int k = 0; k < lines; k++) {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            if (matrix3[i][j] > 9) cout << matrix3[i][j] << "  ";
            else cout << matrix3[i][j] << "   ";
            if (matrix3[i][j] != 0) {
                count = count + 1;
            }

        }
        cout << endl;
    }
    cout << endl;

    int* values3 = new int[count];
    int* lines_number3 = new int[count];
    int* first_element = new int[lines + 1];
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

    cout << "Окончательный вариант матрицы: " << endl << endl;

    cout << "Массив значений: ";
    print_array(values3, count);

    cout << "Массив номеров строк: ";
    print_array(lines_number3, count); 

    cout << "Массив первых элементов каждого столбца: ";
    print_array(first_element, lines);


    clear_memory(values1);
    clear_memory(line_umbers1);
    clear_memory(column_numbers1);

    clear_memory(values2);
    clear_memory(line_umbers2);
    clear_memory(column_numbers2);

    clear_memory(matrix1, lines);
    clear_memory(matrix2, lines);
    clear_memory(matrix2, lines);

    return 0;
}

void clear_memory(int* arr)
{
    delete[] arr;
}

void clear_memory(int** arr, int lines)
{
    for (int i = 0; i < lines; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

void fill_array(string path, int* values, int* line, int* column, int value)
{
    ifstream file(path);
    if (file.is_open()) {
        for (int i = 0; i < value; i++) {
            file >> values[i];
        }
        cout << endl;
        for (int i = 0; i < value; i++) {
            file >> line[i];
        }
        cout << endl;
        for (int i = 0; i < value; i++) {
            file >> column[i];
        }

        file.close();
    }
    else cout << "file is not open" << endl;
}

void fill_matrix(int** matrix, int line, int column, int value, int* lines, int* columns, int* values)
{
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < column; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < value; i++) {
        matrix[lines[i] - 1][columns[i] - 1] = values[i];
    }
}

void print_matrix(int** matrix, int line, int column)
{
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < column; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void create_matrix(int** matrix, int line, int column)
{
    for (int i = 0; i < line; i++)
    {
        matrix[i] = new int[column];
    }
}

void print_array(int* arr, int count) 
{
    for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}