#pragma force_active on
extern float lbl_8040AD30[];

extern "C" {
void fn_801BF2E0(void *arg0, int arg1) {
    *(float *)((char *)arg0 + 0x10) = lbl_8040AD30[arg1];
}
}
