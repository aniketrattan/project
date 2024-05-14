#ifndef stateMachine_h
#define stateMachine_h

#include <memory>
#include <stack>

#include "state.h"
using namespace std;

namespace project {
typedef unique_ptr<State> StateRef;

// class will handle all the states of the machine
class StateMachine {
 private:
  stack<StateRef> _states;
  StateRef _newState;

  bool _isRemoving;
  bool _isAdding;
  bool _isReplacing;

 public:
  StateMachine() {}
  ~StateMachine() {}
  /*adds a state onto the stack and will be the latest state, the isReplacing
  value states if you are replacing the current state with the inputed one*/
  void AddState(StateRef newState, bool isReplacing = true);
  // to manually remove the top state
  void RemoveState();
  // program will run at the start of each cpp file.
  void ProcessStateChanges();
  // this will return the top level state
  StateRef &GetActiveState();
};

}  // namespace project

#endif