//
// Created by robot on 1/21/2022.
//

#include "art.h"

using namespace std;

art::art() {
    id = 0;
    value = 0;
    width = 0;
    height = 0;
    ppi = 0;

}
art::art(int a, int b, int c, int d, double e) {
    id = a;
    value = b;
    width = c;
    height = d;
    ppi = e;
}

void art::setId(int a) {
    id = a;
}// setId

void art::setValue(int a) {
    value = a;
}//setValue

void art::setWidth(int a) {
    width = a;
}//setWidth

void art::setPPI(int a) {
    ppi = a;
}//setPPI

int art::getId() {
    return id;
}//getID

int art::getValue() {
    return value;
}//getValue

int art::getWidth() {
    return width;
}//getWidth

int art::getPPI() {
    return ppi;
}//getPPI

int art::comparePPI(art other) {
    if (ppi > other.ppi)
        return 1;
    else if (ppi == other.ppi)
        return 0;
    else
        return -1;
}

bool art::operator>(art other) {
    if (value > other.value)
        return true;
    else
        return false;
}

bool art::operator<(art other) {
    if(value < other.value)
        return true;
    else
        return false;
}

bool art::operator==(art other) {
    if(value == other.value)
        return  true;
    else
        return false;
}

art art::operator=(art copy) {
    id = copy.id;
    value = copy.value;
    width = copy.width;
    height = copy.height;
    ppi = copy.ppi;
    return copy;
}








//comparePPI
