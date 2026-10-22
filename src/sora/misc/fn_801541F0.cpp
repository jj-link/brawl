#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" u32 NETCalcCRC32(void* p, int size);

extern "C" void* fn_801541F0(u8* arg0, int arg1) {
    u8 var_r5 = arg0[4];
    u8* temp_r31;
    u32 crc;

    if (var_r5 > 5) {
        var_r5 = 0;
    }
    if (var_r5 < (u8)arg1) {
        return 0;
    }
    temp_r31 = arg0 + arg1 * 0xC;
    crc = NETCalcCRC32(arg0 + *(u32*)(temp_r31 + 8), *(int*)(temp_r31 + 0xC));
    if (*(u32*)(temp_r31 + 0x10) != crc) {
        return 0;
    }
    return arg0 + *(u32*)(temp_r31 + 8);
}
