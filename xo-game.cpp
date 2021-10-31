

#include <cstdio>
#include <cstdlib>

#include <iomanip>
#include <iostream>

#include <ctime>
using namespace std;
char arry[3][3]{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char position, play = 'x';
char arr[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
bool w = true;
int counter = 0, countx = 0, counto = 0, counterx = 0, countero = 0;
char arrx[5] = {' ', ' ', ' ', ' ', ' '}, arro[5] = {' ', ' ', ' ', ' ', ' '};
char all_position[9]{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
int chioce;
void printarry() {
  system("clear");

  for (int i = 0; i < 3; i++) {
    cout << setw(30);
    for (int t = 0; t < 3; t++)
      cout << arry[i][t] << "  ";
    cout << endl;
  }
}
void player() {
t:
  cout << "enter your position player (" << play << ") :";
  cin >> position;
  cin.ignore(100, '\n');
  if (position != '1' && position != '2' && position != '3' &&
      position != '4' && position != '5' && position != '6' &&
      position != '7' && position != '8' && position != '9') {
    cout << "please enter right position player (" << play << ")\n";
    cin.clear();
    cin.ignore(100, '\n');
    goto t;
  }
  for (int i = 0; i < 9; i++) {
    if (position == arr[i])
      w = false;
  }
  if (w == false) {
    cout << "this is riservied position please enter anthor position player ("
         << play << ")\n";
    cin.clear();
    cin.ignore();
    w = true;
    goto t;
  }
  arr[counter] = position;
  counter++;
  if (play == 'x') {
    arrx[countx] = position;
    countx++;
  }
  if (play == 'o') {
    arro[counto] = position;
    counto++;
  }
  for (int i = 0; i < 3; i++) {
    for (int t = 0; t < 3; t++) {
      if (arry[i][t] == position)
        arry[i][t] = play;
    }
  }
  if (chioce == 2) {
    if (play == 'x')
      play = 'o';
    else
      play = 'x';
  }
}

void computer_player() {
  srand(time(0));
  bool x = false;
  int counter_name = 0;
  for (int i = 0; i < 3; i++) {
    for (int t = 0; t < 3; t++) {
      if (arry[i][t] != 'x' && arry[i][t] != 'o')
        counter_name++;
    }
  }
  if (counter_name == 9 || counter_name == 8) {
    for (int i = 0; i < 3; i++) {
      for (int t = 0; t < 3; t++) {
        if (arry[i][t] != 'x' && arry[i][t] != 'o') {
          arry[rand() % 2 + 1][rand() % 2 + 1] = 'o';
          x = false;
          break;
        }
      }
      if (x == false)
        break;
    }

  }

  else {

    if ((arry[0][0] == 'x' && arry[0][1] == 'x') && arry[0][2] != 'o')
      arry[0][2] = 'o';
    else if ((arry[0][0] == 'x' && arry[0][2] == 'x') && arry[0][1] != 'o')
      arry[0][1] = 'o';
    else if ((arry[0][1] == 'x' && arry[0][2] == 'x') && arry[0][0] != 'o')
      arry[0][0] = 'o';

    else if ((arry[0][0] == 'o' && arry[0][1] == 'o') && arry[0][2] != 'x')
      arry[0][2] = 'o';
    else if ((arry[0][0] == 'o' && arry[0][2] == 'o') && arry[0][1] != 'x')
      arry[0][1] = 'o';
    else if ((arry[0][1] == 'o' && arry[0][2] == 'o') && arry[0][0] != 'x')
      arry[0][0] = 'o';

    else if ((arry[1][0] == 'x' && arry[1][1] == 'x') && arry[1][2] != 'o')
      arry[1][2] = 'o';
    else if ((arry[1][0] == 'x' && arry[1][2] == 'x') && arry[1][1] != 'o')
      arry[1][1] = 'o';
    else if ((arry[1][1] == 'x' && arry[1][2] == 'x') && arry[1][0] != 'o')
      arry[1][0] = 'o';

    else if ((arry[1][0] == 'o' && arry[1][1] == 'o') && arry[1][2] != 'x')
      arry[1][2] = 'o';
    else if ((arry[1][0] == 'o' && arry[1][2] == 'o') && arry[1][1] != 'x')
      arry[1][1] = 'o';
    else if ((arry[1][1] == 'o' && arry[1][2] == 'o') && arry[1][0] != 'x')
      arry[1][0] = 'o';

    else if ((arry[2][0] == 'x' && arry[2][1] == 'x') && arry[2][2] != 'o')
      arry[2][2] = 'o';
    else if ((arry[2][0] == 'x' && arry[2][2] == 'x') && arry[2][1] != 'o')
      arry[2][1] = 'o';
    else if ((arry[2][1] == 'x' && arry[2][2] == 'x') && arry[2][0] != 'o')
      arry[2][0] = 'o';

    else if ((arry[2][0] == 'o' && arry[2][1] == 'o') && arry[2][2] != 'x')
      arry[2][2] = 'o';
    else if ((arry[2][0] == 'o' && arry[2][2] == 'o') && arry[2][1] != 'x')
      arry[2][1] = 'o';
    else if ((arry[2][1] == 'o' && arry[2][2] == 'o') && arry[2][1] != 'x')
      arry[2][0] = 'o';

    //**********************
    else if ((arry[0][0] == 'x' && arry[1][0] == 'x') && arry[2][0] != 'o')
      arry[2][0] = 'o';
    else if ((arry[0][0] == 'x' && arry[2][0] == 'x') && arry[1][0] != 'o')
      arry[1][0] = 'o';
    else if ((arry[1][0] == 'x' && arry[2][0] == 'x') && arry[0][0] != 'o')
      arry[0][0] = 'o';

    else if ((arry[0][0] == 'o' && arry[1][0] == 'o') && arry[2][0] != 'x')
      arry[2][0] = 'o';
    else if ((arry[0][0] == 'o' && arry[2][0] == 'o') && arry[1][0] != 'x')
      arry[1][0] = 'o';
    else if ((arry[1][0] == 'o' && arry[2][0] == 'o') && arry[0][0] != 'x')
      arry[0][0] = 'o';

    else if ((arry[0][1] == 'x' && arry[1][1] == 'x') && arry[2][1] != 'o')
      arry[2][1] = 'o';
    else if ((arry[0][1] == 'x' && arry[2][1] == 'x') && arry[1][1] != 'o')
      arry[1][1] = 'o';
    else if ((arry[1][1] == 'x' && arry[2][1] == 'x') && arry[0][1] != 'o')
      arry[0][1] = 'o';

    else if ((arry[0][1] == 'o' && arry[1][1] == 'o') && arry[2][1] != 'x')
      arry[2][1] = 'o';
    else if ((arry[0][1] == 'o' && arry[2][1] == 'o') && arry[1][1] != 'x')
      arry[1][1] = 'o';
    else if ((arry[1][1] == 'o' && arry[2][1] == 'o') && arry[0][1] != 'x')
      arry[0][1] = 'o';

    else if ((arry[0][2] == 'x' && arry[1][2] == 'x') && arry[2][2] != 'o')
      arry[2][2] = 'o';
    else if ((arry[0][2] == 'x' && arry[2][2] == 'x') && arry[1][2] != 'o')
      arry[1][2] = 'o';
    else if ((arry[1][2] == 'x' && arry[2][2] == 'x') && arry[2][0] != 'o')
      arry[0][2] = 'o';

    else if ((arry[0][2] == 'o' && arry[1][2] == 'o') && arry[2][2] != 'x')
      arry[2][2] = 'o';
    else if ((arry[0][2] == 'o' && arry[2][2] == 'o') && arry[1][2] != 'x')
      arry[1][2] = 'o';
    else if ((arry[1][2] == 'o' && arry[2][2] == 'o') && arry[2][0] != 'x')
      arry[0][2] = 'o';

    //*************************
    else if ((arry[0][0] == 'x' && arry[1][1] == 'x') && arry[2][2] != 'o')
      arry[2][2] = 'o';
    else if ((arry[0][0] == 'x' && arry[2][2] == 'x') && arry[1][1] != 'o')
      arry[1][1] = 'o';
    else if ((arry[1][1] == 'x' && arry[2][2] == 'x') && arry[0][0] != 'o')
      arry[0][0] = 'o';

    else if ((arry[0][0] == 'x' && arry[1][1] == 'o') && arry[2][2] != 'x')
      arry[2][2] = 'o';
    else if ((arry[0][0] == 'x' && arry[2][2] == 'o') && arry[1][1] != 'x')
      arry[1][1] = 'o';
    else if ((arry[1][1] == 'x' && arry[2][2] == 'o') && arry[0][0] != 'x')
      arry[0][0] = 'o';

    else if ((arry[0][2] == 'x' && arry[1][1] == 'x') && arry[2][0] != 'o')
      arry[2][0] = 'o';
    else if ((arry[0][2] == 'x' && arry[2][0] == 'x') && arry[1][1] != 'o')
      arry[1][1] = 'o';
    else if ((arry[1][1] == 'x' && arry[2][0] == 'x') && arry[0][2] != 'o')
      arry[0][2] = 'o';

    else if ((arry[1][2] == 'o' && arry[1][1] == 'o') && arry[2][0] != 'x')
      arry[2][0] = 'o';
    else if ((arry[1][2] == 'o' && arry[2][0] == 'o') && arry[1][1] != 'x')
      arry[1][1] = 'o';
    else if ((arry[1][1] == 'o' && arry[2][0] == 'o') && arry[0][2] != 'x')
      arry[0][2] = 'o';
    else {
      for (int i = 0; i < 3; i++) {
        for (int t = 0; t < 3; t++) {
          if (arry[i][t] != 'x' && arry[i][t] != 'o') {
            arry[i][t] = 'o';
            x = false;
            break;
          }
        }
        if (x == false)
          break;
      }
    }
  }
  counter_name = 0;
}
char winer() {
  int counter_counter = 0;
  for (int i = 0; i < 3; i++) {
    for (int t = 0; t < 3; t++) {
      if (arry[i][t] == 'x')
        counterx++;
      if (arry[i][t] == 'o')
        countero++;
      if (counterx == 3 || countero == 3)
        return (counterx > countero) ? 'x' : 'o';
    }

    counterx = 0;
    countero = 0;
  }
  counterx = 0;
  countero = 0;
  for (int i = 0; i < 3; i++) {
    for (int t = 0; t < 3; t++) {
      if (arry[t][i] == 'x')
        counterx++;
      if (arry[t][i] == 'o')
        countero++;
      if (counterx == 3 || countero == 3)
        return (counterx > countero) ? 'x' : 'o';
    }

    counterx = 0;
    countero = 0;
  }
  counterx = 0;
  countero = 0;
  for (int i = 0; i < 3; i++) {
    for (int t = 0; t < 3; t++) {
      if (arry[i][t] == 'x' || arry[i][t] == 'o')
        counter_counter++;
    }
  }
  if (arry[0][0] == 'x' && arry[1][1] == 'x' && arry[2][2] == 'x')
    return 'x';
  if (arry[0][0] == 'o' && arry[1][1] == 'o' && arry[2][2] == 'o')
    return 'o';

  if (arry[0][2] == 'x' && arry[1][1] == 'x' && arry[2][0] == 'x')
    return 'x';
  if (arry[0][2] == 'o' && arry[1][1] == 'o' && arry[2][0] == 'o')
    return 'o';
  if (counter_counter == 9)
    return 'z';
  return '_';
}
void printwiner() {
  if (winer() == 'x')
    cout << "the winer is player (x)\n";
  else if (winer() == 'o')
    cout << "the winer is player (o)\n";
  else
    cout << "there is now winer\n";
}
void printdata() {

  cout << setw(30) << "the all data\n";
  cout << setw(30)
       << "=======================================================\n";

  cout << "the all position are              : ";
  for (int i = 0; i < 9; i++)
    cout << arr[i] << " ";
  cout << endl;
  cout << "the position of  player (x) are   : ";
  for (int i = 0; i < 5; i++)
    cout << arrx[i] << " ";
  cout << endl;
  cout << "the position of player (o) are    : ";
  for (int i = 0; i < 5; i++)
    cout << arro[i] << " ";
  cout << endl;
  // cout << "the game finish at\t          : ";
  system("date ");
  // cout << "the game finish at\t          : ";
  system("date");
  cout << setw(30)
       << "=======================================================\n";
}
void choosefirstplayer() {
u:
  cout << "enter the player who begin (x)\n"
       << "                           (o)\n"
       << endl;
  cin >> play;
  if (play != 'x' && play != 'o') {
    cout << "please enter rigth character\n";
    cin.clear();
    cin.ignore(100, '\n');
    goto u;
  }
}
void game() {
chioce_x:
  cout << "would you play with [1]-computer\n"
       << "                    [2]-frind\n"
       << "enter your choice :";

  cin >> chioce;
  if (cin.fail() || (chioce != 1 && chioce != 2)) {
    cout << "error :please enter right choice\n";
    goto chioce_x;
  }

  switch (chioce) {
  case 1: {

    while (winer() == '_') {
      printarry();

      player();
      computer_player();
      printarry();
    }
    printwiner();
    printdata();
  } break;
  case 2: {
    choosefirstplayer();
    int bigcounter = 0;
    while (winer() == '_') {
      printarry();
      player();
      printarry();
    }
    printwiner();
    printdata();
  }
  }
}

int main() {
  game();

  cout << "Enter any key to finished  !!!!!!!!!!!!!" << endl;
  system("read x");
  return 0;
}