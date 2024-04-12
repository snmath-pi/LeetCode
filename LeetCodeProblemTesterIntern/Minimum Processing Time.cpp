class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(rbegin(tasks), rend(tasks));
        sort(begin(processorTime), end(processorTime));
        int res = 0;
        for(int i=0, j =0; i < tasks.size(); i+=4) {
            res = max(res, processorTime[j++] + tasks[i]);
        }
        return res;
    }
};
