#include <types.h>
#include <gr/collision/gr_collision.h>
#include <gr/collision/gr_collision_line.h>
#include <mt/mt_coll2d.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern float lbl_805A2A48;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(Vec2f* pos);
};

struct CollisionInfo {
    grCollisionLine* line;
    void* other;
    grCollision* collision;
    u8 byte0;
    u8 byte1;

    bool hasLine() const {
        return line != NULL && other != 0;
    }
    bool isValid() const {
        return hasLine() && collision != NULL;
    }
};

struct State {
    s32 value : 8;
    u32 rest : 24;
};

struct FnObj {
    char pad0[0x8];
    State m_8;
    char pad1[0x54 - 0xc];
    s32 m_54;
    char pad2[0x60 - 0x58];
    Object_vptr_0* m_60;
    char pad3[0x75 - 0x64];
    u8 m_75;
    char pad4[0x104 - 0x76];
    CollisionInfo m_104;
    char pad5[0x154 - 0x114];
    CollisionInfo m_154;
};

extern "C" void fn_80133F64(FnObj* self) {
    clSegment2D seg;
    Vec2f pos;

    if (self->m_8.value == 3) {
        self->m_104 = self->m_154;

        if (self->m_154.isValid()) {
            self->m_154.collision->getSegment(&seg, self->m_154.line);
            if ((self->m_54 >> 24) == 1) {
                pos = seg.m_p0Pos;
                pos.m_x += lbl_805A2A48;
            } else {
                pos = seg.m_p1Pos;
                pos.m_x -= lbl_805A2A48;
            }
            self->m_60->slot3(&pos);
        }
        self->m_154.line = NULL;
        self->m_154.other = 0;
        self->m_154.collision = NULL;
        self->m_154.byte0 = 0;
    }
    self->m_8.value = 1;
    self->m_75 |= 0x80;
}
