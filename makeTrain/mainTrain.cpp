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
    auto iter = train.begin();
    for (size_t i = 0; i != train.size(); ++ i) {
        auto next = std::next(iter); 
        std::string delim = next == train.end()? "\n":" ";
        iter = std::next(iter);
        std::cout << train[i] << delim; 
    }
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



/* #include<deque>
#include<iostream>

void Print ( const std::deque <int> & collection ) {
    for ( const auto & item: collection ) {
        std::cout << item << " "; 
    }
    std::cout << "\n";
}

int main () {
    std::deque <int> queuedCollection = {1, 2, 3, 4, 5};
    Print(queuedCollection); 
    queuedCollection.resize(3);
    Print(queuedCollection); 
    return 0; 
} */ 