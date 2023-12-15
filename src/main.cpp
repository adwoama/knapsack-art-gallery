//
// Created by robot on 1/21/2022.
//

#include "fileio.h"
#include "art.h"
#include "sorts.h"
#include <vector>
#include <iostream>
#include <string>
#include <chrono>

using namespace std;

int main(int argc, char** argv){
    if(argc != 2){
        cout << "This program is meant to be run with 1 argument." <<endl;
        cout << "The argument should be a string holding the name of the input file." << endl;
        cout << "Please enter the correct argument and try again." << endl;
        return 1;
    }//if wrong number of arguments entered.
    //create a start and end time_point object
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    int numArtPieces;
    int wallLength;
    int brutePrice;
    int highValuePrice;
    int customPrice;
    vector <art> masterList;
    string fileName = argv[1]; //cout << fileName << endl;

    fileio fileReader(masterList,"input/"+fileName);
    fileReader.readFile();
    numArtPieces = fileReader.getNumArtPieces();
    wallLength = fileReader.getWallLength();
    sorts sorted(wallLength, numArtPieces, masterList);

    //get the current time, run the algo, then get the current time again
    start = std::chrono::high_resolution_clock::now();//TODO @Timing
    highValuePrice = sorted.sortHighValue();
    end = std::chrono::high_resolution_clock::now();//TODO @Timing
    //calculate the duration between start and end and print to the terminal
    std::chrono::duration<double> time_in_seconds = end - start;//TODO @Timing
    std::cout << std::fixed << "High Value Duration: " << time_in_seconds.count() << std::endl;//TODO @Timing
    /*print high value sort
     for (auto const &i: masterList) {
        std::cout << i << std::endl;
    }
     */

    //get the current time, run the algo, then get the current time again
    start = std::chrono::high_resolution_clock::now();//TODO @Timing
    customPrice = sorted.sortCustom();
    end = std::chrono::high_resolution_clock::now();//TODO @Timing
    //calculate the duration between start and end and print to the terminal
     time_in_seconds = end - start;//TODO @Timing
    std::cout << std::fixed << "Custom Duration: " << time_in_seconds.count() << std::endl;//TODO @Timing
    /*print custom sort
    for (auto const &i: masterList) {
        std::cout << i << std::endl;
    }
    */

    //get the current time, run the algo, then get the current time again
    start = std::chrono::high_resolution_clock::now();//TODO @Timing
    brutePrice = sorted.sortBruteForce();
    end = std::chrono::high_resolution_clock::now();
    //calculate the duration between start and end and print to the terminal
    time_in_seconds = end - start;//TODO @Timing
    std::cout << std::fixed << "Brute Force Duration: " << time_in_seconds.count() << std::endl;//TODO @Timing

    //write output files
    fileReader.writeBruteForce(brutePrice,sorted.getBruteForce());
    fileReader.writeHighValue(highValuePrice,sorted.getHighValue());
    fileReader.writeCustom(customPrice,sorted.getCustom());

    return 0;
}