struct
{
  string artist;
  string title;
};

void initialize(Song & song)
{
  song.artist = "none";
  song.title = "invalid";
}

void print(const Song & song, ostream & out)
{
  out << song.title << endl << song.artist;
}

bool is_equal(const Song & song1, const Song & song2)
{
  return song1.title == song2.title && song1.artist == song2.artist;
}

