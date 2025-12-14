#include <iostream>
using namespace std;

class SongNode {
public:
    string title;
    SongNode* link;

    SongNode(string t) {
        title = t;
        link = nullptr;
    }
};

class Playlist {
    SongNode* start;
    SongNode* end;

public:
    Playlist() {
        start = end = NULL;
    }

    void insert(string name) {
        SongNode* s = new SongNode(name);
        if (start == NULL) {
            start = end = s;
            end->link = start;
        } else {
            end->link = s;
            end = s;
            end->link = start;
        }
    }

    void show() {
        if (start == NULL) return;
        SongNode* p = start;
        do {
            cout << p->title << endl;
            p = p->link;
        } while (p != start);
        cout << endl;
    }

    void remove(string name) {
        if (start == NULL) return;

        if (start == end && start->title == name) {
            delete start;
            start = end = NULL;
            return;
        }

        SongNode* curr = start;
        SongNode* prev = end;

        do {
            if (curr->title == name) {
                if (curr == start) {
                    start = start->link;
                    end->link = start;
                } else if (curr == end) {
                    end = prev;
                    end->link = start;
                } else {
                    prev->link = curr->link;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->link;
        } while (curr != start);
    }

    void play(int count) {
        if (start == NULL) return;
        SongNode* p = start;
        for (int i = 0; i < count; i++) {
            cout << "Playing: " << p->title << endl;
            p = p->link;
        }
    }

    ~Playlist() {
        if (start == NULL) return;
        end->link = NULL;
        SongNode* p = start;
        while (p != NULL) {
            SongNode* nxt = p->link;
            delete p;
            p = nxt;
        }
        start = end = NULL;
    }
};

int main() {
    Playlist p;

    p.insert("Track 1");
    p.insert("Track 2");
    p.insert("Track 3");

    p.show();

    p.remove("Track 1");
    p.show();

    p.play(6);

    return 0;
}

