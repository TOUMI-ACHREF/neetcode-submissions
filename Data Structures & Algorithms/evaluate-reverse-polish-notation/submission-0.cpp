class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> last_numbers;

        for(int i=0; i<tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" ||
               tokens[i] == "*" || tokens[i] == "/"){
                int a,b;
                b = last_numbers.top();
                last_numbers.pop();
                a = last_numbers.top();
                last_numbers.pop();

                if(tokens[i] == "+") last_numbers.push(a+b);
                else if(tokens[i] == "-") last_numbers.push(a-b);
                else if(tokens[i] == "*") last_numbers.push(a*b);
                else last_numbers.push(a/b);
            }else{
                last_numbers.push(stoi(tokens[i]));
            }            
        }
        return last_numbers.top();

    }
};
