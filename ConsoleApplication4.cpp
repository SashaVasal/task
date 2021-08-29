#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

void build_matrix(int d) {
    vector<vector<int>> m = vector<vector<int>>(d);

}

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
private:
    vector<vector<int>> m;
    int size = 0;
};

int main() {
    mymatrix *m = new mymatrix(12);
    m->show_matrix();
    return 0;
}