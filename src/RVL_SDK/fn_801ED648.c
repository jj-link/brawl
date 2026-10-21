#pragma force_active on
extern unsigned char* __GXData;

void* fn_801ED648(unsigned int arg0) {
    if (arg0 >= 0x14) {
        return 0;
    }
    return __GXData + (arg0 << 4) + 0x3D8;
}
