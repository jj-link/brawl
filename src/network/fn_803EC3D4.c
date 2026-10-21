#pragma force_active on
extern void OSReport(const char* fmt, ...);
extern void fn_801E032C(int arg0);
extern char lbl_8049315C[];

int fn_803EC3D4(int arg0) {
    if (arg0 == 0) {
        OSReport(lbl_8049315C);
        return -2;
    }
    fn_801E032C(arg0);
    return 0;
}
