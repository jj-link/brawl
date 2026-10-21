#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

union Flags {
    u16 value;
    struct {
        u16 high : 2;
        u16 enabled : 1;
        u16 low : 13;
    } bits;
};

struct Joint {
    u8 pad0[0x52];
    u16 flags;
    u8 pad54[4];
    void* owner;
};

struct Collision {
    u8 pad0[6];
    u16 count;
};

struct Object {
    u8 pad0[0x4C];
    Collision* collision;
    u8 pad50[0x114];
    u8* state;
    Joint* joint;
};

extern "C" Joint* getJoint__11grCollisionFUs(Collision*, unsigned int);

extern "C" void fn_73_2F30(Object* self) {
    if (self->joint) {
        u16 flags = 0;
        if (*self->state == 0x13) {
            Flags bits;
            bits.value = 0;
            bits.bits.enabled = 1;
            flags = bits.value;
        }
        self->joint->flags = flags;
    } else {
        u32 count;
        Collision* collision = self->collision;
        if (collision) {
            count = collision->count;
            u32 i;
            Joint* joint;
            for (i = 0; i != count; ++i) {
                joint = getJoint__11grCollisionFUs(collision, i);
                if (joint && joint->owner == self)
                    break;
            }
            if (i != count)
                self->joint = joint;
        }
    }
}
