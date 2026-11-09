#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern "C" int fn_8006BCA8(u8* dst, const u16* src) {
    int count = 0;
    u8* out = dst;
    while (*src != 0) {
        if (*src <= 0x7F) {
            *out = (u8)*src;
            out++;
            src++;
        } else if (*src <= 0x7FF) {
            out[0] = (u8)(0xC0 | ((*src >> 6) & 0x1F));
            out[1] = (u8)(0x80 | (*src & 0x3F));
            src++;
            out += 2;
        } else {
            out[0] = (u8)(0xE0 | ((*src >> 12) & 0x0F));
            out[1] = (u8)(0x80 | ((*src >> 6) & 0x3F));
            out[2] = (u8)(0x80 | (*src & 0x3F));
            src++;
            out += 3;
        }
        count++;
    }
    *out = 0;
    return count;
}