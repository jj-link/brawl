#include <types.h>
#pragma force_active on

#define CRC_STEP()                              \
    if (crc & 0x8000) {                         \
        crc <<= 1;                              \
        crc ^= 0x1021;                          \
    } else {                                    \
        crc <<= 1;                              \
    }                                           \
    if (byte & 0x80) {                          \
        crc ^= 1;                               \
    }                                           \
    byte <<= 1;

u16 fn_803D5254(u8 *data, u32 len) {
    u32 i;
    u16 crc;
    u8 byte;
    u16 j;

    for (i = 0, crc = 0; i < len; i++) {
        byte = *data;
        for (j = 0; j < 6; j++) {
            CRC_STEP();
            CRC_STEP();
            CRC_STEP();
            CRC_STEP();
            j += 2;
        }
        data++;
    }
    return crc;
}
