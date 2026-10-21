#pragma force_active on
typedef struct SOState {
    int f0;
    void (*fn)(int, int, int);
    int f8;
    int fc;
    int f10;
    int count;
} SOState;

extern SOState lbl_80537680;

void fn_803A6828(int a, int b, int c)
{
    SOState* s;
    void (*fn)(int, int, int);
    int d;

    if (b == 0) {
        return;
    }
    s = &lbl_80537680;
    fn = s->fn;
    if (fn == 0) {
        return;
    }
    d = s->count;
    s->count = d - 1;
    fn(a, b, c);
}
