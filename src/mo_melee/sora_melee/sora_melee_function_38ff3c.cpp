#pragma force_active on
typedef signed int s32;
typedef unsigned char u8;

struct fn27Obj {
    u8 pad[0x18];
    s32 unk18;
};

extern "C" void* fn_27_38FF3C(struct fn27Obj* p, s32 idx) {
    s32 s = p->unk18 >> 26;
    s32 i = s + idx;
    i = (i >= 19) ? i - 19 : i;
    return (u8*)p + i * 12 + 0x1c;
}
