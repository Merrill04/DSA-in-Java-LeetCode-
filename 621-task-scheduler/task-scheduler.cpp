class Solution {
    struct Compare {
        bool operator()(const pair<char, int>& a,
                    const pair<char, int>& b) {
            return a.second < b.second;
        }
    };

public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        map<char, pair<char, int>> m;
        

        for(int i = 0; i < tasks.size(); i++){
            if(m.find(tasks[i]) != m.end()){
                m[tasks[i]].second += 1;
            }else{
                pair<char, int> p = {tasks[i], 1};
                m[tasks[i]] = p;
            }
        }

        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;

        for(auto &i : m){
            pq.push(i.second);
        }

        while(!pq.empty()){
            int t = n + 1;
            vector<pair<char, int>> temp;
            while(!pq.empty() && t > 0){
                pair<char, int> p = pq.top();
                pq.pop();
                p.second--;

                if (p.second != 0){
                    temp.push_back(p);
                }
                ans++;
                t--;
            }

            for (auto &p : temp) {
                pq.push(p);
            }

            if (!pq.empty()) {
                ans += t;
            }
        }

        return ans;
    }
};