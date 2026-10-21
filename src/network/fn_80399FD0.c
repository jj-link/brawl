#pragma force_active on
typedef int s32;
extern void OSRegisterVersion(s32);
extern s32 lbl_8059FCE0;
extern s32 lbl_805A1180;

void fn_80399FD0(void) {
    if (lbl_805A1180 == 0) {
        OSRegisterVersion(lbl_8059FCE0);
        lbl_805A1180 = 1;
    }
}
