class Solution {
    public int lengthOfLongestSubstring(String s) {
        int maxlen = 0;
        int j = 0;
        HashMap<Character, Integer> map = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (map.containsKey(c)) {
                j = Math.max(j, map.get(c) + 1);
            }

            map.put(c, i); 
            maxlen = Math.max(maxlen, i - j + 1);
        }

        return maxlen;
    }
}
