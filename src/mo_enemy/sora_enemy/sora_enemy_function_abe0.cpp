#pragma force_active on
extern const float lbl_41_rodata_18;

extern "C" void fn_41_ABE0(void* ptr) {
    unsigned char* p = (unsigned char*)ptr;
    p[0] = 0;
    p[1] = 0;
    p[2] = 1;
    *(int*)(p + 0x24) = 0;
    *(int*)(p + 4) = -1;
    *(float*)(p + 0x10) = lbl_41_rodata_18;
    *(float*)(p + 0x0c) = lbl_41_rodata_18;
    *(float*)(p + 0x08) = lbl_41_rodata_18;
    *(float*)(p + 0x18) = lbl_41_rodata_18;
    *(float*)(p + 0x14) = lbl_41_rodata_18;
    *(float*)(p + 0x20) = lbl_41_rodata_18;
    *(float*)(p + 0x1c) = lbl_41_rodata_18;
    *(int*)(p + 0x28) = 0;
}
