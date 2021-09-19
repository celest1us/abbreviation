#include <iostream>
#include <algorithm>
#include <vector>

#include "abbrev.hpp"

using namespace std;


typedef struct {
    string a;
    string b;
    string expResult;
} tc_t;

int main() {

    int successes(0);

    vector<tc_t> testcases {
        {"daBcd", "ABC", "YES"},
        {"JHMWY", "HUVPW", "NO"},
        {"RDWPJPAMKGRIWAPBZSYWALDBLDOFLWIQPMPLEMCJXKAENTLVYMSJNRJAQQPWAGVcGOHEWQYZDJRAXZOYDMNZJVUSJGKKKSYNCSFWKVNHOGVYULALKEBUNZHERDDOFCYWBUCJGbvqlddfazmmohcewjg", "RDPJPAMKGRIWAPBZSYWALDBLOFWIQPMPLEMCJXKAENTLVYMJNRJAQQPWAGVGOHEWQYZDJRAXZOYDMNZJVUSJGKKKSYNCSFWKVNHOGVYULALKEBUNZHERDOFCYWBUCJG", "NO"}
    };

    int cnt = 0;
    for (auto &tc : testcases) {

        if (tc.expResult == abbreviation(tc.a, tc.b)) {
            cout << "Test case #" << cnt+1 << ": SUCCESS" << endl;
            ++successes;
        }
        else {
            cout << "Test case #" << cnt+1 << ": FAILURE" << endl;
        }

        ++cnt;
    }

    cout << "Total test cases: " << testcases.size() << endl;
    cout << "Total successes: " << successes << endl;
    cout << "Total failures: " << testcases.size()-successes << endl;

    return 0;
}