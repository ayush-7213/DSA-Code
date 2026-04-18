class Solution {
public:
    int mirrorDistance(int n) {
        long long rev = 0;
        for(int i=n; i; i/=10){
            rev = 10*rev + i%10;
        }
        rev -= n;
        return rev >=0 ? rev : -rev;
    }
};