#ifndef CHARACTER_H
#define CHARACTER_H

class Character{
protected:
  int health;
  bool isAlive;
public:
  // constructor
  Character(int health);

  // getters
  int get_health();
  bool get_isAlive();

  // setters
  void set_health(int health);

  // update is alive status
  void checkHealth();

};

#endif // CHARACTER_H