#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int main() 
{
    // declarations
    map<string, tuple<int, string, string>> villagerDetails; // Define map of string and tuple

    int choice; // user choice
    string villagerName;
    int friendship;
    string species;
    string catchphrase;

    while (true)
    {
        cout << "1. Add Villager" << endl;
        cout << "2. Delete Villager" << endl;
        cout << "3. Increase Friendship" << endl;
        cout << "4. Decrease Friendship" << endl;
        cout << "5. Search for Villager" << endl;
        cout << "6. Exit" << endl << endl;

        cout << "Enter Choice: ";
        cin >> choice;
        if (choice == 6)
        {
            break;
        }
        
        switch (choice)
        {
            case 1:
            {
                cout << "Villager name: ";
                cin >> villagerName;
                cout << "Friendship level: ";
                cin >> friendship;
                cout << "Species: ";
                cin >> species;
                cout << "Catchphrase: ";
                cin.ignore();
                getline(cin, catchphrase);

                villagerDetails.insert({villagerName, {friendship, species, catchphrase}});

                cout << villagerName << " added." << endl << endl;
    
                break;
            }
            case 2:
            {
                cout << "Villager name: ";
                cin >> villagerName;

                villagerDetails.erase(villagerName);

                cout << villagerName << " deleted." << endl << endl;
                                    
                break;
            }
            case 3:
            {
                cout << "Villager name: ";
                cin >> villagerName;
                
                auto it = villagerDetails.find(villagerName);
                if (it == villagerDetails.end()) 
                {  
                    cout << villagerName << " not found." << endl << endl;
                }
                else
                {
                    if (get<0>(it->second) < 10)
                    {
                        get<0>(it->second)++; 
                    }

                    auto [friendship, species, catchphrase] = it->second;
                    cout << villagerName << "'s details: ";
                    cout << "[" << friendship << ", " << species << ", " << catchphrase << "]";
                    cout << endl;
                    cout << endl;
                }

                break;
            }
            case 4:
            {
                cout << "Villager name: ";
                cin >> villagerName;

                auto it = villagerDetails.find(villagerName);
                if (it == villagerDetails.end()) 
                {  
                    cout << villagerName << " not found." << endl << endl;
                }
                else
                {
                    if (get<0>(it->second) > 0)
                    {
                        get<0>(it->second)--;
                    }

                    auto [friendship, species, catchphrase] = it->second;
                    cout << villagerName << "'s details: ";
                    cout << "[" << friendship << ", " << species << ", " << catchphrase << "]";
                    cout << endl;
                    cout << endl;
                }

                break;
            }
            case 5:
            {
                cout << "Villager name: ";
                cin >> villagerName;

                auto it = villagerDetails.find(villagerName);
                if (it == villagerDetails.end()) 
                {  
                    cout << villagerName << " not found." << endl << endl;
                }
                else
                {
                    auto [friendship, species, catchphrase] = it->second;
                    cout << "Found " << villagerName << "'s details: ";
                    cout << "[" << friendship << ", " << species << ", " << catchphrase << "]";
                    cout << endl;
                    cout << endl;
                }

                break;
            }
        }
    }

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerDetails.size() << endl;
    villagerDetails.clear();
    cout << "Size after clear: " << villagerDetails.size() << endl;

    return 0;
}