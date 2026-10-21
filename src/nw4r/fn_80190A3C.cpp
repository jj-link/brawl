#pragma force_active on
extern "C" int fn_801D7718(int, int);
extern "C" int fn_801D7774(int, int);

extern "C" int fn_80190A3C(int* p, int x) {
    int val = *p;
    if (x)
        return fn_801D7718(val, 0x80);
    return fn_801D7774(val, 0x80);
}
