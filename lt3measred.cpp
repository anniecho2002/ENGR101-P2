/*
 * The code below is meant to detect whether the Red Ruby
 * is present. The strategy implemented by the code is not very effective. 
 * Study the code so that you understand what the strategy is and how 
 * it is implemented. Then design and implement a better strategy.
 * 
 * */

#include <iostream>

#include "E101.h"

using namespace std;

int main() {
  int err = init(0);
  cout << "Hello. err=" << err << endl;
  int totred = 0; // combined value of all red values of all pixels
  int totint = 0; // ditto for grey (int standing for intensity)
  int totgreen = 0;
  int totblue = 0;
  int redPixelCount = 0;
  bool heist = false;
  open_screen_stream();

  // make 1000 runs  
  for (int countrun = 0; countrun < 1000; countrun++) {
    take_picture();
    update_screen();
    totred = 0;
    totint = 0;
    totgreen = 0;
    totblue = 0;
    redPixelCount = 0;

    // for all pixels in latest image
    for (int row = 0; row < 240; row = row + 10) {
      for (int col = 0; col < 320; col = col + 1) {
        totred = (int) get_pixel(row, col, 0);
        totgreen = (int) get_pixel(row, col, 1);
        totblue = (int) get_pixel(row, col, 2);
        totint = (int) get_pixel(row, col, 3);

        if ((totred > (1.4 * totgreen)) && (totred > (1.4 * totblue))) {
          redPixelCount++;
          //set.pixel(row, col, r, g, b);
          //update.screen();

          if ((row < 65 || row > 185) || (col < 55 || col > 275)) {
            cout << "Heist is underway" << endl;
            //return 0;

          }
        }
      }
    }

    //cout<<" red pixels="<<redPixelCount;
    //cout<<" totred="<<totred;
    if (redPixelCount > 30) {
      cout << "Ruby is there" << endl;
    } else {
      cout << "Ruby is not there" << endl;
    }

    cout << " countrun=" << countrun;
    sleep1(100); // slow down a bit to make display easier
  }
  close_screen_stream();
  return 0;
}
