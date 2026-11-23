class ProductOfNumbers {
public:
    vector<int> v;

    ProductOfNumbers() {

    }
    
    void add(int num) {
        v.push_back(num);
    }
    
    int getProduct(int k) {
        int res = 1;

        for(int i = 0; i < k; i++){
            res *= v[v.size() - 1 - i];
        }

        return res;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */