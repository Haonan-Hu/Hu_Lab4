#include "Movie.h"


movie::movie(std::string movie, double rating)
{
  m_movie = movie;
  m_rating = rating;
}

std::string movie::getMovie()const
{
  return m_movie;
}

void movie::setMovie(std::string movie)
{
  m_movie = movie;
}

double movie::getRating()const
{
  return m_rating;
}

void movie::setRating(double rating)
{
  m_rating = rating;
}
