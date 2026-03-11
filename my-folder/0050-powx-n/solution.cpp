class Solution {
    double Pow(double x,long long n)
    {
        if(n==0 ||x==1) return 1;
        double half = Pow(x,n/2);
        if(n%2!=0) return x*half* half;
        else return half* half;
    }
public:
    double myPow(double x, int n) {
        long long  nn = n;
        if(nn<0) {
            nn = -nn;
            x = 1/x;
        }
        return Pow(x,nn);
    }
};
