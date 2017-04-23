// George Juarez - ICSI402
// Programming Assignment #4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "filenameUtil.h"
#include "dirBuilder.h" // I heard you like includes

int main(int argc, char * argv[]){
  DIR * dir;
  struct dirent * ent;
  char * extArr[6] = {".mp3", ".mkv", ".docx", ".txt", ".jpg", ".png"};
  int i, uhoh; // counter var and errnumber handle for rename
  char * srcFile; // string to hold copy of the source file
  char * destFolder; // string to hold destination folder
  char * filename; // string to hold the current filename
  char * exte; // string to hold the current filename extension
  //-----------------check for correct number of arguments----------------------
  if(argc < 1 && argc > 2){
    printf("Usage: directory\ndirectory pathname\n");
    exit(1);
  }
  //----------------------------------------------------------------------------
  //-----------------check to open current directory----------------------------
  if(argc == 1){
    // target directory is current working directory - check to see if can be opened
    if((dir = opendir(".")) == NULL){
      printf("Cannot open current directory.\n");
      exit(1);
    }
  }
  //----------------------------------------------------------------------------
  //-----------------check to open specified directory--------------------------
  if(argc == 2){
    // target directory is current working directory - check to see if can be opened
    if((dir = opendir(argv[1])) == NULL){
      printf("Cannot open specified directory.\n");
      exit(1);
    }
  }
  //----------------------------------------------------------------------------
  //----------------------begin processing--------------------------------------
  createBaseDir(); // create and check all resulting directories
  while((ent = readdir(dir)) != NULL){
    filename = ent->d_name;
    srcFile = malloc(sizeof(char) * strlen(ent->d_name));
    srcFile[0] = '\0';
    strcpy(srcFile, filename);  // take in filename and copy that onto sourcefile
    exte = filetype(filename); // find the file extension of the file
    if(exte != NULL){
      //------------------process mp3 files--------------------
      if(strcmp(exte, extArr[0]) == 0){
        filename[strlen(filename) - 4] = '\0'; // snip off .mp3 extension
        char ** mp3Arr = parseMP3(filename); // parse the mp3 file
        // create new directory foreach artist AND foreach album
        char * albumDir = createArtistDir(mp3Arr[0], mp3Arr[1]);
        destFolder = finalMusicDir(albumDir, mp3Arr[2], ".mp3");
        uhoh = rename(srcFile, destFolder); // move the source file to its current destination
        printf("%d\n", uhoh);
        albumDir[0] = '\0';
        free(albumDir);
        free(destFolder);
        free(mp3Arr); // free alllllll the mallocs
        }
      //------------------------------------------------------
      //------------------process mkv files-------------------
      if(strcmp(exte, extArr[1]) == 0){
        filename[strlen(filename) - 4] = '\0'; // snip off .mkv extension
        char ** mkvArr = parseMKV(filename); // parse the mkv file
        if(mkvArr[2] == NULL){
          char * yearDir = createMovieYearDir(mkvArr[0]);  // since this file is a movie file
          destFolder = finalMovieDir(yearDir, mkvArr[1], ".mkv");
          uhoh = rename(srcFile, destFolder);
          printf("%d\t%s\n", uhoh, strerror(errno));
          yearDir[0] = '\0';
          free(yearDir);
          free(destFolder);
        }
        if(mkvArr[2] != NULL){
          // create a sub directory for each series
          // then create subdirectory for each season
          // rename file inside movies/shows/series/season/episode-title.mkv
          char * seriesDir = createSeriesDir(mkvArr[0]);
          char * seasonDir = createSeasonDir(seriesDir, mkvArr[1]);
          destFolder = finalShowDir(seasonDir, mkvArr[2], mkvArr[3], ".mkv");
          uhoh = rename(srcFile, destFolder);
          printf("%d\t%s\n", uhoh, strerror(errno));
          seriesDir[0] = '\0';
          seasonDir[0] = '\0';
          free(seriesDir);
          free(seasonDir);
          free(destFolder);
        }
        free(mkvArr);
      }
      //------------------------------------------------------
      //--------------process docx/txt files-------------------
      if(strcmp(exte, extArr[2]) == 0 || strcmp(exte, extArr[3]) == 0){
        destFolder = finalOtherDir(srcFile, "documents/");
        uhoh = rename(srcFile, destFolder);
        printf("%d\t%s\n", uhoh, strerror(errno));
        free(destFolder);
      }
      //--------------process jpg/png files-------------------
      if(strcmp(exte, extArr[4]) == 0 || strcmp(exte, extArr[5]) == 0){
        destFolder = finalOtherDir(srcFile, "pictures/");
        uhoh = rename(srcFile, destFolder);
        printf("%d\t%s\n", uhoh, strerror(errno));
        free(destFolder);
      }
      //---------------process other files--------------------
      // TODO: get rid of .c, .h, .o, .exe, ., .stackdump extension comparsions
      if(strcmp(exte, extArr[0]) != 0 && strcmp(exte, extArr[1]) != 0 && strcmp(exte, extArr[2]) != 0
      && strcmp(exte, extArr[3]) != 0 && strcmp(exte, extArr[4]) != 0 && strcmp(exte, extArr[5]) != 0
      && strcmp(exte, ".c") != 0 && strcmp(exte, ".h") != 0 && strcmp(exte, ".o") != 0
      && strcmp(exte, ".exe") != 0 && strcmp(exte, ".") != 0 && strcmp(exte, ".stackdump") != 0 ) {
        destFolder = finalOtherDir(srcFile, "other/");
        uhoh = rename(srcFile, destFolder);
        // printf("%d\t%s\n", uhoh, strerror(errno));
        free(destFolder);
      }
      //------------------------------------------------------
    }
    free(srcFile);
  }
  closedir(dir); // close the directory
  //----------------------------------------------------------------------------
  return 0;
}
