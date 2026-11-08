#pragma force_active on
extern "C" {
void OSRegisterVersion(const char *);
void fn_801CC09C(void *, const void *, unsigned int);
extern const char *lbl_8059E970;
extern char lbl_804C2340[];
}
extern "C" void fn_801CC034(int arg0, int arg1) {
    struct S { int f0, f1, f2, f3; } s;
    OSRegisterVersion(lbl_8059E970);
    s.f1 = 0x4000;
    s.f3 = 0x4000;
    s.f0 = arg0;
    s.f2 = arg1;
    fn_801CC09C(&s, lbl_804C2340, 0x1696C);
}