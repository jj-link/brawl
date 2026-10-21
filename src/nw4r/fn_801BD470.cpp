#pragma force_active on
extern "C" {
extern float lbl_805A34A8;
extern float lbl_805A34AC;

void fn_801BD470(void* arg0, int arg1, float farg0) {
    float val;
    if (farg0 > lbl_805A34AC) {
        val = lbl_805A34AC;
    } else if (farg0 < lbl_805A34A8) {
        val = lbl_805A34A8;
    } else {
        val = farg0;
    }
    *(float*)((char*)arg0 + arg1 * 4 + 0xA8) = val;
}
}
