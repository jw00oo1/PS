#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> key){
    int keysize = key.size();
    vector<vector<int>> rot_key(keysize, vector<int>(keysize));
    
    for(int i = 0; i < keysize; i++)
    {
        for(int j = 0; j < keysize; j++)
        {
            rot_key[j][keysize-1-i] = key[i][j];
        }
    }
    return rot_key;
}

bool put_key(int x, int y, vector<vector<int>> key, vector<vector<int>> board)
{
    int keysize = key.size(), boardsize = board.size();
    
    //put key onto board
    for(int i = x, ki = 0; i < x + keysize; i++, ki++)
    {
        for(int j = y, ky = 0; j < y + keysize; j++, ky++)
        {
            board[i][j] = board[i][j] ^ key[ki][ky];
        }
    }
    //check lock
    for(int i = keysize - 1; i < boardsize - keysize + 1; i++)
    {
        for(int j = keysize - 1; j < boardsize - keysize + 1; j++)
        {
            if(!board[i][j])    return false;
        }
    }
    
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int keysize = key.size(), locksize = lock.size();
    int boardsize = locksize + (keysize - 1) * 2;
    
    vector<vector<int>> board(boardsize, vector<int>(boardsize));
    for(int i = keysize - 1, lx = 0; i < keysize - 1 + locksize; i++, lx++)
    {
        for(int j = keysize - 1, ly = 0; j < keysize - 1 + locksize; j++, ly++)
            board[i][j] = lock[lx][ly];
    }
    
    vector<vector<int>> r_key = key;
    for(int i = 0; i < 4; i++)
    {
        r_key = rotate(r_key);
        for(int x = 0; x < boardsize - keysize + 1; x++)
        {
            for(int y = 0; y < boardsize - keysize + 1; y++)
            {
                answer = put_key(x, y, r_key, board);
                if(answer)  return answer;
            }
        }
    }
    
    return answer;
}