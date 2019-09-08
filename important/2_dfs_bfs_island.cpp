class Solution {
public:
    void searchBFS(vector<vector<char>>& grid, bool* visited, int i, int j, int rows, int cols)
    {
        visited[i*cols + j]=true;
        queue<pair<int,int>> qu;
        qu.push(make_pair(i,j));

        int n_rows[] = {-1,1,0,0};
        int n_cols[] = {0,0,-1,1};

        while(!qu.empty())
        {
            int pop_row = qu.front().first;
            int pop_col = qu.front().second;
            qu.pop();
            // std::cout<<pop_row<<","<<pop_col<<std::endl;

            for(int idx = 0; idx<4;idx++)
            {
                int c_row = pop_row + n_rows[idx];
                int c_col = pop_col + n_cols[idx];

                if(c_row>=0 && c_col>=0 && c_row<rows && c_col<cols)
                {
                    if(!visited[c_row*cols + c_col]) visited[c_row*cols + c_col]=true;
                    else continue;

                    if(grid[c_row][c_col]=='1') qu.push(make_pair(c_row,c_col));
                }
                else continue;
            }
        }
    }

    void searchDFS(vector<vector<char>>& grid, bool* visited, int i, int j, int rows, int cols)
    {
        visited[i*cols + j]=true;

        int n_rows[] = {-1,1,0,0};
        int n_cols[] = {0,0,-1,1};

        for(int idx = 0; idx<4;idx++)
        {
            int c_row = i + n_rows[idx];
            int c_col = j + n_cols[idx];

            if(c_row>=0 && c_col>=0 && c_row<rows && c_col<cols)
            {
                if(!visited[c_row*cols + c_col]) visited[c_row*cols + c_col]=true;
                else continue;

                if(grid[c_row][c_col]=='1') searchDFS(grid, visited, c_row, c_col, rows, cols);
            }
            else continue;
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        if(grid.empty()) return 0;

        int row = grid.size();
        int col = grid[0].size();

        // std::cout<<row<<col<<std::endl;

        bool visited[row*col];
        memset(visited,false,sizeof(visited));

        int count = 0;

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(!visited[i*col + j] && grid[i][j]=='1')
                {
                    searchDFS(grid, visited, i, j, row, col);
                    count++;
                }
            }
        }

        return count;
    }
};
