 #include <time.h>       /* time */
#include <stdlib.h>
#include<math.h>
#include<iostream>
#include"PercolationStats.h"
using namespace std;
 /* srand, rand */


     // high endpoint of 95% confidence interval

    // perform T independent computational experiments on an N-by-N grid
    PercolationStats::PercolationStats(int N, int T){
        PercolationStats::N = N;
        PercolationStats::recT = new double [T];


        int times = 0;
        if (N <= 0){
           // throw new IllegalArgumentException();
        }
        if (T <= 0){
            //throw new IllegalArgumentException();
        }
        while (times < T){
            Percolation percolation(N);
              /*bool arrOpen[N][N];
              int i,j;
              for(i=0;i<N;i++){
              for(j=0;j<N;j++){
              arrOpen[i][j]=false;
              }
             }*/
            int count = 0;
            while(true){
                count++;

                    int x = rand() % N;
                    int y = rand() % N;
                     cout << "  N ,  x , y =" << N << " " << x << " , " << y <<"\n";

                    percolation.open(x, y);

                if (percolation.percolates()){

                    recT[times] = (double)count / ((double)N * (double)N);
                    break;
                }

                }
               times++;
            }


        double sum=0;
        int i;
        for(i=0;i<T;i++){
            sum=sum+recT[i];

        }



        PercolationStats::res_mean = sum/T;
sum=0;
        for(i=0;i<T;i++){
            sum=sum+((recT[i]-PercolationStats::res_mean )*(recT[i]-PercolationStats::res_mean ));

        }


       PercolationStats::res_stddev = sqrt(sum/(T-1));
    }

    // sample mean of percolation threshold
     double PercolationStats::mean(){
        return PercolationStats::res_mean;
    }


    // sample standard deviation of percolation threshold
     double PercolationStats::stddev(){
        return PercolationStats::res_stddev;
    }

    // returns lower bound of the 95% confidence interval
     double PercolationStats::confidenceLo(){
        return PercolationStats::res_mean - 1.96*PercolationStats::res_stddev / sqrt(N);
    }

    // returns upper bound of the 95% confidence interval
     double PercolationStats::confidenceHi(){
        return PercolationStats::res_mean + 1.96*PercolationStats::res_stddev / sqrt(N);
    }

    // test client, described below


