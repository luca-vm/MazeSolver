#include <iostream>
#include <array>
#include <queue>

using namespace std;

int main(){

    int boardRow, boardCol;
    cin >> boardRow >> boardCol;

    int dist[boardRow][boardCol];
    for (int i = 0; i < boardRow; i++){
        for (int j = 0; j < boardCol; j++){

            dist[i][j] = -1;
        
        }
    }

    pair<int, int> parent[boardRow][boardCol];

    char grid[boardRow][boardCol];
    string line;
    pair<int, int> start, goal;

    for (int i = 0; i < boardRow; i++){

        getline(cin, line);
        if (i == 0){
           getline(cin, line);  
        }
        for (int j = 0; j < boardCol; j++){
            grid[i][j] = line[j];
            
            if (line[j] == 'S'){
                start.first = i;
                start.second = j; 
            }
            if (line[j] == 'G'){
                goal.first = i;
                goal.second = j; 
            }
        
        }
    }


    queue<pair<int, int>> fringe; 

    fringe.push({start.first, start.second});
    dist[start.first][start.second] = 0;

    while ((!fringe.empty()) && (dist[goal.first][goal.second] == -1)){

        pair<int, int> curr;
        curr = fringe.front();
        fringe.pop();

        int row, col;

        for (int k = 0; k < 4; k++){

            if (k == 0){
                row = curr.first + 1;
                col = curr.second;
            } else if (k == 1){
                row = curr.first;
                col = curr.second - 1;
            } else if (k == 2){
                row = curr.first - 1;
                col = curr.second;
            } else if (k == 3){
                row = curr.first;
                col = curr.second + 1;
            }

            if ((grid[row][col] != 'x[i]') && (dist[row][col] == -1)){
                dist[row][col] = dist[curr.first][curr.second] + 1;
                parent[row][col] = curr;
                fringe.push({row, col});
            }

        }
    }

    if ((fringe.empty()) && (dist[goal.first][goal.second] == -1)){
        cout << "No Path" << endl;
    }
    else
    {
        pair<int, int> curr;
        curr = goal;
        curr = parent[curr.first][curr.second];

        while (curr != start){
            grid[curr.first][curr.second] = '*';
            curr = parent[curr.first][curr.second];
        }
        
        for (int i = 0; i < boardRow; i++){
            for (int j = 0; j < boardCol; j++){
                cout << char(grid[i][j]);
            }
            cout << endl;
        }

    }
 

    return 0;
}