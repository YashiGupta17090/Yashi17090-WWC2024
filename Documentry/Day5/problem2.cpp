//valid parenthesis
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> matching_parentheses = {
        {')', '('}, 
        {']', '['}, 
        {'}', '{'}
    };
    
    for (char ch : s) {
        if (matching_parentheses.count(ch)) {
            // Check if the top of the stack matches the corresponding opening parenthesis
            if (st.empty() || st.top() != matching_parentheses[ch]) {
                return false;  // Mismatch or stack is empty
            }
            st.pop();  // Pop the matching opening parenthesis
        } else {
            // Push opening parenthesis onto the stack
            st.push(ch);
        }
    }
    
    // If the stack is empty, all parentheses are matched
    return st.empty();
}

int main() {
    string s = "{[()]}";
    
    if (isValid(s)) {
        cout << "The parentheses are valid." << endl;
    } else {
        cout << "The parentheses are not valid." << endl;
    }
    
    return 0;
}
