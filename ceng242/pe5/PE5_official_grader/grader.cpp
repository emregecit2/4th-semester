#include <iostream>
#include <fstream>
#include <string>
#include "highSpeedTrain.h"

std::ofstream resultFile;

void test1(){
    HighSpeedTrain *h = new HighSpeedTrain();
    resultFile << h->getFrom() << std::endl;
    resultFile << h->getTo() << std::endl;
    resultFile << h->getETA();
}

void test2(){
    HighSpeedTrain *h = new HighSpeedTrain("Turin", "Napoli", 90);
    resultFile << h->getFrom() << std::endl;
    resultFile << h->getTo() << std::endl;
    resultFile << h->getETA();
}

void test3(){
    HighSpeedTrain *h = new HighSpeedTrain("Napoli", "Turin", 90);
    HighSpeedTrain h2 = *h;
    resultFile << h2.getFrom() << std::endl;
    resultFile << h2.getTo() << std::endl;
    resultFile << h2.getETA();
}

void test4(){
    HighSpeedTrain *h = new HighSpeedTrain("Florence", "Turin", 175);
    HighSpeedTrain h2 = *h;
    resultFile << h2.getFrom() << std::endl;
    resultFile << h2.getTo() << std::endl;
    resultFile << h2.getETA();
}

void test5(){
    HighSpeedTrain *h = new HighSpeedTrain("Turin", "Napoli", 90);
    resultFile << *h;
}

void test6(){
    HighSpeedTrain *h = new HighSpeedTrain("Florence", "Turin", 175);
    resultFile << *h;
}

void test7(){
    HighSpeedTrain *h = new HighSpeedTrain("Turin", "Florence", 175);
    HighSpeedTrain *h2 = new HighSpeedTrain("Florence", "Rome", 97);
    resultFile << (*h) + (*h2);
}

void test8(){
    HighSpeedTrain *h = new HighSpeedTrain("Milan", "Turin", 60);
    HighSpeedTrain *h2 = new HighSpeedTrain("Florence", "Rome", 115);
    resultFile << (*h) + (*h2);
}

void test9(){
    HighSpeedTrain *h = new HighSpeedTrain("Turin", "Milan", 60);
    HighSpeedTrain *h2 = new HighSpeedTrain("Milan", "Bologna", 74);
    resultFile << (*h) + (*h2);
}

void test10(){
    HighSpeedTrain *h = new HighSpeedTrain("Turin", "Milan", 60);
    HighSpeedTrain *h2 = new HighSpeedTrain("Florence", "Rome", 115);
    resultFile << std::boolalpha << (*h < *h2);
}

void test11(){
    HighSpeedTrain *h = new HighSpeedTrain("Florence", "Milan", 114);
    HighSpeedTrain *h2 = new HighSpeedTrain("Florence", "Rome", 96);
    resultFile << std::boolalpha;
    resultFile << std::boolalpha << (*h < *h2);
}

void test12(){
    HighSpeedTrain *h = new HighSpeedTrain("Turin", "Milan", 77);
    HighSpeedTrain *h2 = new HighSpeedTrain("Turin", "Milan", 59);
    resultFile << std::boolalpha;
    resultFile << std::boolalpha << (*h < *h2);
}

void test13(){
    HighSpeedTrain *h = new HighSpeedTrain("Turin", "Milan", 60);
    HighSpeedTrain *h2 = new HighSpeedTrain("Bologna", "Rome", 123);
    resultFile << std::boolalpha;
    resultFile << std::boolalpha << (*h > *h2);
}

void test14(){
    HighSpeedTrain *h = new HighSpeedTrain("Bologna", "Rome", 123);
    HighSpeedTrain *h2 = new HighSpeedTrain("Bologna", "Florence", 37);
    resultFile << std::boolalpha;
    resultFile << std::boolalpha << (*h > *h2);
}

void test15(){
    HighSpeedTrain *h = new HighSpeedTrain("Bologna", "Florence", 37);
    HighSpeedTrain *h2 = new HighSpeedTrain("Bologna", "Florence", 97);
    resultFile << std::boolalpha;
    resultFile << std::boolalpha << (*h > *h2);
}



int main(int argc, char *argv[]){
    int caseIndex = std::stoi(argv[1]);
    resultFile.open ("tempout");
    
    switch(caseIndex){
        case 1:
            test1();
            break;
        case 2:
            test2();
            break;
        case 3:
            test3();
            break;
        case 4:
            test4();
            break;
        case 5:
            test5();
            break;
        case 6:
            test6();
            break;
        case 7:
            test7();
            break;
        case 8:
            test8();
            break;
        case 9:
            test9();
            break;
        case 10:
            test10();
            break;
        case 11:
            test11();
            break;
        case 12:
            test12();
            break;
        case 13:
            test13();
            break;
        case 14:
            test14();
            break;
        case 15:
            test15();
            break;
        default:
            break;
    }
    resultFile.close();
    return 0;
}