#pragma force_active on
extern "C" {
extern char lbl_6_rodata_0[];
void setFrameVisible__8MuObjectFf(void* obj, float f);
}

extern "C" void fn_6_38F8(unsigned char* self, int flag) {
    char* base = lbl_6_rodata_0;
    float f;
    if (flag == 0) {
        f = *(float*)(base + 0x590);
    } else {
        f = *(float*)(base + 0x1c4);
    }
    unsigned char* p = *(unsigned char**)(self + 0x1ac);
    if (p[0x1c74] == 0) {
        f = f + *(float*)(base + 0x1c8);
    }
    setFrameVisible__8MuObjectFf(*(void**)(p + 0x108), f);
}
