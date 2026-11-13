#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TimeMap 
{
private:
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) 
    {
        store[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) 
    {
        if (store.find(key) == store.end()) 
        {
            return "";
        }

        const vector<pair<int, string>>& entries = store[key];

        int left = 0;
        int right = entries.size() - 1;
        string result = "";

        while (left <= right) 
        {
            int mid = left + (right - left) / 2;

            if (entries[mid].first <= timestamp) 
            {
                result = entries[mid].second;
                left = mid + 1;
            } 
            else 
            {
                right = mid - 1;
            }
        }

        return result;
    }
};
