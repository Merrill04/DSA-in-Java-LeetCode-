class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea = 0;
        stack<int> s1;
        stack<int> s2;
        int next[heights.size()];
        int prev[heights.size()];
        //The below loop is for next smaller index.
        for(int i = heights.size() - 1; i >= 0; i--){
            if(s1.empty()){
                next[i] = -1;
                s1.push(i);
            }else if(heights[s1.top()] >= heights[i]){
                while(!s1.empty() && heights[s1.top()] >= heights[i]){
                    s1.pop();
                }

                if(s1.empty()){
                    next[i] = -1;
                }else{
                    next[i] = s1.top();
                }

                s1.push(i);
            }else{
                next[i] = s1.top();
                s1.push(i);
            }
        }
        //This calculates previous smaller elements index
        for(int i = 0; i < heights.size(); i++){
            if(s2.empty()){
                prev[i] = -1;
                s2.push(i);
            }else if(heights[i] <= heights[s2.top()]){
                while(!s2.empty() && heights[i] <= heights[s2.top()]){
                    s2.pop();
                }

                if(s2.empty()){
                    prev[i] = -1;
                }else{
                    prev[i] = s2.top();
                }

                s2.push(i);
            }else{
                prev[i] = s2.top();
                s2.push(i);
            }
        }
        
        for(int i = 0; i < heights.size(); i++){
            int r = -1;
            
            if(next[i] == -1){
                r = heights.size();
            }else{
                r = next[i];
            }

            int l = prev[i];
            int width = r - l - 1;
            int area = heights[i] * width;
            maxarea = max(maxarea, area);
        }

        return maxarea;
    }
};