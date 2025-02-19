int maxArea(vector<int>& v) {
    int max = 1;
    if (v.size() == 2) {
        return min(v[0], v[1]);
    }
    for (int i = 0; i < v.size(); i++) {
        int c = 0;
        for (int j = i + 1; j < v.size(); j++) {
            int tmp = (j - i) * min(v[i], v[j]);
            if (c < tmp) {
                c = tmp;
            }
        }
        if (c > max) {
            max = c;
        }
    }
    return max;
}
