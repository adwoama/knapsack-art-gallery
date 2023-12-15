//
// Created by Maggie Asare on 1/21/2022.
//

#ifndef PA01_SORTS_H
#define PA01_SORTS_H
#include<vector>
#include "art.h"

using namespace std;

class sorts {
private:
    int wallLength;
    int numArtPieces;
    vector<art>* myArt;
    vector<art> bruteForceList;
    vector<art> highValueList;
    vector<art> customList;
    int bruteTotal;
    int highValueTotal;
    int customTotal;
    int currMax;
    int currLength;
public:
    //++++++++++++++++++ CONSTRUCTORS +++++++++++
    sorts();
    sorts(int, int, vector<art>&);
    //+++++++++++++++++= MUTATORS +++++++++++++
    void setWallLength(int);
    void setNumArtPieces(int);
    void setList(vector<art>&);
    //++++++++++++++++++ACCESSORS ++++++++++++++
    vector<art>* getList();
    vector<art>* getBruteForce();
    vector<art>* getHighValue();
    vector<art>* getCustom();
    //++++++++++++++++++ SORTS +++++++++++++++++
    int sortBruteForce();
    int sortHighValue();
    int sortCustom();

    int partition(vector<art> &values, int left, int right);
    void quicksort(vector<art> &values, int left, int right);

    int partitionC(vector<art> &values, int left, int right);
    void quicksortC(vector<art> &values, int left, int right);
    //++++++++++++++++ RECURSIONS ++++++++++++++++++
    void printCombination(vector<art>& arr, int n, int r);
    void combinationUtil(vector<art>& arr, int n, int r,
                                int index, vector<art>& data, int i);

};


#endif //PA01_SORTS_H
