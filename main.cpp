#include <bits/stdc++.h>
#include <ctype.h>

using namespace std;

/*
 * Complete the 'abbreviation' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

bool isStringLower(string s) {
    for (int i = 0; i < s.length(); ++i)
        if (!islower(s[i])) return false;
    
    return true;
}

int abbreviationAux(string a, string b, int ia, int ib, vector<vector<int>> dp) {
    if (ia == a.length()) {
        if (ib == b.length()) return 1;
        else return 0;
    } else if (ib == b.length()) return isStringLower(a.substr(ia));
    
    if (dp[ia][ib] == -1) {
        if (a[ia] == b[ib]) dp[ia][ib] = abbreviationAux(a, b, ia+1, ib+1, dp);
        else if (toupper(a[ia]) == b[ib]) dp[ia][ib] = abbreviationAux(a, b, ia+1, ib+1, dp) || abbreviationAux(a, b, ia+1, ib, dp);
        else if (a[ia] != b[ib] && isupper(a[ia])) dp[ia][ib] = 0;
        else dp[ia][ib] = abbreviationAux(a, b, ia+1, ib, dp);
    }
    
    return dp[ia][ib];
}

string abbreviation(string a, string b) {
    if (b.length() > a.length()) {
        return "NO";
    }
    
    vector<vector<int>> dp(a.length(), vector<int>(b.length(), -1));
    
    auto res = abbreviationAux(a, b, 0, 0, dp);
    
    if (res == 1) return "YES";
    else return "NO";
}


int main()
{
    cout << abbreviation("BFZZVHdQYHQEMNEFFRFJTQmNWHFVXRXlGTFNBqWQmyOWYWSTDSTMJRYHjBNTEWADLgHVgGIRGKFQSeCXNFNaIFAXOiQORUDROaNoJPXWZXIAABZKSZYFTDDTRGZXVZZNWNRHMvSTGEQCYAJSFvbqivjuqvuzafvwwifnrlcxgbjmigkms", "BFZZVHQYHQEMNEFFRFJTQNWHFVXRXGTFNBWQOWYWSTDSTMJRYHBNTEWADLHVGIRGKFQSCXNFNIFAXOQORUDRONJPXWZXIAABZKSZYFTDDTRGZXVZZNWNRHMSTGEQCYAJSF") << endl;


    return 0;
}
