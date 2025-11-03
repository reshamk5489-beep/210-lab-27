#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int main() 
{
    // declarations
    map<string, tuple<int, string, string>> villagerDetails; // Define map of string and tuple

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerDetails["Drago"] = {5, "Alligator", "Snap to It!"};
    villagerDetails["Kyle"] = {10, "Wolf", "Hubba hubba!"};
    villagerDetails.insert({"Raymond", {8, "Cat", "Nice fit"}});

    int choice;
    string villagerName;

    while (true)
    {
        cout << "1. Increase Friendship" << endl;
        cout << "2. Decrease Friendship" << endl;
        cout << "3. Search for Villager" << endl;
        cout << "4. Exit" << endl;

        cin >> choice;
        if (choice == 4)
        {
            break;
        }

        cout << endl;
        cout << "Please enter villager's name: ";
        cin >> villagerName;

        auto it = villagerDetails.find(villagerName);
        if (it == villagerDetails.end()) 
        {  
            cout << endl << villagerName << " not found." << endl << endl;
        }
        else
        {
            switch (choice)
            {
                case 1:
                {
                    if (get<0>(it->second) < 10)
                    {
                        get<0>(it->second)++; 
                    }

                    auto [friendship, species, catchphrase] = it->second;
                    cout << "\n" << villagerName << "'s details: ";
                    cout << "[" << friendship << ", " << species << ", " << catchphrase << "]";
                    cout << endl;
                    cout << endl;
        
                    break;
                }
                case 2:
                {
                    if (get<0>(it->second) > 0)
                    {
                        get<0>(it->second)--;
                    }

                    auto [friendship, species, catchphrase] = it->second;
                    cout << "\n" << villagerName << "'s details: ";
                    cout << "[" << friendship << ", " << species << ", " << catchphrase << "]";
                    cout << endl;
                    cout << endl;
                                       
                    break;
                }
                case 3:
                {
                    auto [friendship, species, catchphrase] = it->second;
                    cout << "\nFound " << villagerName << "'s details: ";
                    cout << "[" << friendship << ", " << species << ", " << catchphrase << "]";
                    cout << endl;
                    cout << endl;

                    break;
                }
            }
        }
    }

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerDetails.size() << endl;
    villagerDetails.clear();
    cout << "Size after clear: " << villagerDetails.size() << endl;

    return 0;
}