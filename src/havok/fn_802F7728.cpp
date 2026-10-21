#pragma force_active on
extern "C" void fn_802F7744(int, int, int, int);

extern "C" void fn_802F7728(int a0, int a1, int a2) {
    if (a1 > 1)
        fn_802F7744(a0, 0, a1 - 1, a2);
}
