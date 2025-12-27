class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        
        sort(begin(meetings), end(meetings));

        priority_queue<long long, vector<long long>, greater<long long>> freeRooms;
        for(int i = 0; i < n; i++) {
            freeRooms.push(i);
        }
        
        priority_queue<array<long long, 2>, vector<array<long long, 2>>, greater<array<long long, 2>>> bookRooms;

        vector<long long> cnt(n);

        for (int i = 0; i < m; i++) {
            while (!bookRooms.empty() && bookRooms.top()[0] <= meetings[i][0]) {
                freeRooms.push(bookRooms.top()[1]);
                bookRooms.pop();
            }
            if (!freeRooms.empty()) {
                cnt[freeRooms.top()]++;
                bookRooms.push({meetings[i][1], freeRooms.top()});
                freeRooms.pop();
            } else {
                auto [s, id] = bookRooms.top();
                bookRooms.pop();
                cnt[id]++;
                bookRooms.push({s + meetings[i][1] - meetings[i][0], id});
            }
        }

        int maxRoom = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[i] > cnt[maxRoom]) maxRoom = i;
        }
        return maxRoom;
        

    }
};