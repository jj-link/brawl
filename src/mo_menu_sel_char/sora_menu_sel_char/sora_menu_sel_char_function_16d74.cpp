#pragma force_active on
extern "C" int fn_800B5854(void*, int, int, int, int);
extern const unsigned char lbl_10_rodata_6B4[4];

extern "C" int fn_10_16D74(unsigned char* self, int mode, int flag, int idx) {
    switch (mode) {
    case 0:
        mode = 5;
        break;
    case 2:
        mode = 4;
        break;
    case 1:
        if (flag != 0) {
            mode = lbl_10_rodata_6B4[idx];
        } else {
            mode = *(int*)(self + 0x1b0);
        }
        break;
    }
    return fn_800B5854(*(void**)(self + 0xd0), mode, 0x10, 0, 0);
}
