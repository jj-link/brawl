#pragma force_active on
typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern "C" {
void* fn_27_1AFC24(Obj* r3, s32 r4) {
    s32 i = (r3->unk8 >> 28) + r4;
    if (i >= 4) {
        i -= 4;
    }
    return (char*)r3 + i * 4 + 12;
}
}
