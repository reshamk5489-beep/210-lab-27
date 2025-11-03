#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerDetails; // Define map of string and tuple

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerDetails["Drago"] = {5, "Alligator", "Snap to It!"};
    villagerDetails["Kyle"] = {10, "Wolf", "Hubba hubba!"};
    villagerDetails.insert({"Raymond", {8, "Cat", "Nice fit"}});

    int choice;
    string villagerName;
    bool isExit = false;

    cout << "1. Increase Friendship" << endl;
    cout << "2. Decrease Friendship" << endl;
    cout << "3. Search for Villager" << endl;
    cout << "4. Exit" << endl;

    cin >> choice;

    while (isExit == false)
    {
        switch (choice)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                cout << "Please enter villager's name: ";
                cin >> villagerName;;
                auto it = villagerDetails.find(villagerName);
                if (it != villagerDetails.end()) {  // the iterator points to beyond the end of the map
                                                // if searchKey is not found
                    cout << "\nFound " << villagerName << "'s details: ";
                    auto [friendship, species, catchphrase] = it->second;
                    cout << " [" << friendship << ", " << species << ", " << catchphrase << "]";
                    cout << endl;
                } else
                    cout << endl << villagerName << " not found." << endl;
                break;
            case 4:
                isExit = true;
                break;
        }
    }

    // access the map using a range-based for loop
    cout << "Villagers and their details (range-based for loop):" << endl;
    for (const auto& [name, details] : villagerDetails) 
    {
        auto [friendship, species, catchphrase] = details;       
        cout << name << " [" << friendship << ", " << species << ", " << catchphrase << "]";
        cout << endl;
    }

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerDetails.size() << endl;
    villagerDetails.clear();
    cout << "Size after clear: " << villagerDetails.size() << endl;

    return 0;
}