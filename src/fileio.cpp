//
// Created by robot on 1/21/2022.
//
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <exception>
#include "art.h"
#include "fileio.h"

using namespace std;

fileio::fileio() {
    wallLength = 0;
    numArtPieces = 0;
    file = "";
    name = "";

}

fileio::fileio(vector<art> & artList, string fileName) {
    wallLength = 0;
    numArtPieces = 0;
    file = fileName;
    name = file.substr(6,file.length()-9);
    myArt = &artList;
}

void fileio::setFile(string fileName) {
     file = fileName;
}

void fileio::setList(vector<art> &) {

}

void fileio::readFile() {
    int temp1;
    int temp2;
    int temp3;
    int temp4;
    inFS.open(file);
    if(!inFS.is_open()) {
        cout << "Did not open file" << endl;
        //throw ios_base::failure("bad file name "+file);
    }
    inFS >> wallLength; //cout << wallLength <<endl;
    inFS >> temp1;
    inFS >> numArtPieces;
    for (int i = 0; i<numArtPieces; i++){
        inFS >> temp1;//id
        inFS >> temp2;//value
        inFS >> temp3;//width
        inFS >>temp4;//height
        art piece(temp1, temp2, temp3,temp4, (1.0*temp2)/temp3);
        myArt->push_back(piece);
    }
    inFS.close();

}

void fileio::writeBruteForce( int totalVal, vector<art>* artList) {
    //cout << "input/"+name+"-bruteforce.txt\n";
    outFS.open("input/"+name+"-bruteforce.txt");
   if(!outFS.is_open()) {
       cout << "failed to open bruteforce out file" << endl;
       //throw ios_base::failure("bad file name");
   }
   outFS << totalVal << endl;
   for(auto item : *(artList))
       outFS << item << endl;
   outFS.close();
}

void fileio::writeHighValue( int totalVal, vector<art>* artList) {
    //cout << "input/"+name+"-highvalue.txt\n";
    outFS.open("input/"+name+"-highvalue.txt");
    if(!outFS.is_open()) {
        cout << "failed to open highvalue out file" << endl;
        //throw ios_base::failure("bad file name");
    }
    outFS << totalVal << endl;
    for(auto item : *(artList))
        outFS << item << endl;
    outFS.close();
}

void fileio::writeCustom( int totalVal, vector<art>* artList) {
    //cout << "input/"+name+"-custom.txt\n";
    outFS.open("input/"+name+"-custom.txt");
    if(!outFS.is_open()) {
        cout << "failed to open custom out file" << endl;
        //throw ios_base::failure("bad file name");
    }
    outFS << totalVal << endl;
    for(auto item : *(artList))
        outFS << item << endl;
    outFS.close();
}


