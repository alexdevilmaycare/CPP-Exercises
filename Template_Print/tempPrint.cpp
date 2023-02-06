#include<iostream>
#include<string>
#include<iterator>
#include<vector>
#include<array>
#include<forward_list>
#include<list>

template <typename IterableType>

void Print (const IterableType & collection, const std::string & delimiter) {
    auto end = collection.end(); 
    auto nextEl = collection.begin();
    for ( const auto & item: collection ) {
        nextEl = std::next(nextEl);     
        if (end == nextEl) {
            std::cout << item << "\n"; 
            continue;
        }
        std::cout << item << delimiter; 
    }
}

int main ()
{
    std::vector<int> coll1 = { 1, 20, 20 };
    std::string charCol = "Hellow, world!"; 
    std:: array <int, 4> thirdCol = {-100, 100, 400}; 
    std:: forward_list <int> fourthCollection = { 1, 2, 3, 4, 5 }; 
    std:: list <int> fifthCollection = { 300, 400, 500, 1000 }; 
    Print (coll1, "+"); 
    Print (charCol, "__");
    Print(thirdCol, "+"); 
    Print (fourthCollection, "*"); 
    Print (fifthCollection, "+++");
    return 0; 
}