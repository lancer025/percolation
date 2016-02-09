#include <iostream>

#include"Percolation.h"

    Percolation::Percolation(int size){
        Percolation::size = size;

        int i ;
        int j;

        grid = new int *[size];
for (int count = 0; count < size; count++)
{
    grid[count] = new int[size];
}
        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                               // g[i][j] = new Site((j + 1) + (i * size));

            grid[i][j]=0;
            }
        }

        // unionFinder size is grid size (size * size) plus 3
        // to make room for "virtual" top and bottom sites
         WeightedQuickUnionUF percUF(size * size);
                                           std::cout << "Percolation successful\n";



    }

     void Percolation::open(int i, int j) {
                     std::cout << "open called";

 if (i < 0 || i >= size) {
     std::cout << "exception";
     return;
           // throw new IndexOutOfBoundsException();
        } else if (j < 0 || j >=size) {
            std::cout << "exception";
     return;
            //throw new IndexOutOfBoundsException();
        }
        // input is 1 - size, array is zero index, so shift


        int s = grid[i][j];
        if (s==0) {
            grid[i][j] = 1;



            // left is j - 1
            if (j - 1 > -1) {
                if (grid[i][j-1] == 1) {
                    ///System.out.println("UNION:" + s.position + " " + left.position);
                    int spos=(i*size)+j;
                    int lpos=(i*size)+j-1;
                    Percolation::percUF.unionn(spos, lpos);
                }
            }

            // right is j + 1
            if (j + 1 < size) {

                if (grid[i][j+ 1] == 1) {
                    ///System.out.println("UNION:" + s.position + " " + right.position);
                     int spos=(i*size)+j;
                    int lpos=(i*size)+j+1;
                    percUF.unionn(spos, lpos);

                }
            }

            // top is i - 1
            if (i - 1 > -1) {

                if ( grid[i - 1][j] == 1) {
                    ///System.out.println("UNION:" + s.position + " " + top.position);
                     int spos=((i-1)*size)+j;
                    int lpos=((i-1)*size)+j;
                    percUF.unionn(spos, lpos);
                }
            }

            // bottom is i + 1
            if (i + 1 < size) {
                if ( grid[i +1][j] == 1) {
                    ///System.out.println("UNION:" + s.position + " " + top.position);
                     int spos=((i+1)*size)+j;
                    int lpos=((i+1)*size)+j;
                    percUF.unionn(spos, lpos);
                }
            }

            // if s is in TOP or BOTTOM row, ALSO connect to respective top/bottom virt
        std::cout << "open successful \n";

        }
       else{ std::cout << "already open  successful \n";
       }

    }

     bool Percolation::isOpen(int i, int j) {
if (i < 0 || i >= size) {
std::cout << "exception";
                        std::cout << "isOpen \n";

     return false;        } else if (j < 0 || j >=size) {
            std::cout << "exception";
                        std::cout << "isOpen \n";

     return false;
        }
        // input is 1 - size, array is zero index, so shift
                        std::cout << "isOpen \n";


         if( grid[i][j] == 1) return true;
         else
        return false;
    }

     bool Percolation::isFull(int i, int j) {
         int k;
if (i < 0 || i >= size) {
std::cout << "exception";
     return false;        } else if (j < 0 || j >=size) {
std::cout << "exception";
     return false;
        }


      for(k=0;k<size;k++){
      if(grid[0][k] == 1){
           int spos=((i)*size)+j;
                    int lpos=k;
        if( percUF.connected(spos, lpos)){
                          std::cout << "isfull successful\n";

        return true;
        }

      }

      }
              std::cout << "isfull successful\n";

      return false;

    }

     bool Percolation::percolates() {
         int i,j;

        for(i=0;i<size;i++){
        if(grid[0][i] == 1){

        for(j=0;j<size;j++){

        if(grid[size-1][j] == 1 ){
        int spos = i;
        int lpos = (size-1)*(size) + j;
        if(percUF.connected(spos,lpos) )
        std::cout << "percolates successful true\n";

        return true;
        }
        }
        }


        }
        std::cout << "percolates successful false \n";

        return false;
    }





    //
    // priv
    //





