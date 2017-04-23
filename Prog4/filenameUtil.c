// Utility C file for parsing a filename
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filenameUtil.h"
#include "dirBuilder.h"

char * filetype(char * finp){
    // returns the substring in which the last occurence of the period .
    return strrchr(finp, '.');
}

char ** parseMP3(char * mp3File){
  int i;
  char * token;
  const char dash[2] = "-";
  char ** mp3Arr = malloc(3 * sizeof(char *)); // allocate size for string arr
  for(i = 0; i < 3; i++){
    mp3Arr = malloc(1024 * sizeof(char)); // and also sizes for each string i
  }
  token = strtok(mp3File, dash);
  mp3Arr[0] = token; // get and store first token, followed by other two tokens
  i = 1;
  while(token != NULL){
    token = strtok(NULL, dash);
    mp3Arr[i] = token;
    i++;
  }
  return mp3Arr;
}

char ** parseMKV(char * mkvFile){
  int i;
  const char dash[2] = "-";
  char * token;
  char ** mkvArr;
  mkvArr = malloc(4 * sizeof(char *)); // malloc space of 3-string arr
  for(i = 0; i < 4; i++){
    mkvArr = malloc(1024 * sizeof(char)); // and also sizes for each string i
  }
  token = strtok(mkvFile, dash);
  mkvArr[0] = token;
  token = strtok(NULL, dash);
  mkvArr[1] = token;
  token = strtok(NULL, dash);
  // Case 1: The mkvfile has only 1 dash (MOVIE)
  if(token == NULL){
    mkvArr[2] = NULL;
    mkvArr[3] = NULL;
  }
  // Case 2: The mkvFile has 3 dashes (SHOW)
  if(token != NULL){
    mkvArr[2] = token;
    token = strtok(NULL, dash);
    mkvArr[3] = token;
  }
  return mkvArr;
}

char * finalMusicDir(char * albumDir, char * filename, char * exte){
  char * sl = "/";
  char * destFolder = malloc(sizeof(char) * (strlen(albumDir) + strlen(sl) + strlen(filename) + strlen(exte) + 1));
  destFolder[0] = '\0';
  strcat(destFolder, albumDir);
  strcat(destFolder, "/");
  strcat(destFolder, filename);
  strcat(destFolder, exte);
  destFolder[strlen(destFolder)] = '\0';
  return destFolder;
}

char * finalMovieDir(char * yearDir, char * filename, char * exte){
  char * destFolder = malloc(sizeof(char) * (strlen(yearDir) + strlen("/") + strlen(filename) + strlen(exte) + 1));
  destFolder[0] = '\0';
  strcat(destFolder, yearDir);
  strcat(destFolder, filename);
  strcat(destFolder, exte);
  destFolder[strlen(destFolder)] = '\0';
  return destFolder;
}

char * finalShowDir(char * seasonDir, char * episode, char * title, char * exte){
  char * destFolder = malloc(sizeof(char) * (strlen(seasonDir) + strlen(episode) + strlen("-") + strlen(title) + strlen(exte) + 1));
  destFolder[0] = '\0';
  strcat(destFolder, seasonDir);
  strcat(destFolder, episode);
  strcat(destFolder, "-");
  strcat(destFolder, title);
  strcat(destFolder, exte);
  destFolder[strlen(destFolder)] = '\0';
  return destFolder;
}

char * finalOtherDir(char * srcFile, char * headerDir){
  char * destFolder = malloc(sizeof(char) * (strlen(srcFile) + strlen(headerDir) + 1));
  destFolder[0] = '\0';
  strcat(destFolder, headerDir);
  strcat(destFolder, srcFile);
  destFolder[strlen(destFolder)] = '\0';
  return destFolder;
}
