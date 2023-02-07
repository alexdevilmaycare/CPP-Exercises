#include<deque>
#include<string>
#include<iostream>
#include<vector>

void updateStackOfPapers ( std::deque <std::string> & Papers, const std::string lastName, 
                           const std:: string Direction ) {
    if (Direction == "top") {
        Papers.push_front(lastName);
    } else if (Direction == "bottom") {
        Papers.push_back (lastName);
    }
                           }

void fillStudentPapers ( int numberofInputs, std::deque <std::string> & Papers ) {
    for ( int i = 0; i != numberofInputs; i +=1 ) {
        std:: string studentLastName; 
        std:: string Direction; 
        std::cin >> studentLastName >> Direction; 
        updateStackOfPapers(Papers, studentLastName, Direction); 
    }
}

void PrintName ( const std::deque<std::string> & Papers, int numberOfOutputs ) {
    std::vector <size_t> positions; 
    for ( int i = 0; i != numberOfOutputs; i +=1 ) {
        size_t idx; 
        std::cin >> idx;
        positions.push_back(idx-1);  
    }
    for (const auto & pos: positions) {
        std::cout << Papers[pos] << "\n";
    }
}


int main () 
{
    std::deque <std::string> studentPapers;  
    int numberofInputs; 
    std::cin >> numberofInputs; 
    fillStudentPapers (numberofInputs, studentPapers); 
    int numberOfOutputs; 
    std::cin >> numberOfOutputs; 
    PrintName(studentPapers, numberOfOutputs); 
    return 0; 
}