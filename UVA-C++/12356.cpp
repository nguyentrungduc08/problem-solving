#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
    // freopen("in.txt","r",stdin);
    // freopen("out.txt", "w", stdout); 
     
    int s, b;
    bool arrSoldiers[100002]; 
    int arrLeftBuddy[100002];
    int arrRightBuddy[100002];

    while (scanf("%d %d", &s, &b)) {
        if (s == 0 && b == 0) {
            break;
        }
        for(int i = 1 ; i <= s; ++i) {
            arrSoldiers[i] = true;
            arrLeftBuddy[i] = i-1;
            arrRightBuddy[i] = i+1;
        }
        arrSoldiers[0]  =  false;
        arrSoldiers[s+1] = false;
        arrRightBuddy[s] = 0; 
        int l,r;
        for (int i = 0 ; i < b; ++i) {
            scanf("%d %d", &l, &r);
            for(int j = l; j <=r ; ++j) {
                arrSoldiers[j] = false;
            }
            arrSoldiers[l] = false;
            arrSoldiers[r] = false;
            arrRightBuddy[arrLeftBuddy[l]] = arrRightBuddy[r];
            arrLeftBuddy[arrRightBuddy[r]] = arrLeftBuddy[l];

            if (arrSoldiers[arrLeftBuddy[arrRightBuddy[r]]]) {
                printf("%d ", arrLeftBuddy[arrRightBuddy[r]]);
            } else {
                printf("* ");
            }

            if (arrSoldiers[arrRightBuddy[arrLeftBuddy[l]]]) {
                printf("%d\n",arrRightBuddy[arrLeftBuddy[l]]);
            } else {
                printf("*\n");
            }
        }   
        printf("-\n");
    } 
    return 0;
}
