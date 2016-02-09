#include <iostream>
#include"PercolationStats.h"
#include "Percolation.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

      int N ;
        int T ;
        cin >> N;
        cin >> T;
        PercolationStats percolationStats(N, T);
       cout << "mean = " <<  percolationStats.mean();
        cout << "stddev = "  << percolationStats.stddev();
        cout << "95% confidence interval " <<  percolationStats.confidenceLo() << ", " << percolationStats.confidenceHi();
    return 0;
}
