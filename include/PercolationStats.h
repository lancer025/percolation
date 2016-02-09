#ifndef PECOLATIONSTATS_H
#define PECOLATIONSTATS_H
#include"Percolation.h"    // for cout and cin



class PercolationStats {
 private:
     double *recT;
     double res_mean;
     double res_stddev;
     int N;

     public:
     PercolationStats(int N, int T);

    double mean() ;                     // sample mean of percolation threshold
    double stddev();                    // sample standard deviation of percolation threshold
    double confidenceLo() ;             // low  endpoint of 95% confidence interval
    double confidenceHi()  ;
   }    ;

#endif // PECOLATIONSTATES_H
