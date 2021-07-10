#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {
        val = 0;
        children = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        children = vector<Node*>();
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

struct Query {
    int u;
    char c;
};

vector <int> ans;
string alp;
int preAns[1000010][26];

// Function doing the main task
void prepareTree(Node* root) {
    int father = root -> val;
    preAns[father][int(alp[father - 1] - 97)] = 1;
    for(auto child: root -> children) {
        prepareTree(child);
        int kid = child -> val;
        for(int i=0; i<26; i++) {
            preAns[father][i] += preAns[kid][i];
        }
    }
}

vector<int> countOfNodes(Node* root, vector<Query> queries, string s) {
    // Start here
    alp = s;
    ans.clear();
    memset(preAns, 0, sizeof(preAns));
    prepareTree(root);
    for (Query Q: queries) {
        ans.push_back(preAns[Q.u][int(Q.c - 97)]);
    }
    return ans;
}

// Tests use to check solution
void printIntegerVector(vector <int> array) {
    int size = array.size();
    cout << "[";
    for (int i = 0; i < size; i++) {
        if (i != 0) {
            cout << ", ";
        }
        cout << array[i];
    }
    cout << "]";
}

int test_case_number = 1;

void check(vector <int>& expected, vector <int>& output) {
    int expected_size = expected.size();
    int output_size = output.size();
    bool result = true;
    if (expected_size != output_size) {
        result = false;
    }
    for (int i = 0; i < min(expected_size, output_size); i++) {
        result &= (output[i] == expected[i]);
    }
    const char* rightTick = u8"\u2713";
    const char* wrongTick = u8"\u2717";
    if (result) {
        cout << rightTick << "Test #" << test_case_number << "\n";
    }
    else {
        cout << wrongTick << "Test #" << test_case_number << ": Expected ";
        printIntegerVector(expected);
        cout << " Your output: ";
        printIntegerVector(output);
        cout << endl;
    }
    test_case_number++;
}


int main() {

    // Testcase 1
    int n_1 = 3, q_1 = 1;
    string s_1 = "aba";
    Node *root_1 = new Node(1);
    root_1->children.push_back(new Node(2));
    root_1->children.push_back(new Node(3));
    vector<Query> queries_1{{1,'a'}};
    vector<int> output_1 = countOfNodes(root_1, queries_1, s_1);
    vector<int> expected_1 = {2};
    check(expected_1, output_1);

    // Testcase 2
    int n_2 = 7, q_2 = 3;
    string s_2 = "abaacab";
    Node *root_2 = new Node(1);
    root_2->children.push_back(new Node(2));
    root_2->children.push_back(new Node(3));
    root_2->children.push_back(new Node(7));
    root_2->children[0]->children.push_back(new Node(4));
    root_2->children[0]->children.push_back(new Node(5));
    root_2->children[1]->children.push_back(new Node(6));
    vector<Query> queries_2{{1,'a'}, {4, 'a'}, {3, 'a'}};
    vector<int> output_2 = countOfNodes(root_2, queries_2, s_2);
    vector<int> expected_2 = {4, 1, 2};
    check(expected_2, output_2);

}