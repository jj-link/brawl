#pragma force_active on
int fn_8039A69C(int arg0, int arg1, int *arg2) {
    signed char d0, d1, d2, d3, d4, d5;
    int n;
    int x;

    *arg2 = 0;
    n = 0 - arg0;
    d0 = n % 10;
    n /= 10;
    d1 = n % 10;
    n /= 10;
    d2 = n % 10;
    n /= 10;
    d3 = n % 10;
    n /= 10;
    d4 = n % 10;
    n /= 10;
    d5 = n % 10;
    if (d5 == 0 && d4 == 5) { *arg2 = 60; return -31; }
    if (d3 == 7) {
        if (!(arg1 & 2)) return 0;
    } else if (!(arg1 & 1)) return 0;
    if (d5 == 1 && d4 == 1) {
        if (d2 == 1) return 0;
        if (d2 == 4 && d1 == 0 && d0 == 7) { *arg2 = 60; return -31; }
        if (!(arg1 & 1)) return 0;
        *arg2 = 30; return -32;
    }
    if (d5 == 1 && d4 == 0) {
        if (!(arg1 & 1)) return 0;
        x = d0 + d1 * 10;
        switch (d2) {
        case 0:
            if (x >= 70) return 0;
            *arg2 = 60;
            switch (x) {
            case 0: case 1: case 2: case 3: return -1;
            case 30: case 31: return -31;
            case 32: return -32;
            default: return 0;
            }
        case 2:
            switch (-x) {
            case -1: *arg2 = 60; return -1;
            case -11: case -45: return 0;
            case -31: case -44: case -33: *arg2 = 60; return -31;
            case -32: *arg2 = 20; return -32;
            default: return 0;
            }
        case 3:
            switch (x) {
            case 1: case 2: case 3: case 4: case 5:
            case 9: case 10: case 11: case 12: case 13:
                *arg2 = 30; return -31;
            case 6: case 7: case 8:
                *arg2 = 20; return -32;
            default: return 0;
            }
        case 4:
            switch (x) {
            case 9: case 10: case 11: case 12:
                *arg2 = 60; return -32;
            default: *arg2 = 20; return -31;
            }
        }
    }
    return 0;
}
