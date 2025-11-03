#include <iostream>
#include <map>
#include <vector>
#include <tuple>   
#include <string> 
#include <limits>
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
    cout << "\nVillager details (iterators):" << endl;
    for (map<string, tuple<int,string,string>>::iterator it = villagers.begin();
        it != villagers.end(); ++it) {
        // print: friendship, species, catchphrase
        cout << it->first << " [" << get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second) << "]\n";
}


    // delete an element
    villagers.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagers.find(searchKey);
    if (it != villagers.end()) {  // the iterator points to beyond the end of the map
        // if searchKey is not found                             
        cout << "\nFound " << searchKey << ": ["
         << get<0>(it->second) << ", "   // friendship
         << get<1>(it->second) << ", "   // species
         << get<2>(it->second) << "]\n"; // catchphrase
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;
    
    // ======================== M3 =============================
    while (true) {  // the menu
        cout << "\nMenu:\n";
        cout << "1. Increase Friendship\n";
        cout << "2. Decrease Friendship\n";
        cout << "3. Search for Villager\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
    
        int choice;

        if (!(cin >> choice)) {          // make sure read menu number safely
        cin.clear();                 // reset fail state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // drop bad input
        cout << "Invalid input.\n";
        continue;                    // ask again
    }
    // ================== case 1 increase================
        if (choice == 1) { 
        string name;
        cout << "Name to increase: ";
        getline(cin, name); // read the whole line

        auto it2 = villagers.find(name); // try to find this name in the map
        if (it2 == villagers.end()) {
            cout << "Not found.\n"; // no such villager
        } else {
            int f = get<0>(it2->second); // current friendship
            if (f < 10) f++;             // keep it within 0..10
            get<0>(it2->second) = f;     // write it back
            cout << "OK: " << name << " -> " << f << "\n";
        }

        // show everything after this action
        cout << "Villager details:\n";
        for (map<string, tuple<int,string,string>>::iterator itp = villagers.begin();
            itp != villagers.end(); ++itp) {
            cout << itp->first << " [" << get<0>(itp->second) << ", " << get<1>(itp->second) << ", " << get<2>(itp->second) << "]\n";
        }
    }
    // ================== case 2 decrease================
        else if (choice == 2) { 
            string name;
            cout << "Name to decrease: ";
            getline(cin, name); // read the whole line

            auto it2 = villagers.find(name); // find by name
        if (it2 == villagers.end()) {
            cout << "Not found.\n"; }// no such villager
        else {
            int f = get<0>(it2->second); // current friendship
            if (f > 0) f--;              // don't go below 0
            get<0>(it2->second) = f;     // write it back
            cout << "OK: " << name << " -> " << f << "\n";}

        // show everything after this action
        cout << "Villager details:\n";
        for (map<string, tuple<int,string,string>>::iterator itp = villagers.begin(); itp != villagers.end(); ++itp) {
            cout << itp->first << " ["<< get<0>(itp->second) << ", " << get<1>(itp->second) << ", " << get<2>(itp->second) << "]\n";}
    }
//==================case 3 Search for Villager =======================
        else if (choice == 3) { // search
        string name;
        cout << "Name to search: ";
        getline(cin, name);                     // read a whole line

        auto it2 = villagers.find(name);       // look up by name
        if (it2 == villagers.end()) {
            cout << "Not found.\n"; }           // no such villager
        else {    // print this one
            cout << it2->first << " [" << get<0>(it2->second) << ", " << get<1>(it2->second) << ", " << get<2>(it2->second) << "]\n";
    }

        // print all after the action 
        cout << "Villager details:\n";
        for (map<string, tuple<int,string,string>>::iterator itp = villagers.begin(); itp != villagers.end(); ++itp) {
            cout << itp->first << " [" << get<0>(itp->second) << ", " << get<1>(itp->second) << ", " << get<2>(itp->second) << "]\n";
        }
    }
//========== case 4 exit==========
        else if (choice == 4) { // exit
        cout << "Bye.\n";
        break;
    }
}

    return 0;
}
