#pragma force_active on
typedef int (*FnPtr)(int, int);
extern FnPtr lbl_805A09A0;

int fn_801FB924(int a) {
    FnPtr f = lbl_805A09A0;
    if (f == 0) {
        return a;
    }
    return f(a == 0 ? 1 : 2, 0);
}
