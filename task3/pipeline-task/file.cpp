#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

double f(double x, double y) { return (x - 0.5) * (x - 0.5) + y * y; }

pair<double, double> ternary2d(double (*f)(double, double)) {
    double xl = -1e9, xr = 1e9, yl = -1e9, yr = 1e9, xm1, ym1, xm2, ym2;
    while (xr - xl > 1e-9) {
        xm1 = (2 * xl + xr) / 3, xm2 = (xl + 2 * xr) / 3,
        ym1 = (2 * yl + yr) / 3, ym2 = (yl + 2 * yr) / 3;
        if (f(xl, ym1) < f(xl, ym2))
            yr = ym2;
        else
            yl = ym1;
        if (f(xm1, yl) < f(xm2, yl))
            xr = xm2;
        else
            xl = xm1;
    }
    return {xl, yl};
}

int main() {
    fast();

    pair<double, double> a = ternary2d(f);
    cout << fixed << setprecision(6) << a.first << ' ' << a.second << '\n';

    return 0;
}
