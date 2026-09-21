class Solution {
public:
    void dfs(int start, vector<vector<int>>& rooms, vector<bool>& visited){
        if(visited[start] == true){
            return;
        }

        visited[start] = true;

        for(int i = 0; i < rooms[start].size(); i++){
            if(visited[rooms[start][i]] == false){
                dfs(rooms[start][i], rooms, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);

        dfs(0, rooms, visited);

        for(int i = 0; i < rooms.size(); i++){
            if(visited[i] == false){
                return false;
            }
        }

        return true;
    }
};