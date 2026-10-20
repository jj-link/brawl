#pragma force_active on
typedef unsigned int u32;

struct FooBits {
    u32 pad0 : 6;
    u32 field : 3;
    u32 pad1 : 23;
};

struct Foo {
    u32 unk0;
    u32 unk4;
    FooBits bits;
};

extern "C" void fn_27_FEAB4(Foo* p, u32 v) {
    p->bits.field = v;
}
