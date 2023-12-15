//
// Created by Maggie Asare on 1/21/2022.
//
/**
 * Resources used for recursive brute force algorithm:
 * https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/
 */
#include <cstdio>
#include <vector>
#include <iterator>
#include <iostream>


#include "sorts.h"

using namespace std;

//++++++++++++++++ CONSTRUCTORS ++++++++++++++++
sorts::sorts() {
    wallLength = 0;
    numArtPieces = 0;
    bruteTotal = 0;
    highValueTotal = 0;
    customTotal = 0;
    currMax = 0;
    currLength = 0;

}// default: sorts()

sorts::sorts(int length, int pieces, vector<art> & artList) {
    wallLength = length;
    numArtPieces = pieces;
    myArt = &artList;
    bruteTotal = 0;
    highValueTotal = 0;
    customTotal = 0;
    currMax = 0;
    currLength = 0;
}//sorts(int, int, list<art> *)
//+++++++++++++++++ MUTATORS +++++++++++++++++
void sorts::setWallLength(int length) {
    wallLength = length;
}

void sorts::setNumArtPieces(int pieces) {
    numArtPieces = pieces;
}

void sorts::setList(vector<art> &artList) {
    myArt = &artList;
}
//+++++++++++++++++++++++++++ ACCESSORS +++++++++++++++
vector<art> *sorts::getList() {
    return myArt;
}

vector<art> *sorts::getBruteForce() {
    return &bruteForceList;
}

vector<art> *sorts::getHighValue() {
    return &highValueList;
}

vector<art> *sorts::getCustom() {
    return &customList;
}
//++++++++++++++++++++++++ SORTS +++++++++++++++++
int sorts::sortBruteForce() {
    //cout << "Wall Length: " << wallLength << endl;
    for(int combo = myArt->size(); combo > 0; combo--){
        printCombination(*myArt, myArt->size(), combo);
    }
   /*
    cout << "Brute Force Winner:" << endl;
    for(art item : bruteForceList)
        cout << item;
   */
    return bruteTotal;
}

int sorts::sortHighValue() {
    quicksort(*(myArt), 0, myArt->size() - 1);
    int totalP = 0;//total price of list
    int totalL = 0; // total length of list
    for(art item: *myArt){
        if(totalL+item.getWidth() <= wallLength) {
            highValueList.push_back(item);
            totalL += item.getWidth();
            totalP += item.getValue();
        }
    }
    return totalP;


}

int sorts::sortCustom() {
    quicksortC(*(myArt), 0, myArt->size() - 1);
    int totalP = 0;//total price of list
    int totalL = 0; // total length of list
    for(art item: *myArt){
        //cout << item;
        if(totalL+item.getWidth() <= wallLength) {
            customList.push_back(item);
            totalL += item.getWidth();
            totalP += item.getValue();
        }
    }
    return totalP;
}

//============= QUICK SORT LIST HELP
int sorts::partition(vector<art> &values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    art pivotValue = values[pivotIndex];
    int i = left, j = right;
    art temp;
    while(i <= j) {
        while(values[i] > pivotValue) {
            i++;
        }
        while(values[j] < pivotValue) {
            j--;
        }
        if(i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

void sorts::quicksort(vector<art> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(values, left, right);
        quicksort(values, left, pivotIndex - 1);
        quicksort(values, pivotIndex, right);
    }
}

int sorts::partitionC(vector<art> &values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    art pivotValue = values[pivotIndex];
    int i = left, j = right;
    art temp;
    while(i <= j) {
        while(values[i].getPPI() > pivotValue.getPPI()) {
            i++;
        }
        while(values[j].getPPI() < pivotValue.getPPI()) {
            j--;
        }
        if(i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

void sorts::quicksortC(vector<art> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = partitionC(values, left, right);
        quicksortC(values, left, pivotIndex - 1);
        quicksortC(values, pivotIndex, right);
    }
}
//=============== BRUTE FORCE EXHAUST ALL COMBINATIONS HELP
//Recursive implementation to finding all solutions
/**
 *
 * @param arr
 * @param n size of input array
 * @param r size of array to be printed
 */
void sorts::printCombination(vector<art>& arr, int n, int r)
{
    // A temporary array to store
    // all combination one by one
    vector<art> data;
    data.resize(r);



    // Print all combination using
    // temporary array 'data[]'
    combinationUtil(arr, n, r, 0, data, 0);
}

/* arr[] ---> Input Array
n ---> Size of input array
r ---> Size of a combination to be printed
index ---> Current index in data[]
data[] ---> Temporary array to store current combination
i ---> index of current element in arr[] */
void sorts::combinationUtil(vector<art>& arr, int n, int r,
                     int index,vector<art>& data, int i)
{
    // Current combination is ready, print it
    if (index == r)
    {
       currMax = 0;
        currLength = 0;
        for (int j = 0; j < r; j++) {
            //cout << data[j] << " ";
            currMax += data[j].getValue();
            currLength += data[j].getWidth();
        }

        //cout <<"currMax: " << currMax << endl;
        //cout << "currLength: " << currLength << endl;
        //when a new max price has been reached that can feasibly fit on the wall
        if (currMax >= bruteTotal && currLength <= wallLength) {
            bruteTotal = currMax;
            bruteForceList.clear();
            for(art item: data){
                bruteForceList.push_back(item);
            }
            //bruteForceList = data;
            //cout << "new max found!! " << endl;

        }


        //currMax = 0;
        //currLength = 0;

        //cout << endl;

        //currMax = 0;
        //currLength = 0;
        return;
    }

    // When no more elements are there to put in data[]
    if (i >= n) {
        currMax = 0;
        currLength = 0;
        return;
    }

    // current is included, put next at next location
    data[index] = arr[i];
    //currMax += arr[i].getValue();//add art price to total price of current combo
    //currLength += arr[i].getWidth();
    combinationUtil(arr, n, r, index + 1, data, i + 1);

    // current is excluded, replace it with next (Note that
    // i+1 is passed, but index is not changed)
    combinationUtil(arr, n, r, index, data, i+1);
}
