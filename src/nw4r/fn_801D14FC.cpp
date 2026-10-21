#pragma force_active on
extern float lbl_805A3640;
extern float lbl_805A3644;

extern "C" void fn_801D14FC(unsigned char* self, int idx, float x) {
    float v;
    if (x > lbl_805A3640) {
        v = lbl_805A3640;
    } else if (x < lbl_805A3644) {
        v = lbl_805A3644;
    } else {
        v = x;
    }
    float* slot = (float*)(self + idx * 4 + 0xD0);
    if (v == *slot) {
        return;
    }
    *slot = v;
    self[0xB1] |= 0x10;
}
