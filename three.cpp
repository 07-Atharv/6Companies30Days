class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> adj[numCourses];

        for( auto it : prerequisites ) {
            adj[it[0]].push_back( it[1] );
        }

        // setting the ind of all nodes
        int ind[numCourses];
        memset(ind,0,numCourses*sizeof(int));
        for( int i=0; i<numCourses; i++ ) {
            for( auto it : adj[i] ) {
                ind[it]++;
            }
        }

        // taking all the elements with ind 0 ind a seperate queue, as they all can be valid candiates for the starting point
        queue<int> q;
        for( int i=0; i<numCourses; i++ ) {
            if( ind[i] == 0 ) {
                q.push( i );
            }
        }

        // using topological sort to get a valid path 
        vector<int> topo;
        while( !q.empty() ) {
            int node = q.front();
            q.pop();
            topo.push_back( node );

            for( int it : adj[node] ) {
                ind[it]--;
                if( ind[it] == 0 ) q.push( it );
            }
        }

        cout << topo.size() << " " << endl;
        return topo.size() == numCourses;
    }
};