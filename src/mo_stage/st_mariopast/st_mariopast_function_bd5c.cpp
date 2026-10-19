#pragma force_active on
typedef unsigned char u8;

extern "C" u8* fn_48_BD5C(u8* obj, int idx) {
    int i = (*(int*)(obj + 8) >> 26) + idx;
    if (i >= 0x13) {
        i -= 0x13;
    }
    return obj + i * 0xa0 + 0xc;
}
