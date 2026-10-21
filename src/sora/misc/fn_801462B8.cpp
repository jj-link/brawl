#pragma force_active on
typedef signed short s16;
extern s16 lbl_805A040A;

extern "C" {
void fn_801462B8(int unused, s16 arg1) {
    lbl_805A040A = arg1;
}
}
