#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int main() 
{
    // Comment #1: Create a map to store villager details keyed by name
    map<string, tuple<int, string, string>> villagerDetails; 

    // Comment #2: Variables to temporarily hold user input
    int choice;
    string villagerName;
    int friendship;
    string species;
    string catchphrase;

    // Comment #3: Menu loop runs until user chooses to exit
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

        // Comment #4: Exit program if user selects option 6
        if (choice == 6)
        {
            break;
        }
        
        switch (choice)
        {
            case 1:
            {
                // Comment #5: Input villager info and insert into map
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
                // Comment #6: Remove villager by name
                cout << "Villager name: ";
                cin >> villagerName;

                villagerDetails.erase(villagerName);

                cout << villagerName << " deleted." << endl << endl;
                                    
                break;
            }
            case 3:
            {
                // Comment #7: Increase friendship level if villager exists
                cout << "Villager name: ";
                cin >> villagerName;
                
                auto it = villagerDetails.find(villagerName);
                if (it == villagerDetails.end()) 
                {  
                    // Comment #8: Villager not found case
                    cout << villagerName << " not found." << endl << endl;
                }
                else
                {
                    // Comment #9: Only increment if friendship < 10
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
                // Comment #10: Decrease friendship level if villager exists
                cout << "Villager name: ";
                cin >> villagerName;

                auto it = villagerDetails.find(villagerName);
                if (it == villagerDetails.end()) 
                {  
                    cout << villagerName << " not found." << endl << endl;
                }
                else
                {
                    // Comment #11: Prevent friendship from going below 0
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
                // Comment #12: Search and display villager details
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

        // Print all villagers' details in the map
        cout << "Villagers and their details (iterators):" << endl;
        for (map<string, tuple<int, string, string>>::iterator it = villagerDetails.begin(); 
                                                it != villagerDetails.end(); ++it) 
        {
            const string& name = it->first;
            auto [friendship, species, catchphrase] = it->second;

            cout << name << " [" << friendship << ", " << species << ", " << catchphrase << "]";
            cout << endl;
        }
        
        cout << endl;
    }

    return 0;
}