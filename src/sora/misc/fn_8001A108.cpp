#pragma force_active on
extern int* lbl_805A0098;
extern const float lbl_805A1454;
extern const float lbl_805A1458;

extern "C" void fn_800384CC(int* p, int v);

extern "C" void fn_8001A108(char* self, int arg1) {
    float f31 = lbl_805A1454;
    int r4 = 0;
    if (arg1 == 0) {
        f31 = lbl_805A1458;
        r4 = 1;
    }

    fn_800384CC(lbl_805A0098, r4);
    *(float*)(self + 0x73c) = *(float*)((char*)lbl_805A0098 + 0x44);
    *(float*)(self + 0x738) = f31;

    float f0 = f31 * *(float*)((char*)lbl_805A0098 + 0x44);
    *(float*)(self + 0xe4) = f0;
    *(float*)(self + 0x218) = f0;
    *(float*)(self + 0x34c) = f0;
    *(float*)(self + 0x480) = f0;
    *(float*)(self + 0x5b4) = f0;
    *(float*)(self + 0x6e8) = f0;
}
