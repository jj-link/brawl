#pragma force_active on
extern "C" float lbl_79_rodata_44;

extern "C" void fn_79_54F8(char* obj) {
    unsigned int v = *(unsigned int*)(obj + 0x74);
    float zero = lbl_79_rodata_44;
    *(float*)(obj + 0x60) = zero;
    *(float*)(obj + 0x64) = zero;
    *(float*)(obj + 0x68) = zero;
    *(unsigned int*)(obj + 0x74) = v & ~31u;
}
