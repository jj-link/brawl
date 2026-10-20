#pragma force_active on
typedef int s32;

struct Foo {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern "C" {
void* fn_27_295A8C(Foo* p, s32 idx)
{
    s32 i = (p->unk8 >> 28) + idx;
    if (i >= 6) {
        i -= 6;
    }
    return (char*)p + 0xc + i * 4;
}
}
