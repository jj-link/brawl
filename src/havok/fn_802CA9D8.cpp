#pragma force_active on
typedef float f32;
typedef signed char s8;
typedef unsigned int u32;

struct Dst {
    int unk0;
    f32 unk4;
    s8 unk8;
    s8 pad9[7];
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
};

struct Src {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

extern "C" void fn_802CA9D8(Dst* dst, const Src* src) {
    s8 value = dst->unk8;
    f32 previous;
    f32 incoming;
    if (((u32)(-value | value) >> 31) != 0) {
        previous = dst->unk2C;
        incoming = src->unk1C;
        if (incoming < previous) {
        } else {
            return;
        }
    }

    dst->unk8 = 1;
    dst->unk10 = src->unk0;
    dst->unk14 = src->unk4;
    dst->unk18 = src->unk8;
    dst->unk1C = src->unkC;
    dst->unk20 = src->unk10;
    dst->unk24 = src->unk14;
    dst->unk28 = src->unk18;
    dst->unk4 = dst->unk2C = src->unk1C;
}