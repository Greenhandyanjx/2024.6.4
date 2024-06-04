#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>res;
        for (int i = 0; i < tokens.size(); i++) {
            if (!res.empty() && (tokens[i].compare("+") == 0 || tokens[i].compare("-") == 0 || tokens[i].compare("*") == 0 || tokens[i].compare("/") == 0)) {
                int n1 = res.top(); res.pop();
                int n2 = res.top(); res.pop();
                switch (tokens[i][0]) {
                case '+':res.push(n1 + n2); break;
                case '-':res.push(n2 - n1); break;
                case '*':res.push(n1 * n2); break;
                case '/':res.push(n2 / n1); break;
                }
            }
            else {
                res.push(stoi(tokens[i]));
            }
        }
        return res.top();
    }
};
int main() {
    vector<string> v({ "4","13","5","/","+" });
    evalRPN(v);
}
//string removeDuplicates(string s) {
//    stack<char> res;
//    for (int i = 0; i < s.length(); i++) {
//        if (!res.empty() && s[i] == res.top()) {
//            res.pop();
//        }
//        else
//            res.push(s[i]);
//    }
//    string temp;
//    int n = res.size();
//    for (int i = 0; i < n; i++) {
//        temp += res.top();
//        res.pop();
//    }
//    reverse(temp.begin(), temp.end());
//    return temp;
//}
//class Solution {
//public:
//    bool isValid(string s) {
//        stack<char>res;
//        if (s.length() % 2 != 0)return false;
//        for (int i = 0; i < s.length(); i++) {
//            if (s[i] == '(')res.push(')');
//            else if (s[i] == '[')res.push(']');
//            else if (s[i] == '{')res.push('}');
//            else if (res.empty() || s[i] != res.top())return false;
//            else {
//                res.pop();
//            }
//        }
//        if (res.empty())
//            return true;
//        return false;
//    }
//};
//int main() {
//    isValid("((");
//	return 0;
//}
//class MyStack {
//public:
//    queue<int> q;
//    int num=0;
//    MyStack() {
//
//    }
//
//    void push(int x) {
//        q.push(x);
//        num++;
//    }
//
//    int pop() {
//        int temp = num;
//        while (--temp) {
//            q.push(q.front());
//            q.pop();
//        }
//        int res = q.front();
//        q.pop();
//        num--;
//        return res;
//    }
//
//    int top() {
//        return q.back();
//    }
//
//    bool empty() {
//        return q.empty();
//    }
//};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */