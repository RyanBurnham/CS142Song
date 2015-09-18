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

  inline bool is_equal(const Song & other) const;

  string artist() const {return artist_;}
  string title() const {return title_; }

private:
  string artist_;
  string title_;
};

inline void operator<<(ostream & out, const Song & song)
{
  out << song.title() << endl << song.artist() << endl;
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

    Song song1(t_title, t_artist);

    cout << "Enter a song name: ";
    getline(cin, t_title);
    cout << "Enter the artist of the song: ";
    getline(cin, t_artist);

    Song song2(t_title, t_artist);

    if(song1.is_equal(song2))
      cout << "They are the same song." << endl;
    else
      cout << "They are different songs." << endl;

    cout << "The first song is:\n";
    cout <<song1;
    cout << "The second song is:\n";
    cout << song2;

    cout << "RESTARTING TEST\n";
  }

  return 0;
}

