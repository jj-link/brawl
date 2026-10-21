#pragma force_active on
extern "C" void fn_8018BDD4(int, int, int, int, int, int);

extern "C" void fn_8018BFEC(int arg0, int arg1, int arg2, int arg3) {
    fn_8018BDD4(arg0 + 4, arg0 + 0x30, arg1, arg2, arg3, arg1);
}
