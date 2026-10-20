#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct Elem {
    s32 a;
    s32 b;
    s32 c;
};

struct Obj {
    u8 pad[0x18];
    s32 field18;
};

extern "C" Elem* fn_27_F5244(Obj* self, s32 idx) {
    s32 i = (self->field18 >> 29) + idx;
    if (i >= 3) {
        i -= 3;
    }
    return (Elem*)((char*)self + 0x1c + i * 12);
}
