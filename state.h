#ifndef STATE_H
#define STATE_H

namespace Game{
  class State{
  public:
    // define pure virtual functions
    virtual void Init() = 0;
    virtual void HandleInput() =0;
    virtual void Update(float dt) = 0;
    virtual void Draw( float delta)=0;
    virtual void Pause(){}
    virtual void Resume(){}
  };
}

#endif // STATE_H
