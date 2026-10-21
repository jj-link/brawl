#pragma force_active on
extern "C" int fn_80351304(int);

extern "C" int fn_8014CB4C(int a, int b) {
    return (fn_80351304(b) - 1) == 0;
}
