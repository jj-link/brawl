#pragma force_active on
extern "C" const float lbl_66_rodata_1B8;

extern "C" void fn_66_A0C8(char* p) {
    unsigned int v = *(unsigned int*)(p + 0x74);
    *(float*)(p + 0x60) = lbl_66_rodata_1B8;
    *(float*)(p + 0x64) = lbl_66_rodata_1B8;
    *(float*)(p + 0x68) = lbl_66_rodata_1B8;
    *(unsigned int*)(p + 0x74) = v & ~31u;
}
