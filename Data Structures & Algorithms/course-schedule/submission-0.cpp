class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>indegree(n);
        vector<int>adj[n];
        vector<int>ans;

        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        queue<int>q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();

            for(auto adjNode:adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode]==0){
                    q.push(adjNode);
                }
            }
        }

        return ans.size()==n;
    }
};
