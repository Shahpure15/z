#include<iostream>
using namespace std;

int grid[2][2];

bool isSafe(int r,int c,int num){
    for(int i=0;i<2;i++)
        if(grid[r][i]==num || grid[i][c]==num) return false;
    return true;
}

bool solve(){
    for(int r=0;r<2;r++){
        for(int c=0;c<2;c++){
            if(grid[r][c]==0){
                for(int num=1;num<=2;num++){
                    if(isSafe(r,c,num)){
                        grid[r][c]=num;
                        if(solve()) return true;
                        grid[r][c]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    cout<<"Enter 2x2 Sudoku (0 for empty):
";
    for(int r=0;r<2;r++)
        for(int c=0;c<2;c++)
            cin>>grid[r][c];

    if(solve()){
        cout<<"Solved:
";
        for(int r=0;r<2;r++){
            for(int c=0;c<2;c++)
                cout<<grid[r][c]<<" ";
            cout<<endl;
        }
    } else cout<<"No solution!";
}
