#pragma force_active on
extern "C" {
    extern void fn_801C07F8(int, int, int, int);
    void fn_801C219C(int arg0, int arg1, int arg2);
}

void fn_801C219C(int arg0, int arg1, int arg2) {
    fn_801C07F8(arg0 + 8, arg1, arg2, 0xD8);
}
