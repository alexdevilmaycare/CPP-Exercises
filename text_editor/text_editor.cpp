#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<deque>
#include<iterator>


std::list <std::string> parseTextFileStrings () {
    std::list <std::string> collection; 
    std::string userInput;
    while (std::getline (std::cin, userInput))
    {
        collection.push_back(userInput);
        if (userInput.empty()) {
           break;  
        }
        
    }
    return collection;   
}

std::vector<std::string> parsedUserCommands () {
    std::vector <std::string> collection; 
    std::string userInput;
    while (std::getline (std::cin, userInput))
    {
        collection.push_back(userInput);
        if (userInput.empty()) {
           break;  
        }
       
    }
    return collection;   
}




void printCollection (const std::list<std::string> & coll) {
    for (const auto & item: coll) {
        std::cout << item << "\n"; 
    }
}

void transformList (std::list<std::string> & collection, const std::vector<std::string> & commands) {
      auto iter = collection.begin();
      std::vector<std::string> buffer; 
      for (const auto & comm: commands) {
            if (comm == "Down") {
                if (std::next(iter) != collection.end()) {
                    iter = std::next(iter); 
                    continue;
                }
            }
            if (comm == "Up") {
                if (iter != collection.begin()) {
                    iter = std::prev(iter);
                    continue;
                }
            }
            if (comm == "Ctrl+X") {
                std::string line = * iter; 
                if (line.empty()) {
                    continue; 
                }
                buffer.clear(); 
                buffer.push_back(line);
                iter = collection.erase(iter); 
                continue;
            }
            if (comm == "Ctrl+V") {
                if ( buffer.empty()) {
                       continue; 
                } 
                    std:: string last = buffer.back(); 
                    // auto previous = std::prev (iter); 
                    collection.insert(iter, last);
            }

      }
}



int main () {
    std::list <std::string> textFileStrings = parseTextFileStrings(); 
    std:: vector <std::string> commands = parsedUserCommands(); 
    transformList (textFileStrings, commands); 
    printCollection(textFileStrings); 
    return 0;  
}