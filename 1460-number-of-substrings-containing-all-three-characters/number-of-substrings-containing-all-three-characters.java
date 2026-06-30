class Solution {
    public int numberOfSubstrings(String s) {
        if(s.length() < 3){
            return 0;
        }

        int answer = 0;

        int left = 0;
        int right = 0;

        int counta = 0;
        int countb = 0;
        int countc = 0;

        while(right < s.length()){

            if(s.charAt(right) == 'a'){
                counta++;
            }else if(s.charAt(right) == 'b'){
                countb++;
            }else if(s.charAt(right) == 'c'){
                countc++;
            }
            
            while(counta > 0 && countb > 0 && countc > 0){
                answer += s.length() - right;
                if(s.charAt(left) == 'a'){
                    counta--;
                }else if(s.charAt(left) == 'b'){
                    countb--;
                }else if(s.charAt(left) == 'c'){
                    countc--;
                }
                left++;
            }

            right++;
        }

        return answer;
    }
}