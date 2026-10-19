#pragma force_active on
extern "C" int fn_41_15FD4(int, int);
extern "C" int fn_41_1F1F8(int);

extern "C" int fn_41_180FC(int a, int b) {
    if (b == -1) return -1;
    return fn_41_1F1F8(fn_41_15FD4(a, b));
}
