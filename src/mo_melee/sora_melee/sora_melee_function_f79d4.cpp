#pragma force_active on
typedef int s32;

struct fn27Obj {
    char pad[0x18];
    s32 unk18;
};

extern "C" void* fn_27_F79D4(fn27Obj* p, s32 idx) {
    const s32 v = p->unk18 >> 25;
    s32 i = v + idx;
    if (i >= 0x25) i -= 0x25;
    return (char*)p + i * 12 + 0x1c;
}
