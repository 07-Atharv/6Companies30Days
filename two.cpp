class Solution {
public:
void help( int i, int k, int n, vector<int> &subSet, vector<vector<int>> &ans ) {
        // base conditions to stop the recurssion
        if( n==0 && k == 0 )  {
            ans.push_back( subSet );
            return;
        }

        if( k == 0 ) {
            // checking if sum is the same required sum 
            return;
        }

        for( int j=i; j<=9; j++ ) {
            subSet.push_back(j);

            help( j+1, k-1, n-j, subSet, ans );

            // backtracking
            subSet.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        // creating two vectors to store the subset and store the vector of possible combinations
        vector<int> subSet;     // stores the possible subset of given combinations
        vector<vector<int>> ans;    // stores the vector of all the possible combinations whose summation would be equal to given summation

        // calling the helper function
        help( 1, k, n, subSet, ans );

        return ans;
    }
};