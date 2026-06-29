class Solution {
    public int numOfStrings(String[] patterns, String word) {
        int count = 0;
        for(int i = 0; i < patterns.length; i++){
            for(int j = 0; j <= word.length() - patterns[i].length(); j++){
                if(patterns[i].equals(word.substring(j, j + patterns[i].length()))){
                    count++;
                    break;
                }
            }
        }

        return count;
    }
}