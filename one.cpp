class Solution {
public:
 int eval_EQN( int n1, int n2, char op ) {
        if( op == '+' ) {
            // poping two elements from stack and performing addition, and then pushing it back into stack
            return n2 + n1;
        }
        else if( op == '-' ) {
            // poping two elements from stack and performing subtraction, and then pushing it back into stack
            return n2 - n1;
        }
        else if( op == '*' ) {
            // poping two elements from stack and performing multiplication, and then pushing it back into stack
            return n2 * n1 ;
        }
        else {
            // poping two elements from stack and performing division, and then pushing it back into stack
            return n2 / n1 ;
        }
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        
        for( auto& it : tokens ) {
            if( it.size() == 1 && it[0] < 48 ) {
                // getting the top two elements from the stack
                int n1 = s.top();
                s.pop();

                int n2 = s.top();
                s.pop();
                
                // it's a non-number, check which operator it is 
                s.push( eval_EQN( n1, n2, it.at(0)) );
            }
            else {
                s.push( stoi( it ) );
                // the character is a number, adding it to stack of operands
            }
        }

        // at the end, there would be only one value in stack which would be the result, returning the element of stack 
        return s.top();
    }
};