#include<iostream>
#include<deque>
#include<string>
#include<sstream>
#include<utility>
#include<iterator>

void PrintTrain (const std::deque<int> & train) {
    if (train.size() == 0) {
        std::cout << "\n"; 
        return; 
    }
    for (const auto & wagon: train) {
        std::cout << wagon << " ";
    }
    std::cout << "\n"; 

}

std::pair<std::string, int> parseString (const std::string & str) {
    std::string command; 
    int numberofWagons; 
    std:: stringstream sstrm (str);
    sstrm >> command; 
    sstrm.ignore(1); 
    sstrm >> numberofWagons; 
    std::pair<std::string, int> commandPair (command, numberofWagons);
    return commandPair; 
}


void ModifyTrain (std::deque<int> & train, const std::string & userCommand, int & wagNumb) {
    
    if (userCommand == "+left") {
        train.push_front(wagNumb);
        return; 
    }
    if (userCommand == "+right") {
        train.push_back(wagNumb);
        return; 
    }
    size_t containerSize = train.size(); 
    size_t numberofItmestoBeRemoved = static_cast<size_t> (wagNumb); 
    if (userCommand == "-right") {
        
         if (containerSize <= numberofItmestoBeRemoved) {
            train.clear(); 
            return; 
         }
        size_t newSize = containerSize - numberofItmestoBeRemoved; 
        train.resize(newSize); 
    }
    if (userCommand == "-left") {
        if (containerSize <= numberofItmestoBeRemoved) {
            train.clear();
            return; 
        }
        train.erase( train.begin(), train.begin() + numberofItmestoBeRemoved );       
    }
}



void MakeTrain() {
    std::deque<int> train;
    std::string userCommand; 
    while (std::getline(std::cin, userCommand)) {
        if (userCommand.empty()) {
            break;
        }
        std::pair<std::string, int> parsedInput = parseString(userCommand);
        std::string command = parsedInput.first; 
        int wagons = parsedInput.second; 
        ModifyTrain(train, command, wagons);
    }
    PrintTrain(train); 
}

int main () {
    MakeTrain(); 
    return 0;  
}



