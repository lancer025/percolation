#ifndef PERCOLATION_H
#define PERCOLATION_H
#include "WeightedQuickUnionUF.h"    // for cout and cin




class Percolation                   // begin declaration of the class
{
  public:                    // begin public section
     Percolation(int N) ;              // create N-by-N grid, with all sites blocked
    void open(int i, int j);          // open site (row i, column j) if it is not open already
    bool isOpen(int i, int j);     // is site (row i, column j) open?
    bool isFull(int i, int j) ;    // is site (row i, column j) full?
    bool percolates();
  // does the system percolate?
 private:
 int size;                  // begin private section
    int **grid;
             WeightedQuickUnionUF percUF;

};


#endif // PERCOLATION_H
