#include <iostream>
#include <map>
#include <vector>
#include <tuple>   
#include <string> 
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagers; // change to tuple
     // data: friendship level, species, catchphrase
    villagers["Audie"]   = make_tuple(7,  string("Wolf"),     string("Yeah!")); 
    villagers["Raymond"] = make_tuple(8,  string("Cat"),      string("Nice!")); 
    villagers["Marshal"] = make_tuple(5,  string("Squirrel"), string("Oh?"));   

    // access the map using a range-based for loop
    cout << "Villager details (range-based for loop):" << endl;                  
    for (auto p : villagers) {       // print: friendship level, species, catchphrase                                              
        cout << p.first << " [" << get<0>(p.second) << ", " << get<1>(p.second) << ", " << get<2>(p.second) << "]\n";                                
}

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerColors.begin(); 
                                               it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagers.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;
    
    return 0;
}
