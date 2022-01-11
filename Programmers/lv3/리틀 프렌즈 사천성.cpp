#include <string>
#include <vector>
#include <stack>
#include <algorithm>

#define min(x,y)    (x < y ? x : y)
#define max(x,y)    (x < y ? y : x)
using namespace std;

class friends_pair{
    public:
        int x1, y1, x2, y2;
        bool available = true;
        char element;
        friends_pair();
        friends_pair(int _x1, int _y1, int _x2, int _y2, char _element){
            x1 = _x1, y1 = _y1, x2 = _x2, y2 = _y2;
            element = _element;
        }
};

bool less_element(const friends_pair& left, const friends_pair& right){
    return left.element < right.element;
}

stack<vector<string>> q_board;
stack<vector<friends_pair>> q_pairs;
stack<string> q_seq;
int size_row, size_col;

template <typename T>
T getTop(stack<T>& stack){
    T first_val = stack.top();
    stack.pop();
    return first_val;
}

bool isAvailable(vector<string> &board, int x1, int y1, int x2, int y2, int element){    
    bool route1 = true;
    for(int row = min(x1, x2); row <= max(x1, x2); row++){
       if(board[row][y1] == '.' or board[row][y1] == element)
           continue;
        route1 = false;
        break;
    }
    for(int col = min(y1, y2); col <= max(y1, y2); col++){
        if(board[x2][col] == '.' || board[x2][col] == element)
            continue;
        route1 = false;
        break;
    }
    if(route1)
        return true;
    
    bool route2 = true;
    for(int row = min(x1, x2); row <= max(x1, x2); row++){
       if(board[row][y2] == '.' or board[row][y2] == element)
           continue;
        route2 = false;
        break;
    }
    for(int col = min(y1, y2); col <= max(y1, y2); col++){
        if(board[x1][col] == '.' || board[x1][col] == element)
            continue;
        route2 = false;
        break;
    }
    return route2;
}

vector<friends_pair> getPair(vector<string> &board){
    vector<friends_pair> pairs;
    bool isUsed['Z'-'A'+1] = {false};
    
    for(int row = 0; row < size_row; row++){
        for(int col = 0; col < size_col; col++){
            char element = board[row][col];

            if(element == '.' || element == '*' || isUsed[element-'A'])
                continue;
            
            bool isChanged = false;
            
            auto check = [&]() {
                for(int s_row = row; s_row < size_row; s_row++){
                    for(int s_col = 0; s_col < size_col; s_col++){

                        if(board[s_row][s_col] != element || (s_row == row && s_col == col))
                            continue;

                        friends_pair pair = friends_pair(row, col, s_row, s_col, element);
                        pairs.push_back(pair);
                        isChanged = true;
                        isUsed[element-'A'] = true;
                        return true;
                    }
                }
                return false;
            };
            
            check();
        }
    }
    
    return pairs;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
    //게임판 상태, 삭제한 순서, 남은 쌍
    q_board = stack<vector<string>>();
    q_seq = stack<string>();
    q_pairs = stack<vector<friends_pair>>();
    
    size_row = m, size_col = n;
    
    q_board.push(board);
    q_seq.push("");
    vector<friends_pair> total_pair = getPair(board);
    sort(total_pair.begin(), total_pair.end(), less_element);
    q_pairs.push(total_pair);
    
    int cnt_pair = q_pairs.top().size();
    int before_cnt_pair = 0;
    
    while(!q_board.empty()){
        vector<string>n_board = getTop(q_board);
        string n_seq = getTop(q_seq);
        vector<friends_pair> n_pair = getTop(q_pairs);
        int seq_len = n_seq.size();
        
        if(cnt_pair == seq_len){
            return n_seq;
        }
        if(before_cnt_pair > seq_len){
            return "IMPOSSIBLE";
        }
        
        for(int i = cnt_pair - 1; i >= 0; i--){
            friends_pair pair = n_pair[i];
            
            if(!pair.available){
                continue;
            }
            
            int x1 = pair.x1, y1 = pair.y1, x2 = pair.x2, y2 = pair.y2;
            char element = pair.element;
            
            if(isAvailable(n_board, x1, y1, x2, y2, element)){
                vector<string> new_board = n_board;
                new_board[x1][y1] = new_board[x2][y2] = '.';
                
                string new_seq = n_seq + element;
                
                vector<friends_pair> new_pair = n_pair;
                new_pair[i].available = false;
                
                q_board.push(new_board);
                q_seq.push(new_seq);
                q_pairs.push(new_pair);
            }
        }
        
        //빠른 impossible을 위함
        before_cnt_pair = seq_len;
    }
    return "IMPOSSIBLE";
}