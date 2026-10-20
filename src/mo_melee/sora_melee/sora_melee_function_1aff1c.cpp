#pragma force_active on
typedef int s32;

struct Fn27Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern "C" {
s32* fn_27_1AFF1C(Fn27Obj* p, s32 idx)
{
    s32 t = p->unk8 >> 26;
    s32 i = t + idx;
    if (i >= 26) {
        i -= 26;
    }
    return (s32*)((char*)p + i * 4 + 12);
}
}
