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

        for (int i = size - 2; i >= 0 ; i--) {
            for (int j = size - 2; j >= 0; j--) {
                m[i][j] = m[i][j + 1] * (size-i-1) + m[i + 1][j + 1];
            }
        }
    }

    void show_matrix() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                cout << m[i][j] << " ";
            }
            cout << "\n";
        }
    }
    
    vector<vector<int>> get_matrix() {
        return m;
    }
    
private:
    vector<vector<int>> m;
    int size = 0;
};

int main() {
    mymatrix *m = new mymatrix(6);
    m->show_matrix();
    return 0;
}
