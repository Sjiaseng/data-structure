#include <iostream>
using namespace std;

// weighted graph
struct arc{
    int adj;
    double distance;
    double fare;
    int time;

};

class Graph{
    private:
        arc matrix [7][7];
    public:
        Graph(){
            for (int row = 0; row < 7; row ++){
                for (int col = 0 ; col < 7 ; col++){
                    matrix[row][col].adj = 0;

                }
            }
        }
        bool adjacent(int row, int col){
            if(matrix[row][col].adj == 1){
                return true;
            }else{
                return false;
            }
        }

        void connect(int row, int col, double distance, double fare, int time){
            matrix[row][col].adj = 1;
            matrix[row][col].distance = distance;
            matrix[row][col].fare = fare;
            matrix[row][col].time = time;
        }

        void disconnect(int row, int col, double distance, double fare, int time){
            matrix[row][col].adj = 0;
            matrix[row][col].distance = distance;
            matrix[row][col].fare = fare;
            matrix[row][col].time = time;
        }

        void printmatrix(){
            for (int row = 0; row < 7; row ++){
                for (int col = 0 ; col < 7 ; col++){
                    cout << matrix[row][col].adj;
                }
                cout << endl;
            }
        }
};

void menu(){
    cout << "1. add connection"<< endl;
    cout << "2. remove connection"<< endl;
    cout << "3. check connection"<< endl;
    cout << "4. print matrix"<< endl;
    cout << "5. exit"<< endl;
}


int main(){
    Graph graph;
    int choice;

    graph.connect(0,3);
    graph.connect(1,0);
    graph.connect(1,1);
    graph.connect(1,3);
    graph.connect(3,1);
    graph.connect(3,4);
    graph.connect(4,1);
    graph.connect(5,1);

    graph.printmatrix();

    do{
        int from, to, time;
        double distance, fare;
        menu();
        cout << "Choice: ";
        cin >> choice;

        switch(choice){
            case 1: 
                cout << "from: ";
                cin >> from;
                cout << "to: ";
                cin >> to;
                cout << "distance: ";
                cin >> distance;
                cout << "fare: ";
                cin >> fare;
                cout << "time: ";
                cin >> time;
                connect(from, to);
                break;
            case 2:
                cout << "from: ";
                cin >> from;
                cout << "to: ";
                cin >> to;
                disconnect(from, to);
                break;

            default: 
                cout << "Invalid Choise Please Try Again" << endl;
                break;
        }

    }while(choice != 5);

    //row to row (Do with) not with column to column (matrix in slides)
}
