#pragma force_active on
int fn_80387A3C(int, int);

void fn_803884B8(int arg0, int arg1) {
    if (fn_80387A3C(arg0 + 8, arg1) == 0) {
        fn_80387A3C(arg0 + 0x14, arg1);
    }
}
