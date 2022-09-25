#include <forward_list>
#include <list>
#include <random>
#include <iostream>
#include "gui.hpp"


using namespace std;

const int width = 1000;
const int height = 500;
const int CELL_NUMBER = 1000;
random_device rd;
mt19937 gen{rd()}; 
int speed = 5;
uniform_int_distribution<int> dis{-speed,speed};

struct cell {
    int x,y;
    int strength,blood;
    int speed = 5;


    cell(){
        x=rand()%100;
        y=rand()%100;
    }

    int move(){
        //x += (rand()%speed-speed/2+1);
        //y += (rand()%speed-speed/2);
        x += dis(gen);
        y += dis(gen);
        x = x%width;
        y = y%height;
        return 0;
    }

    const void  draw(){
        //cout << "x: " << x<< "y:" << y << endl;
        gui::drawPoint(x,y);
    }

    bool die() const{
        if(x>=500 && y>=400){
            return true;
        }
        else{
            return false;
        }
    }

    };

 /// @brief 细胞家族
 list<cell>  cells;

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

bool die(const cell& cell){
    return cell.die();
}

int main(){
    init();//初始化
    //模拟循环
    while(1){
        gui::drawBackground();
        for(auto& x:cells){
            
            x.move();
            x.draw();
            if(x.die()){cells.remove_if(die);}
        }
        gui::present();
    }
    return 0;
}

