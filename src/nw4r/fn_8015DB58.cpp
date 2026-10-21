#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
struct Object { unsigned char pad[0x18]; u16 value; };
extern "C" {
extern u16 lbl_8059E868;
}
inline int single(u32 c) {
    if (c > 0xFF) return 0;
    return (c >= 0x20 && c <= 0x7E) || (c >= 0xA1 && c <= 0xDF);
}
inline int doubleChar(u32 c) {
    u32 hi = (c >> 8) & 0xFF;
    u32 lo = c & 0xFF;
    return hi >= 0x81 && hi <= 0x98 && lo >= 0x40 && lo <= 0xFC;
}
extern "C" int fn_8015DB58(Object* self, u32 c) {
    u32 lo;
    u16 old = self->value;
    u32 hi;
    self->value = 0xFFFF;
    int valid;
    switch (lbl_8059E868) {
    case 0:
        valid = c >= 0x20 && c <= 0xFF;
        break;
    case 1:
        valid = single(c) || (hi = (c >> 8) & 0xFF, lo = c & 0xFF, hi >= 0x81 && hi <= 0x98 && lo >= 0x40 && lo <= 0xFC);
        break;
    }
    u16 result = valid ? c : self->value;
    if (result != 0xFFFF) {
        self->value = c;
        return 1;
    }
    self->value = old;
    return 0;
}
