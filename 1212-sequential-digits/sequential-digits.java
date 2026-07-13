class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> list = new ArrayList<>();
        int c1 = 0;
        int c2 = 0;
        int temp = low;

        while(temp > 0){
            c1++;
            temp /= 10;
        }

        temp = high;

        while(temp > 0){
            c2++;
            temp /= 10;
        }

        c2 = Math.min(c2, 9);
        
        for(int i = 0; i < c2 - c1 + 1; i++){
            int num = 0;
            int t = c1 + i;
            int j = 0;
            while(j < t){
                num = (num * 10) + j + 1;
                j++;
            }

            int c = 0;
            j = 0;
            while(j < t){
                c = (c * 10) + 1;
                j++;
            }

            while(num % 10 != 9){
                if(num >= low && num <= high){
                    list.add(num);
                }
                num += c;
            }
            if(num >= low && num <= high){
                list.add(num);
            }
        }

        return list;
    }
}