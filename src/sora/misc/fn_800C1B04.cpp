#pragma force_active on
struct TwoInts {
    int a;
    int b;
};
extern const TwoInts lbl_80407C58[];
extern "C" void fn_800C1B04(int unused, int idx, int* dest) {
    dest[1] = lbl_80407C58[idx].b;
}
