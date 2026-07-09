class Solution {
    public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
        boolean[] answer = new boolean[queries.length];

        for(int i = 0; i < queries.length; i++){
            if(queries[i][0] <= queries[i][1]){
                boolean flag = true;
                for(int j = queries[i][0]; j < queries[i][1]; j++){
                    if(Math.abs(nums[j+1] - nums[j]) > maxDiff){
                        flag = false;
                        break;
                    }
                }
                answer[i] = flag;
            }else{
                boolean flag = true;
                for(int j = queries[i][1]; j < queries[i][0]; j++){
                    if(Math.abs(nums[j+1] - nums[j]) > maxDiff){
                        flag = false;
                        break;
                    }
                }
                answer[i] = flag;
            }
        }

        return answer;
    }
}