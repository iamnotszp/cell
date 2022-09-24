#include <forward_list>
#include <random>
#include <iostream>
#include "gui.hpp"


using namespace std;


struct cell {
    int x,y;
    int strength,blood;
    int speed = 10;

    cell(){
        x=rand()%10000;
        y=rand()%10000;
    }

    int move(){
        x += rand()%speed;
        y += rand()%speed;
        return 0;
    }

    void  draw(){
        //cout << "x: " << x<< "y:" << y << endl;
        gui::drawPoint(x,y);
    }

    };

 /// @brief 细胞家族
 forward_list<cell>  cells;

 int init(){
    cells.push_front(cell());
    //cells.push_front(cell());
    //cells.push_front(cell());
    return 0;
 }

int main(){
    init();//初始化
    //模拟循环
    while(1){
        for(auto& x:cells){
            x.move();
            x.draw();
        }
    }
    return 0;
}

