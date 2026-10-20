#pragma force_active on
typedef signed int s32;
typedef unsigned char u8;

struct Table {
    u8 pad[8];
    s32 val;
};

extern "C" u8* fn_27_1CFAD8(Table* t, s32 idx) {
    s32 i = (t->val >> 26) + idx;
    if (i >= 0x11) {
        i -= 0x11;
    }
    return (u8*)t + i * 12 + 12;
}
