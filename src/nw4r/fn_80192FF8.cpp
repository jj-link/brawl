#include <types.h>
#pragma force_active on

extern f32 lbl_805A31A8;

struct Obj {
    u8 pad0[0x14];
    u32 flags;
    u8 pad1[0x2c - 0x18];
    f32 m_x;
    f32 m_y;
    f32 m_z;
};

extern "C" {

void fn_80192FF8(Obj** arg0, f32 farg0, f32 farg1, f32 farg2) {
    Obj* obj = *arg0;
    u32 flags;
    if (obj == 0) {
        return;
    }
    if (lbl_805A31A8 == farg0 && lbl_805A31A8 == farg1 && lbl_805A31A8 == farg2) {
        obj->flags |= 4;
    } else {
        obj->flags &= ~4u;
    }
    flags = obj->flags;
    if ((flags & 2) && (flags & 4) && (flags & 8)) {
        obj->flags = flags | 1;
    } else {
        obj->flags &= ~1u;
    }
    obj->m_x = farg0;
    obj->m_y = farg1;
    obj->m_z = farg2;
}

}
