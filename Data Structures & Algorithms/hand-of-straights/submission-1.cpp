class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> freqMap;

        if(n%groupSize!=0){
            return false;
        }

        for(auto it:hand){
            freqMap[it]++;
        }

        for(auto it1:freqMap){
            pq.push(it1.first);
        }

        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            int count = freqMap[temp];
            if(count==0){
                continue;
            }

            for(int i=0;i<groupSize;i++){
                if(freqMap[temp+i]<count){
                    return false;
                }
                freqMap[temp+i]-=count;

                if(freqMap[temp+i]==0){
                     freqMap.erase(temp + i); 
                }
            }
        }

        return true;
    }
};
