#include <string>
using std::string;

#include <iostream>

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

  inline void set(const string & title, const string & artist);

private:
  string artist_;
  string title_;
};

inline void Song::set(const string & title, const string & artist)
{
    artist_ = artist;
    title_ = title;
}

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
