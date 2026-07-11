class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean flag = true;
        HashMap<Character, Integer> map1 = new HashMap<>();
        HashMap<Character, Integer> map2 = new HashMap<>();

        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                if(board[i][j] != '.'){
                    if(map1.containsKey(board[i][j]) && map1.get(board[i][j]) == i){
                        return false;
                    }else{
                        map1.put(board[i][j], i);
                    }
                }
            }
        }

        for(int i = 0; i < board[0].length; i++){
            for(int j = 0; j < board.length; j++){
                if(board[j][i] != '.'){
                    if(map2.containsKey(board[j][i]) && map2.get(board[j][i]) == i){
                        return false;
                    }else{
                        map2.put(board[j][i], i);
                    }
                }
            }
        }

        for(int i = 0; i < board.length; i += 3){
            for(int j = 0; j < board[0].length; j += 3){
                HashMap<Character, Integer> map = new HashMap<>();
                for(int k = i; k < i + 3; k++){
                    for(int l = j; l < j + 3; l++){
                        if(board[k][l] != '.'){
                            if(map.containsKey(board[k][l])){
                                return false;
                            }else{
                                map.put(board[k][l], k);
                            }
                        }
                    }
                }
            }
        }

        return flag;
    }
}