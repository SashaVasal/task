#include <fstream>
#include <vector>
#include <iostream>
using namespace std;


class mymatrix {
public:
    mymatrix(int d) {
        size = d+1;
        m = vector<vector<int>>(size, vector<int>(size));

        for (int i = 0; i < size; i++) {
            m[i][i] = 1;
        }

        for (int i = 1; i < size; i++) {
            for (int j = 1; j < size; j++) {
                m[i][j] = m[i][j - 1] * i + m[i - 1][j - 1];
            }
        }
    }

    void show_matrix() {
        for (int i = size-1; i >= 0; i--) {
            for (int j = size - 1; j >= 0; j--) {
                cout << m[i][j] << " ";
            }
            cout << "\n";
        }
    }
    
    void show_pattern() {
        for (int i = 0; i < size; i++) {
            cout << "b_" << 6 - i << " = ";
            for (int j = 0; j < size; j++) {
                if (m[i][j] != 0) {
                    if (m[i][j] != 1 || j == 6) {
                        cout << m[i][j] << " ";
                    }
                    if (j != 6) {
                        cout << "a_" << 6 - j;
                       if (j != 0) {
                           cout << " + ";
                       }
                    }                 
                }   
            }

            cout << "\n";
        }
    }
private:
    vector<vector<int>> m;
    int size = 0;
};

int main() {
    mymatrix *m = new mymatrix(6);
    m->show_pattern();
    return 0;
}
