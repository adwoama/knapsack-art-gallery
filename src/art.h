//
// Created by robot on 1/21/2022.
//

#ifndef PA01_ART_H
#define PA01_ART_H

#include <ostream>

using namespace std;

class art {
private:
    int id;
    int value;
    int width;
    int height;
    double ppi;//price per inch

public:
    //++++++++++++++ CONSTRUCTORS +++++++++++++
    art();
    art(int,int,int,int, double);
    //++++++++++++++ MUTATORS ++++++++++++++++
    void setId(int);
    void setValue(int);
    void setWidth(int);
    void setHeight(int);
    void setPPI(int);
    //++++++++++++++ ACCESSORS ++++++++++++++
    int getId();
    int getValue();
    int getWidth();
    int getHeight();
    int getPPI();
    //+++++++++++++ OTHER +++++++++++++++++++
    int comparePPI(art);
    bool operator >(art);
    bool operator < (art);
    bool operator == (art);
    art operator = (art);
    friend ostream & operator<<(ostream &output, const art &A) {
        output << A.id <<" " << A.value << " " << A.width << " " << A.height;//" " << A.ppi << endl;
        return output;
    }

};


#endif //PA01_ART_H
