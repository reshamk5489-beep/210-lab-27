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
        cout << "6. Exit" << endl;

        cin >> choice;
        if (choice == 6)
        {
            break;
        }

        cout << endl;
        cout << "Please enter villager's name: ";
        cin >> villagerName;
        cout << endl;

        
        switch (choice)
        {
            case 1:
            {
                cout << "Please enter friendship level: ";
                cin >> friendship;
                cout << "Please enter species: ";
                cin >> species;
                cout << "Please enter catchphrase: ";
                getline(cin, catchphrase);

                villagerDetails.insert({villagerName, {friendship, species, catchphrase}});
    
                break;
            }
            case 2:
            {
                villagerDetails.erase(villagerName);
                                    
                break;
            }
            case 3:
            {
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