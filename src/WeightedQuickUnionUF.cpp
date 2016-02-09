


/******************************************************************************
 *  Compilation:  javac WeightedQuickUnionUF.java
 *  Execution:  java WeightedQuickUnionUF < input.txt
 *  Dependencies: StdIn.java StdOut.java
 *
 *  Weighted quick-union (without path compression).
 *
 ******************************************************************************/

/**
 *  The <tt>WeightedQuickUnionUF</tt> class represents a <em>union-find data type</em>
 *  (also known as the <em>disjoint-sets data type</em>).
 *  It supports the <em>union</em> and <em>find</em> operations,
 *  along with a <em>connected</em> operation for determining whether
 *  two sites are in the same component and a <em>count</em> operation that
 *  returns the total number of components.
 *  <p>
 *  The union-find data type models connectivity among a set of <em>N</em>
 *  sites, named 0 through <em>N</em> &ndash; 1.
 *  The <em>is-connected-to</em> relation must be an
 *  <em>equivalence relation</em>:
 *  <ul>
 *  <p><li> <em>Reflexive</em>: <em>p</em> is connected to <em>p</em>.
 *  <p><li> <em>Symmetric</em>: If <em>p</em> is connected to <em>q</em>,
 *          then <em>q</em> is connected to <em>p</em>.
 *  <p><li> <em>Transitive</em>: If <em>p</em> is connected to <em>q</em>
 *          and <em>q</em> is connected to <em>r</em>, then
 *          <em>p</em> is connected to <em>r</em>.
 *  </ul>
 *  <p>
 *  An equivalence relation partitions the sites into
 *  two sites are in the same component if and only if they are connected.
 *  Both sites and components are identified with integers between 0 and
 *  <em>N</em> &ndash; 1.
 *  Initially, there are <em>N</em> components, with each site in its
 *  own component.  The <em>component identifier</em> of a component
 *  (also known as the <em>root</em>, <em>canonical element</em>, <em>leader</em>,
 *  or <em>set representative</em>) is one of the sites in the component:
 *  two sites have the same component identifier if and only if they are
 *  in the same component.
 *  <ul>
 *  <p><li><em>union</em>(<em>p</em>, <em>q</em>) adds a
 *         connection between the two sites <em>p</em> and <em>q</em>.
 *         If <em>p</em> and <em>q</em> are in different components,
 *         then it replaces
 *         these two components with a new component that is the union of
 *         the two.
 *  <p><li><em>find</em>(<em>p</em>) returns the component
 *         identifier of the component containing <em>p</em>.
 *  <p><li><em>connected</em>(<em>p</em>, <em>q</em>)
 *         returns true if both <em>p</em> and <em>q</em>
 *         are in the same component, and false otherwise.
 *  <p><li><em>count</em>() returns the number of components.
 *  </ul>
 *  <p>
 *  The component identifier of a component can change
 *  only when the component itself changes during a call to
 *  <em>union</em>&mdash;it cannot change during a call
 *  to <em>find</em>, <em>connected</em>, or <em>count</em>.
 *  <p>
 *  implementation uses weighted quick union by size (without path compression).
 *  Initializing a data structure with <em>N</em> sites takes linear time.
 *  Afterwards, the <em>union</em>, <em>find</em>, and <em>connected</em>
 *  operations  take logarithmic time (in the worst case) and the
 *  <em>count</em> operation takes constant time.
 *  For alternate implementations of the same API, see
 *  {@link UF}, {@link QuickFindUF}, and {@link QuickUnionUF}.
 *
 *  <p>
 *  For additional documentation, see <a href="http://algs4.cs.princeton.edu/15uf">Section 1.5</a> of
 *  <i>Algorithms, 4th Edition</i> by Robert Sedgewick and Kevin Wayne.
 *
 *  @author Robert Sedgewick
 *  @author Kevin Wayne
 */
#include"WeightedQuickUnionUF.h"
     WeightedQuickUnionUF::WeightedQuickUnionUF(int N) {
        count = N;
        WeightedQuickUnionUF::parent= new int [N];
          WeightedQuickUnionUF::size= new int [N];
        for (int i = 0; i < N; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    WeightedQuickUnionUF::WeightedQuickUnionUF() {
        WeightedQuickUnionUF::parent= new int [1000000];
          WeightedQuickUnionUF::size= new int [1000000];
        for (int i = 0; i < 1000000; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    /**
     * Returns the number of components.
     *
     * @return the number of components (between <tt>1</tt> and <tt>N</tt>)
     */
     int WeightedQuickUnionUF::countt() {
        return count;
    }

    /**
     * Returns the component identifier for the component containing site <tt>p</tt>.
     *
     * @param  p the integer representing one object
     * @return the component identifier for the component containing site <tt>p</tt>
     * @throws IndexOutOfBoundsException unless <tt>0 &le; p &lt; N</tt>
     */
     int WeightedQuickUnionUF::find(int p) {
        validate(p);
        while (p != parent[p])
            p = parent[p];
        return p;
    }

    // validate that p is a valid index
      void WeightedQuickUnionUF::validate(int p) {
       // int N = parent.size();
        //if (p < 0 || p >= N) {
          //  throw new IndexOutOfBoundsException("index " + p + " is not between 0 and " + (N-1));
        }


    /**
     * Returns true if the the two sites are in the same component.
     *
     * @param  p the integer representing one site
     * @param  q the integer representing the other site
     * @return <tt>true</tt> if the two sites <tt>p</tt> and <tt>q</tt> are in the same component;
     *         <tt>false</tt> otherwise
     * @throws IndexOutOfBoundsException unless
     *         both <tt>0 &le; p &lt; N</tt> and <tt>0 &le; q &lt; N</tt>
     */
     bool WeightedQuickUnionUF::connected(int p, int q) {
        return find(p) == find(q);
    }

    /**
     * Merges the component containing site <tt>p</tt> with the
     * the component containing site <tt>q</tt>.
     *
     * @param  p the integer representing one site
     * @param  q the integer representing the other site
     * @throws IndexOutOfBoundsException unless
     *         both <tt>0 &le; p &lt; N</tt> and <tt>0 &le; q &lt; N</tt>
     */
    void  WeightedQuickUnionUF::unionn(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;

        // make smaller root point to larger one
        if (size[rootP] < size[rootQ]) {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        else {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        count--;
    }


    /**
     * Reads in a sequence of pairs of integers (between 0 and N-1) from standard input,
     * where each integer represents some object;
     * if the sites are in different components, merge the two components
     * and print the pair to standard output.
     */


