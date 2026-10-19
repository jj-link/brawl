#pragma force_active on
extern "C" int fn_27_C2A58(int a, int b, int c, int d) {
    if (a < b)
        return b - a;

    if (a == b && d == 0)
        return 0;

    return c - (a - b);
}
