#pragma force_active on
typedef unsigned char u8;

extern "C" int fn_27_9ECD8(u8* self) {
    u8 bit = (self[0x135] >> 3) & 1;
    return bit != 0;
}
