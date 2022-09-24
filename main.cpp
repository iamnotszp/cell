#include <forward_list>
#include <random>
#include <iostream>

using namespace std；

struct cell {
    int x,y;
    int strength,blood;
    int speed = 10;

    cell(){
        x=rand()%1000;
        y=rnad()%1000;
    }

    int move(){
        x += rand();
        y += rand();
        return 0;
    }

    };

 /// @brief 细胞家族
 forward_list<int>  cells;

int main(){
    cout << "hello world!" << endl;
    return 0;
}

