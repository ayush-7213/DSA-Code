class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n1 = num1.size(), n2 = num2.size();
        vector<int> prod(n1 + n2, 0);

        // Reverse for easier calculation
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                prod[i + j] += (num1[i] - '0') * (num2[j] - '0');
                prod[i + j + 1] += prod[i + j] / 10;
                prod[i + j] %= 10;
            }
        }

        // Convert to string
        while (prod.size() > 1 && prod.back() == 0)
            prod.pop_back();

        string result;
        for (int d : prod) result.push_back('0' + d);

        reverse(result.begin(), result.end());
        return result;
    }
};
