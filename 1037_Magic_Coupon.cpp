#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    size_t nc;
    cin >> nc;

    vector<ll> coupon(nc);
    for(auto& c : coupon) {
        cin >> c;
    }
    sort(coupon.begin(), coupon.end());

    size_t np;
    cin >> np;

    vector<ll> product(np);
    for(auto& p : product) {
        cin >> p;
    }
    sort(product.begin(), product.end());

    ll max_back = 0;

    size_t l;
    for(l = 0; coupon[l] <= 0 && product[l] <= 0 && l < nc && l < np; l++) {
        max_back += coupon[l] * product[l];
    }

    size_t r;
    for(r = 0; coupon[nc - 1 - r] >= 0 && product[np - 1 - r] >= 0 && r < nc && r < np; r++) {
        max_back += coupon[nc - 1 - r] * product[np - 1 - r];
    }

    // if(true
    //    && l < nc 
    //    && l < np 
    //    && r < nc 
    //    && r < np 
    //    && l <= nc - r 
    //    && l <= np - r) {
    //     size_t cr = nc - 1 - r;
    //     size_t pr = np - 1 - r;
    //     
    //     if(coupon[l] >= 0 && coupon[cr] >= 0) {
    //         size_t offset = max(0ul, pr - cr);
    //         for(l = l + offset; l <= pr; l++) {
    //             max_back += coupon[l] * product[l];
    //         }
    //     } else if(coupon[l] <= 0 && coupon[cr] <= 0) {
    //         size_t offset = max(0ul, cr - pr);
    //         for(; l + offset <= cr; l++) {
    //             max_back += coupon[l + offset] + product[l];
    //         }
    //     }
    // }

    cout << max_back << endl;
    return 0;
}