#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_8018CCF0(u8* out, unsigned short a, unsigned int b) {
    out[0] = 0x10;
    out[1] = 0;
    out[2] = 0;
    out[3] = a >> 8;
    out[4] = a;
    out[5] = b >> 24;
    out[6] = b >> 16;
    out[7] = b >> 8;
    out[8] = b;
}
