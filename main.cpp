#include <forward_list>
#include <random>
#include <iostream>
#include "gui.hpp"


using namespace std;

const int width = 1000;
const int height = 500;
const int CELL_NUMBER = 100;

struct cell {
    int x,y;
    int strength,blood;
    int speed = 10;

    cell(){
        speed = speed * 2;//保证speed为偶数
        x=rand()%100;
        y=rand()%100;
    }

    int move(){
        x += (rand()%speed-speed/2+1);
        y += (rand()%speed-speed/2+1);
        x = x%width;
        y = y%height;
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
    gui::init(width,height);
    //cells.push_front(cell());
    //cells.push_front(cell());
    //cells.push_front(cell());
    for(int i = 0;i < CELL_NUMBER ;i++){
        cells.push_front(cell());
    }
    return 0;
 }

int main(){
    init();//初始化
    cout << "hello" << std::endl;
    //模拟循环
    while(1){
        gui::drawBackground();
        for(auto& x:cells){
            x.move();
            x.draw();
        }
        gui::present();
    }
    return 0;
}

