#include <bits/stdc++.h>
using namespace std;

void CSCAN(int arr[], int head) {
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right, seek_sequence;

    left.push_back(0);
    right.push_back(DISK_SIZE - 1);

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    for (int track : right) {
        seek_sequence.push_back(track);
        distance = abs(track - head);
        seek_count += distance;
        head = track;
    }
    
    head = 0;
    seek_count += (DISK_SIZE - 1);

    for (int track : left) {
        seek_sequence.push_back(track);
        distance = abs(track - head);
        seek_count += distance;
        head = track;
    }

    cout << "Total number of seek operations = " << seek_count << endl;
    cout << "Seek Sequence is:" << endl;
    for (int track : seek_sequence)
        cout << track << endl;
}

int main() {
    int arr[SIZE] = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53;
    
    cout << "Initial position of head: " << head << endl;
    CSCAN(arr, head);
    
    return 0;
}
