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

        auto it = villagerDetails.find(villagerName);
        
        switch (choice)
        {
            case 1:
            {
                villagerDetails
    
                break;
            }
            case 2:
            {
                
                                    
                break;
            }
            case 3:
            {
                if (it == villagerDetails.end()) 
                {  
                    cout << endl << villagerName << " not found." << endl << endl;
                }
                else
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
                }

                break;
            }
            case 4:
            {
                if (it == villagerDetails.end()) 
                {  
                    cout << endl << villagerName << " not found." << endl << endl;
                }
                else
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
                }

                break;
            }
            case 5:
            {
                if (it == villagerDetails.end()) 
                {  
                    cout << endl << villagerName << " not found." << endl << endl;
                }
                else
                {
                    auto [friendship, species, catchphrase] = it->second;
                    cout << "\nFound " << villagerName << "'s details: ";
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