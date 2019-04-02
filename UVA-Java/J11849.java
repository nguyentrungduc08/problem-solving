import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


/**
 *
 * @author ducnt6
 * problem: https://uva.onlinejudge.org/external/118/11849.pdf
 */
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int n,m;
            n = sc.nextInt();
            m = sc.nextInt();
            if (n == 0 && m ==0) {
                break;
            }
            Set setCD = new HashSet<>();
            for(int i = 0; i < n; ++i) {
                int catalog = sc.nextInt();
                setCD.add(catalog);
            }
            int res = 0;
            for(int i = 0; i < m; ++i) {
                int catalog = sc.nextInt();
                if (setCD.contains(catalog)) {
                    ++res;
                }
            }
            System.out.println(res);
        }
    }   
}