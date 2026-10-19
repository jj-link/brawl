#pragma force_active on
typedef unsigned char u8;

extern "C" const float lbl_67_rodata_E8;
extern "C" const float lbl_67_rodata_F0;

extern "C" void fn_67_B0B8(u8* obj, unsigned int a, unsigned int b, unsigned int c) {
    if (obj[0x1c8] != 4) {
        return;
    }
    unsigned int flag = 0;
    if (lbl_67_rodata_E8 == *(float*)(obj + 0x1a0)) {
        flag = 1;
    }
    if (c == 1) {
        flag = 1;
    }
    *(float*)(obj + 0x1a0) = lbl_67_rodata_F0;
    if (flag != 1) {
        return;
    }
    obj[0x15d] = 1;
}
