class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for (auto task : tasks) {
            counts[task]++;
        }

        priority_queue<int> pq;
        for (auto it : counts) {
            pq.push(it.second);
        }

        int intervals = 0;
        while (!pq.empty()) {
            vector<int> temp;
            int i = 0;
            while (i <= n) {

                if (!pq.empty()) {
                    if (pq.top() > 1) {
                        temp.push_back(pq.top() - 1);
                    }
                    pq.pop();
                }

                intervals++;
                
                if (pq.empty() && temp.empty()) {
                    break;
                }

                i++;
            }
            for (auto t : temp) {
                pq.push(t);
            }
        }

        return intervals;
    }
};