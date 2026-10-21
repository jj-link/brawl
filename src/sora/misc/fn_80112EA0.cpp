#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct grCollisionLine {
    u8 m_padding[0x11];
    u8 m_value : 8;
};

struct grCollisionJoint {
    u16 m_lineCount;
    u8 m_padding[0x32];
    grCollisionLine* m_line;
};

extern "C" grCollisionLine* getLine__16grCollisionJointFUs(grCollisionJoint* self, u32 index) {
    return self->m_line + self->m_lineCount + index;
}
