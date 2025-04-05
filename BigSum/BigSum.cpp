#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

// 去掉字符串前面的多余零
string removeLeadingZeros(const string &s) {
    int i = 0;
    while (i < s.size() - 1 && s[i] == '0') {
        i++;
    }
    return s.substr(i);
}

// 大数加法：返回 a + b，输入为非负大数字符串
string addBig(const string &a, const string &b) {
    int i = a.size() - 1, j = b.size() - 1;
    int carry = 0;
    string res;
    while (i >= 0 || j >= 0 || carry) {
        int x = (i >= 0 ? a[i] - '0' : 0);
        int y = (j >= 0 ? b[j] - '0' : 0);
        int sum = x + y + carry;
        carry = sum / 10;
        res.push_back('0' + (sum % 10));
        i--; j--;
    }
    reverse(res.begin(), res.end());
    return removeLeadingZeros(res);
}

// 大数减法：计算 a - b（要求 a >= b），返回差值
string subtractBig(const string &a, const string &b) {
    // 假设 a>=b，否则可先比较大小
    int i = a.size() - 1, j = b.size() - 1;
    int borrow = 0;
    string res;
    while (i >= 0) {
        int x = a[i] - '0';
        int y = (j >= 0 ? b[j] - '0' : 0);
        int diff = x - y - borrow;
        if(diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        res.push_back('0' + diff);
        i--; j--;
    }
    reverse(res.begin(), res.end());
    return removeLeadingZeros(res);
}

// 大数乘法：返回 a * b，采用 O(n*m) 的模拟乘法
string multiplyBig(const string &a, const string &b) {
    int n = a.size(), m = b.size();
    vector<int> result(n + m, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (a[i]-'0') * (b[j]-'0');
            int sum = result[i + j + 1] + mul;
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    // 转换为字符串
    string res;
    for (int num : result)
        res.push_back('0' + num);
    return removeLeadingZeros(res);
}

// 比较两个大数字符串（非负），返回：
//  1: a > b; 0: a == b; -1: a < b
int compareBig(const string &a, const string &b) {
    string A = removeLeadingZeros(a);
    string B = removeLeadingZeros(b);
    if (A.size() > B.size()) return 1;
    if (A.size() < B.size()) return -1;
    if (A == B) return 0;
    return (A > B) ? 1 : -1;
}

// 大数除法：计算 a / b，返回 pair<商, 余数>
// 注意：b 必须不为 "0"
pair<string, string> divideBig(const string &a, const string &b) {
    assert(b != "0");
    string dividend = removeLeadingZeros(a);
    string divisor = removeLeadingZeros(b);
    if (compareBig(dividend, divisor) < 0)
        return {"0", dividend}; // 商为 0，余数为 dividend

    string quotient;
    string remainder;
    for (int i = 0; i < dividend.size(); i++) {
        // 将当前位加入余数
        remainder.push_back(dividend[i]);
        remainder = removeLeadingZeros(remainder);
        // 计算当前余数能除以 divisor 的次数
        int count = 0;
        while (compareBig(remainder, divisor) >= 0) {
            remainder = subtractBig(remainder, divisor);
            count++;
        }
        quotient.push_back('0' + count);
    }
    quotient = removeLeadingZeros(quotient);
    remainder = removeLeadingZeros(remainder);
    return {quotient, remainder};
}

// 测试
int main() {
    string a = "123456789123456789123456789";
    string b = "987654321987654321987654321";

    cout << "加法: " << a << " + " << b << " = " << addBig(a, b) << endl;
    // 假设 b < a 时的减法测试
    cout << "减法: " << b << " - " << a << " = " << subtractBig(b, a) << endl;
    cout << "乘法: " << a << " * " << b << " = " << multiplyBig(a, b) << endl;
    
    string dividend = "100000000000000000000";
    string divisor = "123456789";
    auto res = divideBig(dividend, divisor);
    cout << "除法: " << dividend << " / " << divisor << " = " << res.first 
         << " 余 " << res.second << endl;
         
    return 0;
}
