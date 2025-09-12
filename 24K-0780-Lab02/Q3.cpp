#include <iostream>
using namespace std;

int main() {
    int numTeams;
    cout << "Enter number of teams: ";
    cin >> numTeams;

    int* teamSizes = new int[numTeams];
    int** scores = new int*[numTeams];

    for (int i = 0; i < numTeams; i++) {
        cout << "Enter number of players in team " << i + 1 << ": ";
        cin >> teamSizes[i];
        scores[i] = new int[teamSizes[i]];
    }

    for (int i = 0; i < numTeams; i++) {
        cout << "Enter scores for team " << i + 1 << ": ";
        for (int j = 0; j < teamSizes[i]; j++) {
            cin >> scores[i][j];
        }
    }

    for (int i = 0; i < numTeams; i++) {
        int sum = 0;
        for (int j = 0; j < teamSizes[i]; j++) {
            sum += scores[i][j];
        }
        cout << "Sum of scores for team " << i + 1 << ": " << sum << endl;
    }

    for (int i = 0; i < numTeams; i++) {
        delete[] scores[i];
    }
    delete[] scores;
    delete[] teamSizes;

    return 0;
}

