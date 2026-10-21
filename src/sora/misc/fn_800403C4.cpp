#pragma force_active on
extern "C" void fn_800401A4(int, int, void*);

extern "C" void fn_800403C4(int a, int b) {
    double sp8;
    fn_800401A4(a, b, &sp8);
}
