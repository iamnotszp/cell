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
int speed = 50;
uniform_int_distribution<int> dis{-speed,speed};
struct cell;

 /// @brief 细胞家族
 list<cell>  cells;


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
        if(x>=500 || y>=400 || cells.size()*dis(gen)/speed>20000){
            return true;
        }
        else{
            return false;
        }
    }

    int breed(){
        int 限制 = 2;//经测试，为四会逐渐减少，为三会有波动，主要维持在1000左右
        int n = rd()%200>限制?1:0;
        //int n =1;
        //int n = 3;
        for(int i = 0;i < n;i ++ ){
            cells.push_front(cell());
        }
        return n;
    }

    };


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

//template<typename T> bool die(T this){
//    return this.die;
//}

//bool die(auto x){
//    return x.die():
//}

bool die(const cell& cell){
    return cell.die();
}

int main(){
    init();//初始化
    //模拟循环
    while(1){
        gui::drawBackground();
        for(auto i = cells.begin();i != cells.end();i++){
            
            i->move();
            i->draw();
            i->breed();
            //if(i->die())cells.erase(i);
        }
        cells.remove_if(die);
        cout << cells.size() << endl;
        gui::present();
    }

    return 0;
}

