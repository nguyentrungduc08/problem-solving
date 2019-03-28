#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt", "w", stdout); 
    int n,k;
    cin >> n;
    while (n--) {
        cin >> k;
        int *arrValue = new int[300];
        for(int i = 0; i < 300; ++i) {
            arrValue[i] = 0;
        }
        for(int i = 0; i < k; ++i) {
            char ch;
            int value;
            cin >> ch >> value;
            arrValue[128 - (int) ch] = value;
        } 
        long res = 0;
        int m;
        cin >> m;
        cin.ignore();
        for (int i = 0; i < m; ++i) {
            string str;
            getline(cin, str);
            //cout << str << endl;
            for(int j = 0; j < str.size(); ++j) {
                res += (long) arrValue[128 - (int)str[j]];
            }
        }
        long dollar = res / 100;
        long cents = res % 100;
        
        printf("%ld.%02ld$\n",dollar,cents); 
    }
    	
    return 0;
}
