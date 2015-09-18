#include "Song.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
  while(true)
  {
    string t_artist;
    string t_title;

    Song song1;
    Song song2;

    cout << "Enter a song, artist then title denoted by enter: ";
    cin >> song1;

    cout << "Enter a song, artist then title denoted by enter: ";
    cin >> song2;

    if(song1 == song2)
      cout << "They are the same song." << endl;
    else
      cout << "They are different songs." << endl;

    cout << "The first song is:\n" << song1 << "The second song is:\n" << song2;

    cout << "Copying song1 to song 2" << endl;
    song1 = song2;

    if(song1 == song2)
      cout << "They are the same song." << endl;
    else
      cout << "They are different songs." << endl;

    cout << "Song1: " << song1 << "Song2: " << song2;

    cout << "RESTARTING TEST\n";
  }

  return 0;
}

