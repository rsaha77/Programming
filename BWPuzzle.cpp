#include <iostream>
#include <vector>

using namespace std;

bool validateLoc(vector<int>& v, int& pos, int& cnt) {
    if (cnt) {
        if (pos < (int) v.size()) {
            return (v[pos++] == cnt);
        } else {
            return false;
        }
    }
    return true;
}

bool validateRows(int& N, int& M, vector<vector<char>>& mat, vector<vector<int>>& rowChk) {
    for (int i=0; i<N; i++) {
        int cnt = 0, pos = 0;
        auto& rc = rowChk[i];
        for (int j = 0; j < M; j++) {
            if (mat[i][j] == 'B') {
                cnt++;
            } else {
                if (!validateLoc(rc, pos, cnt)) return false;
                cnt = 0;
            }
        }
        if (!validateLoc(rc, pos, cnt)) return false;
        if (pos < rc.size()) {
            return false;
        }
    }
    return true;
}

bool validateCols(int& N, int& M, vector<vector<char>>& mat, vector<vector<int>>& colChk){
    for (int i=0; i<M; i++) {
        int cnt = 0, pos = 0;
        auto& cc = colChk[i];
        for (int j=0; j<N; j++) {
            if (mat[j][i] == 'B') {
                cnt++;
            } else {
                if (!validateLoc(cc, pos, cnt)) return false;
                cnt = 0;
            }
        }
        if (!validateLoc(cc, pos, cnt)) return false;
        if (pos < cc.size()) return false;
    }
    return true;
}

bool validPuzzle(vector<vector<char>>& mat, vector<vector<int>>& rowChk, vector<vector <int>>& colChk) {
    int N = (int) mat.size(), M = (int) mat[0].size();
    return validateRows(N, M, mat, rowChk) & validateCols(N, M, mat, colChk);
}

bool getAns(vector<vector<char>>& mat, vector<vector<int>>& row, vector<vector <int>>& col) {
    if (validPuzzle(mat, row, col)) return true;
    else return false;
}


// Tests use to check solution
template <class T>
void printIntegerVector(vector <T> v) {
    int size = (int)v.size();
    cout << "[";
    for (int i = 0; i < size; i++) {
        if (i != 0) {
            cout << ", ";
        }
        cout << v[i];
    }
    cout << "]";
}

// Test your code
int test_case_number = 1;
template <class T>
void test(vector <T>& expected, vector <T>& output) {
    int expected_size = (int)expected.size();
    int output_size = (int)output.size();
    bool result = true;
    if (expected_size != output_size) {
        result = false;
    }
    if (result) {
        for (int i = 0; i < output_size; i++) {
            result &= (output[i] == expected[i]);
        }
    }
    const char* rightTick = u8"\u2713";
    const char* wrongTick = u8"\u2717";
    if (result) {
        cout << rightTick << " Test #" << test_case_number << "\n";
    }
    else {
        cout << wrongTick << " Test #" << test_case_number << ": Expected ";
        printIntegerVector(expected);
        cout << " Your output: ";
        printIntegerVector(output);
        cout << endl;
    }
    test_case_number++;
}

int main() {

    vector<vector<char>> matrix1 = {
            {'W','W','W','W'},
            {'B','W','W','W'},
            {'B','W','B','B'},
            {'W','W','B','W'},
            {'B','B','W','W'}
    };

    vector<vector<int>> rows1_1 = {{},{1},{1,2},{1},{2}};
    vector<vector<int>> columns1_1 = {{2,1},{1},{2},{1}};

    vector<vector<int>> rows1_2 = {{},{},{1},{1},{1,1}};
    vector<vector<int>> columns1_2 = {{2},{1},{2},{1}};

    vector<vector<int>> rows1_3 = {{},{1},{3},{1},{2}};
    vector<vector<int>> columns1_3 = {{3},{1},{2},{1}};

    vector<vector<char>> matrix2 = {
            {'W','W'},
            {'B','B'},
            {'B','B'},
            {'W','B'}
    };

    vector<vector<int>> rows2_1 = {{},{2},{2},{1}};
    vector<vector<int>> columns2_1 = {{1,1},{3}};

    vector<vector<int>> rows2_2 = {{},{2},{2},{1}};
    vector<vector<int>> columns2_2 = {{3},{3}};

    vector<vector<int>> rows2_3 = {{},{},{},{}};
    vector<vector<int>> columns2_3 = {{},{}};

    vector<vector<int>> rows2_4 = {{},{2},{2},{1}};
    vector<vector<int>> columns2_4 = {{2},{3}};

    vector<vector<int>> rows2_5 = {{},{2},{2},{1}};
    vector<vector<int>> columns2_5 = {{2,2},{3}};

    vector <bool> expectedAns {true, false, false, false, false, false, true, false};

    vector <bool> allAns;
    allAns.push_back(getAns(matrix1, rows1_1, columns1_1));
    allAns.push_back(getAns(matrix1, rows1_2, columns1_2));
    allAns.push_back(getAns(matrix1, rows1_3, columns1_3));
    allAns.push_back(getAns(matrix2, rows2_1, columns2_1));
    allAns.push_back(getAns(matrix2, rows2_2, columns2_2));
    allAns.push_back(getAns(matrix2, rows2_3, columns2_3));
    allAns.push_back(getAns(matrix2, rows2_4, columns2_4));
    allAns.push_back(getAns(matrix2, rows2_5, columns2_5));

    test(expectedAns, allAns);

    return 0;
}
