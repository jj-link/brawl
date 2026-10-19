#pragma force_active on
extern "C" const float lbl_48_rodata_44;

extern "C" void fn_48_3E2C(char* obj) {
    unsigned int flags = *(unsigned int*)(obj + 0x74);
    float zero = lbl_48_rodata_44;
    *(float*)(obj + 0x60) = zero;
    *(float*)(obj + 0x64) = zero;
    *(float*)(obj + 0x68) = zero;
    *(unsigned int*)(obj + 0x74) = flags & ~31u;
}
