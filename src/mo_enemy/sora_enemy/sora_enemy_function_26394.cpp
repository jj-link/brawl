#pragma force_active on
extern "C" int fn_41_23BD4(int, unsigned int);
extern "C" int fn_27_14D550(int);

extern "C" int fn_41_26394(int p1, unsigned int p2) {
    if (p2 <= 3) {
        return fn_27_14D550(fn_41_23BD4(p1, p2));
    }
    return 0;
}
