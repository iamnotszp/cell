#include <SDL2/SDL.h>
#include "gui.hpp"
#include <iostream>



namespace gui{
    SDL_Window* window ;
    SDL_Renderer* renderer;
    int init(int width,int height){
        if(SDL_Init(SDL_INIT_EVERYTHING) != 0){std::cout << "SDL init失败，原因自己找"<< SDL_GetError() <<std::endl;};
        SDL_Window* window= SDL_CreateWindow("cells",10,10,width,height,SDL_WINDOW_SHOWN);
        if (window == nullptr)
        {
            return 0;
        }
        
        std::cout << SDL_GetError() << "no fail" << std::endl;
        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
        return 0;
    }
    /// @brief draw a point
    /// @param x 
    /// @param y 
    /// @return fail or success
    int drawPoint(int x,int y){
        SDL_SetRenderDrawColor(renderer,255,0,0,0);
        SDL_RenderDrawPoint(renderer,x,y);
        return 0;
    }

    int present(){
        SDL_RenderPresent(renderer);
        return 0;
    }

    /// @brief 设置现实的背景
    /// @return 成功与否
    int drawBackground(){
        SDL_SetRenderDrawColor(renderer,0,0,0,0);
        SDL_RenderFillRect(renderer,NULL);
        return 0;
    }
}