#pragma force_active on
#pragma opt_propagation off
extern "C" {
extern const float lbl_27_rodata_10B0;
void fn_27_605AC(void*);

void* fn_27_13F330(void* self) {
    int zeroAfter;
    char* p = (char*)self;
    *(unsigned char*)(p + 0x10) = 0;
    *(float*)(p + 0x00) = lbl_27_rodata_10B0;
    *(float*)(p + 0x04) = lbl_27_rodata_10B0;
    *(float*)(p + 0x08) = lbl_27_rodata_10B0;
    *(float*)(p + 0x0C) = lbl_27_rodata_10B0;
    *(float*)(p + 0x14) = lbl_27_rodata_10B0;
    *(float*)(p + 0x18) = lbl_27_rodata_10B0;
    *(float*)(p + 0x1C) = lbl_27_rodata_10B0;
    *(float*)(p + 0x20) = lbl_27_rodata_10B0;
    *(int*)(p + 0x4C) = 0;
    *(int*)(p + 0x50) = 0;
    *(int*)(p + 0x54) = 0;
    *(float*)(p + 0x58) = lbl_27_rodata_10B0;
    *(float*)(p + 0x5C) = lbl_27_rodata_10B0;
    *(int*)(p + 0x60) = 0;
    *(float*)(p + 0x64) = lbl_27_rodata_10B0;
    *(int*)(p + 0x68) = 0;
    *(int*)(p + 0x6C) = 0;
    *(int*)(p + 0x70) = 0;
    *(int*)(p + 0x74) = 0;
    *(unsigned char*)(p + 0x78) = 0;
    *(int*)(p + 0x7C) = 0;
    *(int*)(p + 0x80) = -1;
    *(unsigned char*)(p + 0x84) = 0;
    *(int*)(p + 0x88) = 0;
    *(float*)(p + 0x8C) = lbl_27_rodata_10B0;
    *(unsigned char*)(p + 0x90) = 0;
    *(int*)(p + 0x94) = 0;
    *(int*)(p + 0x98) = -1;
    *(unsigned char*)(p + 0x9C) = 0;
    *(float*)(p + 0xA0) = lbl_27_rodata_10B0;
    *(float*)(p + 0xA4) = lbl_27_rodata_10B0;
    *(unsigned char*)(p + 0xA8) = 0;
    *(int*)(p + 0xAC) = 1;
    *(int*)(p + 0xB0) = 0;
    *(unsigned char*)(p + 0xB4) = 0;
    *(int*)(p + 0xB8) = 1;
    *(int*)(p + 0xBC) = 0;
    *(unsigned char*)(p + 0xC0) = 0;
    *(int*)(p + 0xC4) = 0;
    *(int*)(p + 0xC8) = 0;
    *(float*)(p + 0xEC) = lbl_27_rodata_10B0;
    *(float*)(p + 0xF0) = lbl_27_rodata_10B0;
    *(float*)(p + 0xF4) = lbl_27_rodata_10B0;
    *(unsigned char*)(p + 0xF8) = 0;
    *(int*)(p + 0xFC) = 0;
    *(int*)(p + 0x110) = 0;
    *(int*)(p + 0x114) = 0;
    fn_27_605AC(p + 0x24);
    zeroAfter = 0;
    *(int*)(p + 0xCC) = zeroAfter;
    *(int*)(p + 0xD0) = zeroAfter;
    *(int*)(p + 0xD4) = zeroAfter;
    *(int*)(p + 0xD8) = zeroAfter;
    *(int*)(p + 0x100) = zeroAfter;
    *(int*)(p + 0x104) = zeroAfter;
    *(int*)(p + 0x108) = zeroAfter;
    *(int*)(p + 0x10C) = zeroAfter;
    return self;
}
}
