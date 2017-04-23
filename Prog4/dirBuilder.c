// C file for utility functions surrounds directory building and such
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "dirBuilder.h"

void createBaseDir(){
  // music, movies -> shows, documents, pictures, other
  struct stat status = {0};
  if(stat("music", &status) == -1){
    mkdir("music", S_IRWXU | S_IRWXG | S_IRWXO);
  }
  if(stat("movies", &status) == -1){
    mkdir("movies", S_IRWXU | S_IRWXG | S_IRWXO);
  }
  if(stat("movies/shows", &status) == -1){
    mkdir("movies/shows", S_IRWXU | S_IRWXG | S_IRWXO);
  }
  if(stat("documents", &status) == -1){
    mkdir("documents", S_IRWXU | S_IRWXG | S_IRWXO);
  }
  if(stat("pictures", &status) == -1){
    mkdir("pictures", S_IRWXU | S_IRWXG | S_IRWXO);
  }
  if(stat("other", &status) == -1){
    mkdir("other", S_IRWXU | S_IRWXG | S_IRWXO);
  }
  return;
}

char * createArtistDir(char * artist, char * album){
  // create artist directory inside the music folder
  struct stat status = {0};
  char * music = "music/";
  char * artistDir = malloc(sizeof(char) * (strlen(artist) + strlen(music)));
  char * albumDir = malloc(sizeof(char) * (strlen(artist) + strlen(music) + strlen(album)));
  artistDir[0] = '\0';
  albumDir[0] = '\0';
  //-------build Artist Dir--------------
  strcat(artistDir, music);
  strcat(artistDir, artist);
  if(stat(artistDir, &status) == -1){
    mkdir(artistDir, S_IRWXU | S_IRWXG | S_IRWXO);
  }
  //-------------------------------------
  //-------build Album Dir---------------
  strcat(albumDir, artistDir);
  strcat(albumDir, "/");
  strcat(albumDir, album);
  if(stat(albumDir, &status) == -1){
    mkdir(albumDir, S_IRWXU | S_IRWXG | S_IRWXO);
  }
  //-------------------------------------
  artistDir[0] = '\0';
  free(artistDir);
  return albumDir;
}

char * createMovieYearDir(char * year){
  struct stat status = {0};
  char * yearDir = malloc(sizeof(char) * (strlen("movies/") + strlen(year) + strlen("/") + 1));
  yearDir[0] = '\0';
  strcat(yearDir, "movies/");
  strcat(yearDir, year);
  strcat(yearDir, "/");
  yearDir[strlen(yearDir)] = '\0';
  if(stat(yearDir, &status) == -1){
    mkdir(yearDir, S_IRWXU | S_IRWXG | S_IRWXO);
  }
  return yearDir;
}

char * createSeriesDir(char * series){
  struct stat status = {0};
  char * seriesDir = malloc(sizeof(char) * (strlen("movies/") + strlen("shows/") + strlen(series) + strlen("/") + 1));
  seriesDir[0] = '\0';
  strcat(seriesDir, "movies/");
  strcat(seriesDir, "shows/");
  strcat(seriesDir, series);
  strcat(seriesDir, "/");
  seriesDir[strlen(seriesDir)] = '\0';
  if(stat(seriesDir, &status) == -1){
    mkdir(seriesDir, S_IRWXU | S_IRWXG | S_IRWXO);
  }
  return seriesDir;
}

char * createSeasonDir(char * series, char * season){
  struct stat status = {0};
  char * seasonDir = malloc(sizeof(char) * (strlen(series) + strlen(season) + strlen("/") + 1));
  seasonDir[0] = '\0';
  strcat(seasonDir, series);
  strcat(seasonDir, season);
  strcat(seasonDir, "/");
  seasonDir[strlen(seasonDir)] = '\0';
  if(stat(seasonDir, &status) == -1){
    mkdir(seasonDir, S_IRWXU | S_IRWXG | S_IRWXO);
  }
  return seasonDir;
}
