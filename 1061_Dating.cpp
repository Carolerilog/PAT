#include <iostream>
#include <unordered_set>
#include <string>
#include <string_view>

using namespace std;

int main() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;

    int idx = 0;
    int day;
    int h;
    for(int i = 0; i < min(a.size(), b.size()); i++) {

        if(idx == 0 && a[i] == b[i] && a[i] >= 'A' && a[i] <= 'G') {
            day = a[i] - 'A';
            idx++;
        } else if(idx == 1 && a[i] == b[i] && (isdigit(a[i]) || (a[i] >= 'A' && a[i] <= 'N'))) {
            if(isdigit(a[i])) {
                h = a[i] - '0';
            } else {
                h = a[i] - 'A' + 10;
            }

            break;
        } 
    }

    int s = 0;
    for(; s < min(c.size(), d.size()); s++) {
        if(c[s] == d[s] && isalpha(c[s])) {
            break;
        }
    }

    constexpr string_view week[7] = {
        "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
    };

    printf("%s %02d:%02d\n", week[day].data(), h, s);
    return 0;
}