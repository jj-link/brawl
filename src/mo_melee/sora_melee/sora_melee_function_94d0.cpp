#pragma force_active on
#include <types.h>

extern "C" void fn_801EC158(void*);
extern "C" void fn_801EC1B8(void*, void*, void*);

extern char* g_soWorld;
extern const f32 lbl_27_rodata_300;
extern const f32 lbl_27_rodata_304;

#define V(n) virtual void unused##n();

struct Vec3 {
    f32 x, y, z;
};

struct ObjA {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7)
    virtual u32 get(f32*);
};

struct ObjB {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77)
    virtual u32 flags();
    V(79) V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87)
    virtual u32 result();
    V(89) V(90) V(91) V(92)
    virtual Vec3 pos(s32);
};

struct Table {
    char pad[0x4C];
    ObjA* a;
    char pad2[4];
    ObjB* b;
};

struct Owner {
    char pad[0xD8];
    Table* table;
};

struct Matrix {
    u32 w[12];
};

struct Pad {
    u32 a, b;
};

struct Self : Pad {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    virtual Vec3 pos(s32);

    char pad0[0x44];
    f32 scale;
    Matrix matrix;
    char pad1[0x44];
    Owner* owner;
};

#undef V

extern "C" void fn_27_94D0(Self* self, Matrix* arg) {
    f32 v8[2];
    f32 m[12];

    self->matrix = *arg;
    u32 r = self->owner->table->a->get(v8);

    if (r == 1 || lbl_27_rodata_300 != self->scale) {
        fn_801EC158(m);

        if (r == 1) {
            m[3] = v8[0];
            m[7] = v8[1];
            m[11] = lbl_27_rodata_304;
        }

        if (lbl_27_rodata_300 != self->scale &&
            (u8)g_soWorld[0xD] != 0) {
            f32 z;

            if (self->owner->table->b->result() == 1 &&
                !(self->owner->table->b->flags() & 0x10)) {
                z = self->owner->table->b->pos(0).z;
            } else {
                z = self->pos(0).z;
            }

            m[2] *= self->scale;
            m[6] *= self->scale;
            m[10] *= self->scale;
            m[11] = z;
        }

        fn_801EC1B8(arg, m, arg);
    }
}
