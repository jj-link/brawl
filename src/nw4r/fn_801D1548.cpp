#pragma force_active on
extern float lbl_805A3640;
extern float lbl_805A3644;

extern "C" void fn_801D1548(char* self, int idx, float v) {
    float r;
    if (v > lbl_805A3640) {
        r = lbl_805A3640;
    } else if (v < lbl_805A3644) {
        r = lbl_805A3644;
    } else {
        r = v;
    }
    float* arr = (float*)(self + idx * 4);
    if (r == arr[55]) {
        return;
    }
    arr[55] = r;
    self[0xb1] |= 0x10;
}
