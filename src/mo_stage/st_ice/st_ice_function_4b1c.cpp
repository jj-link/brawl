#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct grCollisionLine {
    u8 padding[0x11];
    u8 material : 8;
};

struct grCollisionJoint {
    u16 unk;
    u16 lineCount;
};

struct Ice {
    u8 padding[0x1b0];
    grCollisionJoint* joint;
};

extern "C" grCollisionLine* getLine__16grCollisionJointFUs(grCollisionJoint*, u32);

extern "C" void fn_62_4B1C(Ice* self, u32 material) {
    if (self->joint) {
        u32 i;
        u32 count = self->joint->lineCount;
        for (i = 0; i != count; ++i) {
            grCollisionLine* line = getLine__16grCollisionJointFUs(self->joint, i);
            if (line) {
                line->material = material;
            }
        }
    }
}
