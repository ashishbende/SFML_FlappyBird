#include<iostream>
#include<sstream>
#include "definitions.h"
#include "splashstate.h"

namespace Game {
  SplashState::SplashState(GameDataRef data)
    :_data(data){}
  void SplashState::Init(){
    _data->assets.LoadTexture("Splash state background", SPLASH_SCENE_BACKGROUND_FILEPATH);
    _background.setTexture(this->_data->assets.GetTexture("Splash state background"));
  }

  void SplashState::HandleInput(){
    sf::Event event;
    while(_data->window.pollEvent(event)){
        if(sf::Event::Closed == event.type){
            _data->window.close();
          }
      }
  }

  void SplashState::Update(float dt){
    if(_clock.getElapsedTime().asSeconds()>SPLASH_STATE_SHOW_TIME){
        std::cout<<"Go to main menu."<<std::endl;
        std::cout<<"Dt = " << dt;
      }
  }

  void SplashState::Draw(float dt){
    std::cout<<"Dt = " << dt;
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.display();
  }
}

