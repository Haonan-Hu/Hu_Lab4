#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class movie
{
public:
  movie(std::string movie, double rating);
  ~movie() {};
  std::string getMovie()const;
  void setMovie(std::string movie);
  double getRating()const;
  void setRating(double rating);
private:
  std::string m_movie;
  double m_rating;
};

#endif
