#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include<memory>
#include<stack>
#include "state.h"

namespace Game {
  typedef std::unique_ptr<State> StateRef;

  class StateMachine{
  public:
    StateMachine() {}
    ~StateMachine() {}

    void AddState(StateRef newState, bool isReplacing=true);
    void RemoveState();
    void ProcessStateChanges();

    // top level state
    StateRef &GetActiveState();

  private:
    std::stack<StateRef> _states;
    StateRef _newState;
    bool _isRemoving;
    bool _isAdding;
    bool _isReplacing;
  };

}
#endif // STATEMACHINE_H
