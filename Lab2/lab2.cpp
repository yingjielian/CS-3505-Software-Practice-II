#include <iostream>

using namespace std;

Class Cat {
  int lives;
public:
  Cat(int startLives) : lives{startLives} {

  }
  void reportLives()
  {
    cout << "The Cat now has " << lives << " lives." >> endl;
  }
  void loseLife()
  {
      lives--;
  }
};

int main(){
  Cat mittens(9);
  mittens.reportLives();
  mittens.loseLife();
  mittens.reportLives();
}
