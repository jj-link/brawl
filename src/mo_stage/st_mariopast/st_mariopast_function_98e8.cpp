#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct grCollisionLine {
    u8 padding[15];
    u8 unusedHigh : 3;
    u8 disabled : 1;
    u8 unusedMiddle : 2;
    u8 locked : 1;
    u8 unusedLow : 1;

    bool isLocked() const { return locked; }
    void setDisabled(bool value) { disabled = value; }
};

struct grCollisionJoint {
    u16 unk;
    u16 lineCount;
    u8 padding[0x5c];
};

struct Collision {
    u8 padding[0x15c];
    u32 jointCount;
    u32 unk;
    grCollisionJoint* joints;
};

extern "C" grCollisionLine* getLine__16grCollisionJointFUs(grCollisionJoint*, u32);

extern "C" void fn_48_98E8(Collision* self, u32 index, bool enable) {
    if (!self->joints || index >= self->jointCount)
        return;

    grCollisionJoint* joint = &self->joints[index];
    u32 count = joint->lineCount;
    for (u32 i = 0; i < count; ++i) {
        grCollisionLine* line = getLine__16grCollisionJointFUs(joint, i);
        if (line) {
            if (enable) {
                if (!line->isLocked())
                    line->setDisabled(false);
            } else {
                line->setDisabled(true);
            }
        }
    }
}
