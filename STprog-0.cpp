#include <iostream>
#include <vector>

using namespace std;

void build(vector<int>& niz, vector<int> &STree, int begin, int end, int pero)
{
    if (begin == end) {
        STree[pero] = niz[begin];
        return;
    }
    int m = (begin + end) / 2;
    build(niz, STree, begin, m, 2 * pero + 1);
    // build(niz ,STree, begin, m, 2*pero);
    build(niz, STree, m + 1, end, 2 * pero + 2);
    STree[pero] = STree[2 * pero + 1] + STree[2 * pero + 2];
}

void update(vector<int>& STree, int begin, int end, int pero, int IN, int val)   //IN-ideks
{
    if (begin == end) {
        STree[pero] = val;
        return;
    }

    int m = (begin + end) / 2;

    if (IN >= begin && IN <= m) {
        update(STree, begin, m, 2 * pero + 1, IN, val);
    }
    else {
        update(STree, m + 1, end, 2 * pero + 2, IN, val);
    }
    STree[pero] = STree[2 * pero + 1] + STree[2 * pero + 2];
    //STree[pero] = STree[2 * pero ] + STree[2 * pero +1];

}

int query(vector<int>& STree, int begin, int end, int pero, int x1, int x2)
{
    if (x1 > end || x2 < begin) {
        return 0;
    }
    if (x1 <= begin && end <= x2) {
        return STree[pero];
    }
    int m = (begin + end) / 2;
    int X = query(STree, begin, m, 2 * pero + 1, x1, x2);
    int Y = query(STree, m + 1, end, 2 * pero + 2, x1, x2);
    return X + Y;
}

int main()
{
    int N;
    std::cout << "Vo prviot red vnesi N (broj na elementi na nizata), a vo slednite N redovi vnesi gi elementite \n";
    std::cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        std::cin >> vec[i];
    }
    vector<int> STree(4 * N);
    build(vec, STree, 0, N - 1, 0);

    std::cout <<"PRED UPDATE: " << query(STree, 0, N - 1, 0, 2, 5) << '\n';
    update(STree, 0, N - 1, 0, 3, 5);

    std::cout <<"POSLE UPDATE: " << query(STree, 0, N - 1, 0, 2, 5);
}