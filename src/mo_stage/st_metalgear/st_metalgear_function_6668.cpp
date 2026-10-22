#pragma force_active on
#include <types.h>
#include <gr/collision/gr_collision_line.h>

extern "C" grCollisionLine* getLine__16grCollisionJointFUs(void* joint, u32 index);

struct MatData {
    u8 pad0;
    u8 unk1;
    u8 pad2;
    u8 unk3;
};

struct Self {
    u8 padding[0x180];
    void* jointA;
    void* jointB;
    MatData* mat;
};

extern "C" void fn_71_6668(Self* self) {
    if (self->jointA != NULL) {
        if (self->mat->unk1 != 6) {
            grCollisionLine* line = getLine__16grCollisionJointFUs(self->jointA, 0);
            line->m_isThroughable = true;
        } else {
            grCollisionLine* line = getLine__16grCollisionJointFUs(self->jointA, 0);
            line->m_isThroughable = false;
        }
        if (self->mat->unk3 != 6) {
            grCollisionLine* line = getLine__16grCollisionJointFUs(self->jointB, 0);
            line->m_isThroughable = true;
        } else {
            grCollisionLine* line = getLine__16grCollisionJointFUs(self->jointB, 0);
            line->m_isThroughable = false;
        }
    }
}
