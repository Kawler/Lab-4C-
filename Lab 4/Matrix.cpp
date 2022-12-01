#include "Math.h"
#include <iomanip>
#include <stdexcept>

Matrix::Matrix()
{
    int Size = 0;
    cout << "Enter size of Matrix" << endl;
    while (Size <= 0 || Size > 20) {
        cout << "Choice:";
        cin >> Size;
    }
    size = Size;
    for (int i = 0; i < size; i++)
    {
        vector<double> myvector;
        for (int j = 0; j < size; j++)
        {
            int num = rand() % 100;
            myvector.push_back(num);
        }
        matrix.push_back(myvector);
    }
}

void Matrix::getData() {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


void Matrix::Extraction(Matrix obj1, Matrix obj2)
{
    vector<vector<double>> temp;
    if (obj1.size == obj2.size) {
        for (int i = 0; i < size; i++)
        {
            vector<double> myvector;
            for (int j = 0; j < size; j++)
            {
                myvector.push_back(obj1.matrix[i][j] - obj2.matrix[i][j]);
                cout << myvector[j] << '\t';
            }
            temp.push_back(myvector);
            cout << endl;
        }
    }
    else cout << "Matrixes have diffrenet size" << endl;
}

void Matrix::Addition(Matrix obj1, Matrix obj2)
{
    vector<vector<double>> temp;
    if (obj1.size == obj2.size) {
        for (int i = 0; i < size; i++)
        {
            vector<double> myvector;
            for (int j = 0; j < size; j++)
            {
                myvector.push_back(obj1.matrix[i][j] + obj2.matrix[i][j]);
                cout << myvector[j] << '\t';
            }
            temp.push_back(myvector);
            cout << endl;
        }
    }
    else cout << "Matrixes have diffrenet size" << endl;
}

void Matrix::Multiplication(Matrix obj1, float num)
{
    vector<vector<double>> temp;
    for (int i = 0; i < size; i++)
    {
        vector<double> myvector;
        for (int j = 0; j < size; j++)
        {
            myvector.push_back(obj1.matrix[i][j]*num);
            cout << myvector[j] << '\t';
        }
        temp.push_back(myvector);
        cout << endl;
    }
}

void Matrix::MultiplicationObj(Matrix obj1, Matrix obj2)
{
    vector<vector<double>> temp;
    if (obj1.size == obj2.size) {
        for (int i = 0; i < size; i++)
        {
            vector<double> myvector;
            for (int j = 0; j < size; j++)
            {
                myvector.push_back(obj1.matrix[i][j] * obj2.matrix[i][j]);
                cout << myvector[j] << '\t';
            }
            temp.push_back(myvector);
            cout << endl;
        }
    }
    else cout << "Matrixes have diffrenet size" << endl;
}

double getDeterminant(const std::vector<std::vector<double>> vect) {
    if (vect.size() != vect[0].size()) {
       cout<<"Matrix is not quadratic"<<endl;
    }
    int dimension = vect.size();

    if (dimension == 0) {
        return 1;
    }

    if (dimension == 1) {
        return vect[0][0];
    }

    //Formula for 2x2-matrix
    if (dimension == 2) {
        return vect[0][0] * vect[1][1] - vect[0][1] * vect[1][0];
    }

    double result = 0;
    int sign = 1;
    for (int i = 0; i < dimension; i++) {

        //Submatrix
        std::vector<std::vector<double>> subVect(dimension - 1, std::vector<double>(dimension - 1));
        for (int m = 1; m < dimension; m++) {
            int z = 0;
            for (int n = 0; n < dimension; n++) {
                if (n != i) {
                    subVect[m - 1][z] = vect[m][n];
                    z++;
                }
            }
        }

        //recursive call
        result = result + sign * vect[0][i] * getDeterminant(subVect);
        sign = -sign;
    }

    return result;
}

std::vector<std::vector<double>> getTranspose(const std::vector<std::vector<double>> matrix1) {

    //Transpose-matrix: height = width(matrix), width = height(matrix)
    std::vector<std::vector<double>> solution(matrix1[0].size(), std::vector<double>(matrix1.size()));

    //Filling solution-matrix
    for (size_t i = 0; i < matrix1.size(); i++) {
        for (size_t j = 0; j < matrix1[0].size(); j++) {
            solution[j][i] = matrix1[i][j];
        }
    }
    return solution;
}

std::vector<std::vector<double>> getCofactor(const std::vector<std::vector<double>> vect) {
    if (vect.size() != vect[0].size()) {
        cout<<"Matrix is not quadratic"<<endl;
    }

    std::vector<std::vector<double>> solution(vect.size(), std::vector<double>(vect.size()));
    std::vector<std::vector<double>> subVect(vect.size() - 1, std::vector<double>(vect.size() - 1));

    for (std::size_t i = 0; i < vect.size(); i++) {
        for (std::size_t j = 0; j < vect[0].size(); j++) {

            int p = 0;
            for (size_t x = 0; x < vect.size(); x++) {
                if (x == i) {
                    continue;
                }
                int q = 0;

                for (size_t y = 0; y < vect.size(); y++) {
                    if (y == j) {
                        continue;
                    }

                    subVect[p][q] = vect[x][y];
                    q++;
                }
                p++;
            }
            solution[i][j] = pow(-1, i + j) * getDeterminant(subVect);
        }
    }
    return solution;
}

std::vector<std::vector<double>> getInverse(const std::vector<std::vector<double>> vect) {
    if (getDeterminant(vect) == 0) {
        cout << "Determinant is 0" << endl;
    }

    double d = 1.0 / getDeterminant(vect);
    std::vector<std::vector<double>> solution(vect.size(), std::vector<double>(vect.size()));

    for (size_t i = 0; i < vect.size(); i++) {
        for (size_t j = 0; j < vect.size(); j++) {
            solution[i][j] = vect[i][j];
        }
    }

    solution = getTranspose(getCofactor(solution));

    for (size_t i = 0; i < vect.size(); i++) {
        for (size_t j = 0; j < vect.size(); j++) {
            solution[i][j] *= d;
        }
    }

    return solution;
}

void printMatrix(const std::vector<std::vector<double>> vect) {
    for (std::size_t i = 0; i < vect.size(); i++) {
        for (std::size_t j = 0; j < vect[0].size(); j++) {
            std::cout << std::setw(8) << vect[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void Matrix::Division(Matrix obj1, Matrix obj2)
{
    vector < vector<double>> temp1 = obj1.matrix;
    vector < vector<double>> temp2 = getInverse(obj2.matrix);
    vector<vector<double>> temp;
    if (obj1.size == obj2.size) {
        for (int i = 0; i < size; i++)
        {
            vector<double> myvector;
            for (int j = 0; j < size; j++)
            {
                myvector.push_back(temp1[i][j] * temp2[i][j]);
                cout << myvector[j] << '\t';
            }
            temp.push_back(myvector);
            cout << endl;
        }
    }
    else cout << "Matrixes have diffrenet size" << endl;
}
