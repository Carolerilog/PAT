// Customer with no valid record should not be outputed
#include <iostream>
#include <cstdio>
#include <array>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

struct phone_call {
    int mo, d, h, mt;
    bool is_on_line;

    bool operator<(phone_call const& pc) const {
        auto mts = [](phone_call const& pc) -> int {
            return pc.d * 24 * 60 + pc.h * 60 + pc.mt;
        };

        auto m0 = mts(*this);
        auto m1 = mts(pc);

        return m0 < m1 || (m0 == m1 && is_on_line >= pc.is_on_line);
    }
};

int main() {
    array<int, 24> price;
    int total_price = 0;

    for(int i = 0; i < 24; i++) {
        cin >> price[i];
        total_price += price[i] * 60;
    }

    int n;
    cin >> n;

    map<string,  vector<phone_call>> m;
    while(n--) {
        string name;
        cin >> name;

        phone_call pc;
        scanf("%d:%d:%d:%d", &pc.mo, &pc.d, &pc.h, &pc.mt);

        string is_on_line;
        cin >> is_on_line;

        if(is_on_line == "on-line") {
            pc.is_on_line = true;
        } else {
            pc.is_on_line = false;
        }

        m[name].push_back(pc);
    }

    for(auto& [name, pcs] : m) {
        sort(pcs.begin(), pcs.end());
        float total_call_price = 0.f;

        bool flag = false;

        for(int i = 0; i < pcs.size() - 1; i++) {
            if(pcs[i].is_on_line && !pcs[i + 1].is_on_line) {
                if(!flag) {
                    flag = true;
                    printf("%s %02d\n", name.c_str(), pcs[0].mo);
                }

                int call_cents = -pcs[i].mt * price[pcs[i].h] + pcs[i + 1].mt * price[pcs[i + 1].h];
                int call_mts = -pcs[i].mt + pcs[i + 1].mt;

                call_cents += (pcs[i + 1].d - pcs[i].d) * total_price;
                call_mts += (pcs[i + 1].d - pcs[i].d) * 24 * 60;

                if(pcs[i + 1].h < pcs[i].h) {
                    for(int j = pcs[i + 1].h; j < pcs[i].h; j++) {
                        call_cents -= price[j] * 60;
                        call_mts -= 60;
                    }
                } else {
                    for(int j = pcs[i].h; j < pcs[i + 1].h; j++) {
                        call_cents += price[j] * 60;
                        call_mts += 60;
                    }
                }

                total_call_price += call_cents;

                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", 
                       pcs[i].d, pcs[i].h, pcs[i].mt, 
                       pcs[i + 1].d, pcs[i + 1].h, pcs[i + 1].mt, 
                       call_mts,
                       call_cents / 100.f);
            }
        }

        if (flag) {
            printf("Total amount: $%.2f\n", total_call_price / 100.f);
        }
    }

    return 0;
}