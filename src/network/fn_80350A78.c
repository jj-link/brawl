#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;
u32 fn_80350A78(u32 *table, u8 *data, u32 size) {
    u32 crc = ~0U;
    u32 i;
    for (i = 0; i < size; i++) {
        crc = (crc >> 8) ^ table[(u8)(crc ^ *data++)];
    }
    return ~crc;
}