#include <iostream>
#include <string>
using namespace std;

class Participant {
public:
    string name;
    int time;

    Participant(string n = "", int t = 0) {
        name = n;
        time = t;
    }
};

void merge(Participant arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Participant leftArr[n1];
    Participant rightArr[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i].time <= rightArr[j].time) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(Participant arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    Participant arr[] = {
        Participant("Ali", 25),
        Participant("Sara", 18),
        Participant("Zain", 30),
        Participant("Hina", 22),
        Participant("Omar", 19),
        Participant("Nida", 27)
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted Participants (by time):\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i].name << " - " << arr[i].time << endl;
    }


}

