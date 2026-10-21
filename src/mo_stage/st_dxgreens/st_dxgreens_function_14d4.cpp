#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" u8 fn_79_14D4(char* self) {
    u8 result = 0;
    for (u8 i = 0; i < 6; i++) {
        if (result < *(u32*)(self + i * 12 + 0x6A4))
            result = (u8)*(u32*)(self + i * 12 + 0x6A4);
    }
    return result;
}
