#pragma force_active on
extern float lbl_805A3640;
extern float lbl_805A3644;

extern "C" void fn_801D15E4(void* obj, int index, float value) {
    float clamped;
    if (value > lbl_805A3640) {
        clamped = lbl_805A3640;
    } else if (!(value < lbl_805A3644)) {
        clamped = value;
    } else {
        clamped = lbl_805A3644;
    }
    
    float* p = (float*)((char*)obj + 0xFC);
    if (p[index] == clamped) return;
    p[index] = clamped;
    ((unsigned char*)obj)[0xB1] |= 0x10;
}
