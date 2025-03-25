#include <bits/stdc++.h>
using namespace std;

const int SIZE = 8;
const int DISK_SIZE = 200;

void SCAN(int arr[], int head, string direction) {
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right, seek_sequence;

    if (direction == "left")
        left.push_back(0);
    else if (direction == "right")
        right.push_back(DISK_SIZE - 1);

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int run = 2;
    while (run--) {
        if (direction == "left") {
            for (int i = left.size() - 1; i >= 0; i--) {
                cur_track = left[i];
                seek_sequence.push_back(cur_track);
                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            direction = "right";
        } else if (direction == "right") {
            for (int i = 0; i < right.size(); i++) {
                cur_track = right[i];
                seek_sequence.push_back(cur_track);
                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            direction = "left";
        }
    }

    cout << "Total number of seek operations = " << seek_count << endl;
    cout << "Seek Sequence is:" << endl;
    for (int track : seek_sequence)
        cout << track << endl;
}

int main() {
    int arr[SIZE] = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53;
    string direction = "left";
    
    SCAN(arr, head, direction);
    return 0;
}
