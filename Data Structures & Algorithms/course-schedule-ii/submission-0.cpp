class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int v=numCourses; 
        vector<int>adj[v];
        for(auto it:prerequisites){
            vector<int>x=it;
            adj[x[1]].push_back(x[0]);
        }
        vector<int>topological;
        vector<int>indegree(v,0);
        queue<int>q;

        for(int i=0;i<v;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(q.size()!=0){
            auto curr=q.front();
            q.pop();
            topological.push_back(curr);

            for(auto child:adj[curr]){
                indegree[child]--;
                if(indegree[child]==0){
                    q.push(child);
                }
            }

        }
        if(topological.size()==v){
            return topological;
        }
        return {};
    }
};