#include <iostream>

using namespace std;

class Student {
public:
    int roll;
    string name;

    Student() {
        roll = -1;
        name = "";
    }
};

class StudentHashTable {
public:
    Student table[15];

    int hashFunc(int roll) {
        return roll % 15;
    }

    void InsertRecord(int roll, string name) {
        int index = hashFunc(roll);

        int attempt = 0;
        int newIndex = index;

        while (table[newIndex].roll != -1) {
            attempt++;
            newIndex = (index + attempt * attempt) % 15;

            if (attempt > 15) {
                cout << "Hash table is full. Cannot insert.\n";
                return;
            }
        }

        table[newIndex].roll = roll;
        table[newIndex].name = name;
    }

    void display() {
        for (int i = 0; i < 15; i++) {
            cout << "Bucket " << i << ": ";
            if (table[i].roll != -1)
                cout << table[i].roll << " - " << table[i].name;
            else
                cout << "EMPTY";
            cout << endl;
        }
    }
};

int main() {
    StudentHashTable obj;

    obj.InsertRecord(0521, "Hasheem");
    obj.InsertRecord(780, "Ali");
    obj.InsertRecord(0742, "Mustufa");
    obj.InsertRecord(1023, "Muzammil");

    obj.display();

    return 0;
}

