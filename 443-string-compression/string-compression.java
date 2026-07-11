class Solution {
    public int compress(char[] chars) {
        int length = 0;
        int pos = 0;
        int start = 0;
        int next = 1;
        int count = 1;
        while(next < chars.length){
            if(chars[start] == chars[next]){
                count++;
                next++;
            }else{
                if(count == 1){
                    chars[pos] = chars[start];
                    pos++;
                    length++;
                }else if(count > 9){
                    chars[pos] = chars[start];
                    pos++;
                    length++;
                    List<Integer> list = new ArrayList<>();
                    while(count > 0){
                        list.add(count % 10);
                        count /= 10;
                    }

                    for(int i = list.size() - 1; i >= 0; i--){
                        chars[pos] = (char)(list.get(i) + '0');
                        pos++;
                        length++;
                    }
                }else{
                    chars[pos] = chars[start];
                    pos++;
                    length++;
                    chars[pos] = (char)(count + '0');
                    pos++;
                    length++;
                }
                count = 1;
                start = next;
                next++;
            }
        }

        if(count == 1){
            chars[pos] = chars[start];
            pos++;
            length++;
        }else if(count > 9){
            chars[pos] = chars[start];
            pos++;
            length++;
            List<Integer> list = new ArrayList<>();
            while(count > 0){
                list.add(count % 10);
                count /= 10;
            }

            for(int i = list.size() - 1; i >= 0; i--){
                chars[pos] = (char)(list.get(i) + '0');
                pos++;
                length++;
            }
        }else{
            chars[pos] = chars[start];
            pos++;
            length++;
            chars[pos] = (char)(count + '0');
            pos++;
            length++;
        }
        
        return length;
    }
}