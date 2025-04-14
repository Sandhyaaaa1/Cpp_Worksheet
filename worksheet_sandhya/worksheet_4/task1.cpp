#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class PersonManager {
public:
    void addPerson() {
        string name;
        int age;

        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;

        names.push_back(name);
        ages[name] = age;
    }

    void findSeniors() {
        int limit;
        cout << "Enter age limit: ";
        cin >> limit;

        cout << "People above " << limit << ":\n";
        for (auto& pair : ages) {
            if (pair.second > limit) {
                cout << pair.first << " (" << pair.second << ")\n";
            }
        }
    }

    void showSorted() {
        vector<string> temp = names;
        sort(temp.begin(), temp.end());

        cout << "Sorted names:\n";
        for (auto& name : temp) {
            cout << "- " << name << "\n";
        }
    }

    void runMenu() {
        while (true) {
            cout << "\n--- Menu ---\n";
            cout << "1. Add person\n";
            cout << "2. Find seniors\n";
            cout << "3. Show sorted names\n";
            cout << "4. Exit\n";
            cout << "Choose: ";

            int choice;
            cin >> choice;

            switch (choice) {
                case 1: addPerson(); break;
                case 2: findSeniors(); break;
                case 3: showSorted(); break;
                case 4: return;
                default: cout << "Invalid choice!\n";
            }
        }
    }

private:
    vector<string> names;
    map<string, int> ages;
};

int main() {
    PersonManager manager;
    manager.runMenu();
    return 0;
}
