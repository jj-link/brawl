#pragma force_active on
typedef unsigned char u8;
typedef short s16;
typedef float f32;

extern const f32 lbl_27_rodata_EC0;

struct Obj {
    u8 pad0[0x8];
    f32 f8;
    u8 pad1[0x10];
    s16 s1c;
};

extern "C" void fn_27_C1AD8(Obj* p) {
    p->s1c = -1;
    p->f8 = lbl_27_rodata_EC0;
}
