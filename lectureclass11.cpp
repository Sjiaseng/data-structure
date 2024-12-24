#include <iostream>
using namespace std;

// non weighted graph
class Graph{
    private:
        int matrix [7][7];
    public:
        Graph(){
            for (int row = 0; row < 7; row ++){
                for (int col = 0 ; col < 7 ; col++){
                    matrix[row][col] = 0;

                }
            }
        }
        bool adjacent(int row, int col){
            if(matrix[row][col] == 1){
                return true;
            }else{
                return false;
            }
        }

        void connect(int row, int col){
            matrix[row][col] = 1;
        }

        void disconnect(int row, int col){
            matrix[row][col] = 0;
        }
};

int main(){

    return 0;
}