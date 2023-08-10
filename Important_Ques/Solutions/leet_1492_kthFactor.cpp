class Solution {
public:
    int kthFactor(int n, int k) {
    float root = sqrt(n);

    for (int i=1; i<root; i++) {
        if (n % i == 0 && --k == 0) 
            return i;
    }

    for (int i=root; i>0; i--) {
        if (n % i == 0 && --k == 0) 
            return n/i;
    }

    return -1;
    }
};