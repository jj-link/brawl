#pragma force_active on
extern int fn_80212588(int);

int fn_803A2814(int a, int b) {
    int r = fn_80212588(b);
    int result = 0;
    if (r < 0)
        result = -0x2A;
    return result;
}
