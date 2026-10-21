#pragma force_active on
extern "C" int fn_801F240C(int a, int b);

extern "C" int fn_801B62B8(int r3, int r4) {
    if (r4) {
        return fn_801F240C(r3 + 4, r4);
    }
    return r3;
}
