#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct grCollisionLine {
    u8 padding[0x11];
    u8 value : 8;
};

struct grCollisionJoint {
    u16 unk;
    u16 lineCount;
};

struct Collision {
    u8 padding[0x160];
    grCollisionJoint* joint;
};

extern "C" grCollisionLine* getLine__16grCollisionJointFUs(grCollisionJoint*, u32);

extern "C" void fn_66_12E50(Collision* self, u32 value) {
    if (self->joint) {
        u32 i = 0;
        u32 count = self->joint->lineCount;
        for (; i != count; ++i) {
            grCollisionLine* line = getLine__16grCollisionJointFUs(self->joint, i);
            if (line) {
                line->value = value;
            }
        }
    }
}
