#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

extern "C" s32 fn_800C84FC();
extern "C" u8 fn_800C851C();
extern "C" u8 fn_800C8548();

extern "C" s32 fn_800D9D4C(int self, int slot, s32* out32, u8* out2, s8* out4) {
    u8* e;
    u8 idx = fn_800C8548();
    if (idx == 0xFF) {
        u8 l = fn_800C851C();
        if (l == 0xFF) l = 4;
        e = (u8*)(self + l * 0x218 + 0x70);
    } else {
        e = (u8*)(self + idx * 0x218 + 0x70);
        if (!((e[0x78] >> 7) & 1)) {
            u8 l = fn_800C851C();
            if (l == 0xFF) l = 4;
            e = (u8*)(self + l * 0x218 + 0x70);
        }
    }
    u8* p = e + slot * 0xA;
    *out32 = p[0xE7];
    *out2 = p[0xE8];
    u8 l = fn_800C851C();
    if (l == 0xFF) l = 4;
    s32 result = (p[0xE5] == l);
    if (p[0xE4] != 0) result = 0;
    *out4 = (p[0xE4] != 3);
    if (*out32 == 0x3E) *out4 = 0;
    if (fn_800C84FC() == 0) *out4 = 0;
    l = fn_800C851C();
    if (l == 0xFF) l = 4;
    if (l == 4) *out4 = 0;
    if (fn_800C8548() == 0xFF) *out4 = 0;
    idx = fn_800C8548();
    s8* p2;
    if (idx == 0xFF) {
        p2 = 0;
    } else {
        p2 = (s8*)(self + idx * 0x218 + 0x70);
    }
    s32 cnt;
    if (p2 == 0) {
        cnt = 1;
    } else {
        cnt = 0;
        if (p2[0x68] == 1) cnt = 1;
        if (p2[0x69] == 1) cnt++;
        if (p2[0x6A] == 1) cnt++;
        if (p2[0x6B] == 1) cnt++;
    }
    if (cnt < 2) *out4 = 0;
    return result;
}
