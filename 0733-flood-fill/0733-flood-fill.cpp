class Solution {
public:

    int c;
    int val;
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // this is just bfs/dfs
        
        //initialize global vars
        c = color;
        val = image[sr][sc];
        
        // intialize visited
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), 0));
        
        // start dfs
        dfs(image, visited, sr, sc);
        
        // return image
        return image;
    }
    
    void dfs(vector<vector<int>>& img, vector<vector<int>>& visited, int x, int y){
        if(x < 0 || y < 0 || x >= img.size() || y >= img[0].size()){
            return;
        }
        else{
            // only change to color if matching value of source
            if(img[x][y] != val || visited[x][y]){
                return;
            }
            else{
                // change color
                img[x][y] = c;
                
                // add to visited
                visited[x][y] = 1;
                
                // do DFS
                dfs(img, visited, x+1, y);
                dfs(img, visited, x, y+1);
                dfs(img, visited, x-1, y);
                dfs(img, visited, x, y-1);
            }
        }
    }
    
};