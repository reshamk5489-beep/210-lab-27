#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerDetails;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerDetails["Drago"] = {5, "Alligator", "Snap to It!"};
    villagerDetails["Kyle"] = {10, "Wolf", "Hubba hubba!"};
    villagerDetails.insert({"Raymond", {8, "Cat", "Nice fit"}});

    // access the map using a range-based for loop
    cout << "Villagers and their details (range-based for loop):" << endl;
    for (const auto& [name, details] : villagerDetails) 
    {
        auto [friendship, species, catchphrase] = details;       
        cout << name << " [" << friendship << ", " << species << ", " << catchphrase << "]";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagerDetails.begin(); 
                                               it != villagerDetails.end(); ++it) 
    {
        string name = it->first; // key
        tuple<int, string, string> details = it->second; // value

        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerDetails.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerDetails.find(searchKey);
    if (it != villagerDetails.end()) {  // the iterator points to beyond the end of the map
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