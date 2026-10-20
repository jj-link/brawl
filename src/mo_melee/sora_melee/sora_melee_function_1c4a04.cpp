#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct Fn27Struct {
    u8 pad[0x18];
    s32 field18;
};

extern "C" {
void* fn_27_1C4A04(Fn27Struct* p, s32 idx) {
    s32 i = (p->field18 >> 28) + idx;
    if (i >= 5) {
        i -= 5;
    }
    return (u8*)p + 0x1c + i * 12;
}
}
