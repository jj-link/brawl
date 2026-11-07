#pragma force_active on
extern char lbl_80490670[];
int fn_8037F1EC(int a, char* b, int c, int d, int e, char* f);

int fn_8037F00C(int a, char* b, int c, int d, int e, char* f) {
    if (a == 0) {
        return 0;
    }
    if (b == 0 || *b == 0) {
        return 0;
    }
    if (d < 0) {
        return 0;
    }
    if (d == 0 && c == 0) {
        return 0;
    }
    if (f == 0) {
        f = lbl_80490670;
    }
    return fn_8037F1EC(a, b, c, d, e, f);
}
