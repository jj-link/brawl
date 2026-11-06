#pragma force_active on
extern const float lbl_67_rodata_0;

extern "C" int fn_67_1BD0(unsigned char* self, void* unused, int* out1, int* out2) {
    unsigned char i;
    int n;
    if (self[0x248] == 0) {
        return 0;
    }
    i = 0;
    for (n = 0; n < 2; n++) {
        if (i == 9) break;
        if (*(float*)(self + ((unsigned char)i << 2) + 0x1F0) != lbl_67_rodata_0) return 0;
        i++;
        if (i == 9) break;
        if (*(float*)(self + ((unsigned char)i << 2) + 0x1F0) != lbl_67_rodata_0) return 0;
        i++;
        if (i == 9) break;
        if (*(float*)(self + ((unsigned char)i << 2) + 0x1F0) != lbl_67_rodata_0) return 0;
        i++;
        if (i == 9) break;
        if (*(float*)(self + ((unsigned char)i << 2) + 0x1F0) != lbl_67_rodata_0) return 0;
        i++;
        if (i == 9) break;
        if (*(float*)(self + ((unsigned char)i << 2) + 0x1F0) != lbl_67_rodata_0) return 0;
        i++;
    }
    *out1 = 6;
    *out2 = 4;
    return 1;
}
