#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;

class Song
{

    friend istream & operator>>(istream & in, Song & s);

public:
  Song(): artist_("none"), title_("invalid") {}
  Song(const string & title, const string & artist): title_(title), artist_(artist) {}

  inline bool operator==(const Song & other) const;

  inline void operator=(const Song & value);

  string artist() const {return artist_;}
  string title() const {return title_; }

private:
  string artist_;
  string title_;
};

inline istream & operator>>(istream & in, Song & s)
{
    in >> s.artist_ >> s.title_;
}

inline void Song::operator=(const Song & value)
{
    artist_ = value.artist_;
    title_ = value.title_;
}

inline ostream & operator<<(ostream & out, const Song & song)
{
  out << song.title() << endl << song.artist() << endl;
  return out;
}

inline bool Song::operator==(const Song & song2) const
{
  return title_ == song2.title_ && artist_ == song2.artist_;
}

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

