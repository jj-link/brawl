#pragma force_active on
extern "C" void setFrameVisible__8MuObjectFf(void*, float);
extern const float lbl_31_rodata_0[];

static inline int get4b4(char* self) {
    return *(int*)(self + 0x4b4);
}

extern "C" void fn_31_2558(char* self) {
    const float* ro = lbl_31_rodata_0;
    void* r30 = *(void**)(self + 0x3fc);
    unsigned char a = *(unsigned char*)(self + 0x5e6);
    if (a != 0) {
        setFrameVisible__8MuObjectFf(r30, ro[0x34 / 4]);
        return;
    }
    int v4 = *(int*)(self + 0x4ac);
    if (v4 == 0 && v4 == get4b4(self))
        setFrameVisible__8MuObjectFf(r30, ro[0x34 / 4]);
    int v3 = *(int*)(self + 0x4ac);
    if (v3 != 0 && v3 == get4b4(self))
        setFrameVisible__8MuObjectFf(r30, ro[0x40 / 4]);
    int v3b = *(int*)(self + 0x4ac);
    if (v3b == 0 && v3b != get4b4(self))
        setFrameVisible__8MuObjectFf(r30, ro[0xf8 / 4]);
    int v3c = *(int*)(self + 0x4ac);
    if (v3c != 0 && v3c != get4b4(self))
        setFrameVisible__8MuObjectFf(r30, ro[0xfc / 4]);
}