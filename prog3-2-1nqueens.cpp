#include <iostream>

bool atk(std::pair<int, int> p1, std::pair<int, int> p2)
{
    bool row = (p1.first == p2.first);
    bool col = (p1.second == p2.second);
    bool diag = (abs(p1.first - p2.first) == abs(p1.second - p2.second));

    return row || col || diag;
}

bool check(std::pair<int, int> Q[], int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (atk(Q[i], Q[j])) {
                return false;
            }
        }
    }
    return true;
}

void fn(int n, std::pair<int, int> Q[], int size, std::pair<int, int> res[][100], int& bRes)
{
    if (size == n) {
        if (check(Q, size)) {
            for (int i = 0; i < size; i++) {
                res[bRes][i] = Q[i];
            }
            bRes++;
        }
        return;
    }
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            Q[size] = { r, c };
            fn(n, Q, size + 1, res, bRes);
        }
    }
}

int main()
{
    int n;
    std::cin >> n;

    std::pair<int, int> res[100][100];
    std::pair<int, int> Q[100];
    int bRes = 0;

    fn(n, Q, 0, res, bRes);

    int c = 0;
    for (int i = 0; i < bRes; i++) {
        c++;
        for (int j = 0; j < n; j++) {
            std::cout << " [ " << res[i][j].first << " , " << res[i][j].second << " ] ;";
        }
        std::cout << '\n';
    }

    std::cout << c << " RESENIJA";
    return 0;
}