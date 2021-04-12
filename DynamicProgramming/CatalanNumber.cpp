// { Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


 // } Driver Code Ends
//User function template for C++

// n : given integer value
class Solution{
  public:
  cpp_int binomialCoeff(cpp_int n,cpp_int k)
    {
        cpp_int res = 1;
     
        // Since C(n, k) = C(n, n-k)
        if (k > n - k)
            k = n - k;
     
        // Calculate value of [n*(n-1)*---*(n-k+1)] /
        // [k*(k-1)*---*1]
        for (int i = 0; i < k; ++i) {
            res *= (n - i);
            res /= (i + 1);
        }
     
        return res;
    }
     
    // A Binomial coefficient based function to find nth catalan
    // number in O(n) time
    cpp_int findCatalan(int n)
    {
        // Calculate value of 2nCn
        cpp_int c = binomialCoeff(2 * n, n);
     
        // return 2nCn/(n+1)
        return c / (n + 1);
    }
    
};

// { Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}  // } Driver Code Ends