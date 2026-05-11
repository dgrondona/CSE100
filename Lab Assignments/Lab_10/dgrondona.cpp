#include <iostream>
#include <vector>
#include <string>

using namespace std;

// recursive function to print optimal parenthesization
void printOptimal(std::vector<std::vector<int>>& s, int i, int j) {

    // single matrix
    if (i == j) {
        std::cout << "A" << i;
        return;
    }

    std::cout << "(";

    int k = s[i][j];

    printOptimal(s, i, k);
    printOptimal(s, k + 1, j);

    std::cout << ")";
}

int main() {

    int n;
    std::cin >> n;

    // dimensions array
    std::vector<int> p(n + 1);

    for (int i = 0; i <= n; i++) {
        std::cin >> p[i];
    }

    // m[i][j] = minimum cost
    std::vector<std::vector<int>> m(n, std::vector<int>(n, 0));

    // s[i][j] = split point
    std::vector<std::vector<int>> s(n, std::vector<int>(n, 0));

    int INF = 1000000000;

    // chain length
    for (int length = 2; length <= n; length++) {

        for (int i = 0; i <= n - length; i++) {

            int j = i + length - 1;

            m[i][j] = INF;

            // try every split
            for (int k = i; k < j; k++) {

                int cost =
                    m[i][k]
                    + m[k + 1][j]
                    + p[i] * p[k + 1] * p[j + 1];

                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    // minimum cost
    std::cout << m[0][n - 1] << endl;

    // optimal parenthesization
    printOptimal(s, 0, n - 1);
    std::cout << endl;

    return 0;
}