//
// Created by robot on 1/21/2022.
//

#ifndef PA01_FILEIO_H
#define PA01_FILEIO_H
#include <string>
#include <fstream>
#include <vector>
#include "art.h"

using namespace std;

class fileio {
private:
    int wallLength;
    int numArtPieces;
    string file;
    string name;
    ifstream inFS;
    ofstream outFS;
    vector<art>* myArt;
    vector<art>* bruteForceList;
    vector<art>* highValueList;
    vector<art>* customList;

public:
    //++++++++++++++++++ CONSTRUCTORS +++++++++++
    fileio();
    fileio(vector<art>&,string);
    //+++++++++++++++++ MUTATORS ++++++++++++++++
    void setFile(string);
    void setList(vector<art>&);
    //+++++++++++++++++ ACCESSORS +++++++++++++++
    int getWallLength() {return wallLength;}
    int getNumArtPieces(){return numArtPieces;}


    //+++++++++++++++++ FILE I/O ++++++++++++++++
    void readFile();
    void writeBruteForce(int, vector<art>*);
    void writeHighValue(int, vector<art>*);
    void writeCustom(int, vector<art>*);
};


#endif //PA01_FILEIO_H
