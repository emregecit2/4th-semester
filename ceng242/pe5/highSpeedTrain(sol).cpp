#include <iostream>
#include <string>
#include "highSpeedTrain.h"

HighSpeedTrain::HighSpeedTrain(){
    from = "Florence";
    to = "Rome";
    eta = 90;
}


HighSpeedTrain::HighSpeedTrain(std::string from, std::string to, int eta){
    this->from = from;
    this->to = to;
    this->eta = eta;
}

HighSpeedTrain::HighSpeedTrain(const HighSpeedTrain &h){
    this->from = h.from;
    this->to = h.to;
    this->eta = h.eta + 60;
}


std::ostream &operator<<(std::ostream &output, const HighSpeedTrain &h){
    output << h.from << " -> " << h.to << " in " << h.eta << " mins.";
    return output;
}

std::string operator+(const HighSpeedTrain &h1, const HighSpeedTrain &h2){
    if (h1.to != h2.from){
        return "Transfer is not possible!";
    }
    return h1.from + " -> " + h1.to + " -> " + h2.to + " in " + std::to_string(h1.eta + h2.eta) + " mins.";
}

bool operator<(const HighSpeedTrain &h1, const HighSpeedTrain &h2){
    if (h1.from.compare(h2.from) < 0){
        return true;
    }else{
        if (h1.from.compare(h2.from) > 0){
            return false;
        }
        else{
            if(h1.to.compare(h2.to) < 0){
                return true;
            }
            else{
                if(h1.to.compare(h2.to) > 0){
                    return false;
                }
                else{
                    return h1.eta < h2.eta;
                }
            }
        }
    }
}

bool operator>(const HighSpeedTrain &h1, const HighSpeedTrain &h2){
    if (h1.from.compare(h2.from) > 0){
        return true;
    }else{
        if (h1.from.compare(h2.from) < 0){
            return false;
        }
        else{
            if(h1.to.compare(h2.to) > 0){
                return true;
            }
            else{
                if(h1.to.compare(h2.to) < 0){
                    return false;
                }
                else{
                    return h1.eta > h2.eta;
                }
            }
        }
    }
}
