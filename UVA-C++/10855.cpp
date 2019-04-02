#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("in.txt","r",stdin);
    // freopen("out.txt", "w", stdout); 
    int nP, nC; 
    
    char arrParent[500][500];
    char arrChild[500][500];

    while (scanf("%d %d", &nP, &nC)) {
        if (nP == 0 && nC == 0) {
            break;
        }
        for(int r = 0; r < nP; ++r) 
            scanf("%s", arrParent[r]);
        for(int r = 0; r < nC; ++r) 
            scanf("%s", arrChild[r]);

        int res1 = 0 , res2 = 0, res3 = 0, res4 = 0;    
        for(int rP = 0; rP <= nP - nC; ++rP) {
            for(int cP = 0; cP <= nP - nC; ++cP) {
                bool ok = true;
                for(int rC = 0; rC < nC && ok; ++rC) {
                    for(int cC = 0; cC < nC && ok; ++cC) {
                        if (arrChild[rC][cC] != arrParent[rP + rC][cP + cC]) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok){
                    ++res1;
                    //cout << rP << " " << cP << endl;
                }
            }
        }
       //90 degrees
        for(int rP = 0; rP <= nP - nC; ++rP) {
            for(int cP = 0; cP <= nP - nC; ++cP) {
                bool ok = true;
                int r = 0, c = 0;
                
                for(int cC = 0; cC < nC && ok; ++cC) {
                    c = 0;
                    for(int rC = nC - 1; rC >= 0 && ok; --rC) {
                        if (arrChild[rC][cC] != arrParent[rP+r][cP+c]) {
                            ok = false;
                            break;
                        }
                        ++c;
                    }
                    ++r;
                }
                if (ok) {
                    ++res2;
                    //cout << rP << " " << cP << endl;
                }
            }
        } 
        // 180 degrees
        for(int rP = 0; rP <= nP - nC; ++rP) {
            for(int cP = 0; cP <= nP - nC; ++cP) {
                bool ok = true;
                int r = 0, c = 0;
                for (int rC = nC - 1; rC >= 0 && ok; --rC) {
                    c = 0;
                    for(int cC = nC - 1; cC >= 0 && ok; --cC) {
                        if (arrChild[rC][cC] != arrParent[rP + r][cP + c]) {
                            ok = false;
                            break;
                        }
                        ++c;
                    }
                    ++r;
                }
                if (ok) {
                    ++res3;
                    //cout << rP << " " << cP << endl;
                }
            }
        }
        //270 degrees
        for(int rP = 0; rP <= nP - nC; ++rP) {
            for(int cP = 0; cP <= nP - nC; ++cP) {
                bool ok = true;
                int r = 0, c = 0;
                for (int cC = nC - 1; cC >= 0 && ok; --cC) {
                    c = 0;
                    for(int rC = 0; rC < nC && ok; ++rC) {
                        if (arrChild[rC][cC] != arrParent[rP + r][cP + c]) {
                            ok = false;
                            break;
                        }
                        ++c;
                    }
                    ++r;
                }
                if (ok) {
                    ++res4;
                    //cout << rP << " " << cP << endl;
                }
            }
        }
        printf("%d %d %d %d\n", res1, res2, res3, res4);
    } 
    return 0;
}
