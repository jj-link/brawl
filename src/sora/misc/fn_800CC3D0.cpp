#pragma force_active on
extern "C" void netReport__FPCce(const char*, ...);
extern int gUnk805a03d8;
extern char lbl_80457CFC[];

extern "C" int fn_800CC3D0(void) {
    int s = gUnk805a03d8;
    if (s < 3) {
        return 0;
    }
    if (s == 3) {
        return 1;
    }
    if (s == 4) {
        return 2;
    }
    if (s == 7) {
        return 3;
    }
    netReport__FPCce(lbl_80457CFC, s);
    return 0;
}
