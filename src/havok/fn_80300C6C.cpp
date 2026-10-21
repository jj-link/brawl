#pragma force_active on
extern "C" void fn_8031830C(int a1, int a2);

extern "C" void fn_80300C6C(int a1, int a2, int a3) {
    fn_8031830C(a2 + 0xC, a3);
}
