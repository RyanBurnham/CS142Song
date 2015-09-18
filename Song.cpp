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
public:
  Song(): artist_("none"), title_("invalid") {}
  Song(const string & title, const string & artist): title_(title), artist_(artist) {}

  inline void print(ostream & out) const;
  inline bool is_equal(const Song & other) const;

  string artist() const {return artist_;}

private:
  string artist_;
  string title_;
};

inline void Song::print(ostream & out) const
{
  out << title_ << endl << artist_;
}

inline bool Song::is_equal(const Song & song2) const
{
  return title_ == song2.title_ && artist_ == song2.artist_;
}

int main()
{
  while(true)
  {
    string t_artist;
    string t_title;

    cout << "Enter a song name: ";
    getline(cin, t_title);
    cout << "Enter the artist of the song: ";
    getline(cin, t_artist);

    Song song1;
    song1.initialize(t_title, t_artist);

    cout << "Enter a song name: ";
    getline(cin, t_title);
    cout << "Enter the artist of the song: ";
    getline(cin, t_artist);

    Song song2;
    song2.initialize(t_title, t_artist);

    if(song1.is_equal(song2))
      cout << "They are the same song." << endl;
    else
      cout << "They are different songs." << endl;

    cout << "The first song is:\n";
    song1.print(cout);
    cout << "The second song is:\n";
    song2.print(cout);

    cout << "RESTARTING TEST\n";
  }

  return 0;
}

