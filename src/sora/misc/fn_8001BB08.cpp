#pragma force_active on
extern int lbl_8059FFE8;
extern int lbl_8059C52C;

extern "C" void fn_8001BB08(int (*func)(int)) {
    lbl_8059FFE8 = (int)func;
    func(lbl_8059C52C);
}
