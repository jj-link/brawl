#pragma force_active on
extern "C" bool fn_41_1AE7C(void* p);
extern float lbl_41_rodata_C9C;

extern "C" float fn_41_1F194(void* unit) {
    float f;
    if (fn_41_1AE7C(unit) == 1) {
        f = lbl_41_rodata_C9C;
    } else {
        int t = *(int*)((char*)unit + 0x8);
        if (t == 0x15) {
            goto A;
        }
        if (t != 0x16) {
            goto B;
        }
A:
        f = *(float*)((char*)unit + 0xac);
        return f;
B:
        f = lbl_41_rodata_C9C;
    }
    return f;
}
