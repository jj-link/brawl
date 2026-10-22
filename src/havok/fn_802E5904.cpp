#pragma force_active on
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

class Obj {
public:
    virtual void v0(s32 arg);
    u16 m_4;
    s16 m_6;
};

struct Self {
    u8 _pad[0x100];
    Obj* m_100;
};

extern "C" void fn_802E5904(Self* self, Obj* arg) {
    if (arg != 0 && arg->m_4 != 0) {
        arg->m_6 = arg->m_6 + 1;
    }
    Obj* child = self->m_100;
    if (child != 0 && child->m_4 != 0) {
        child->m_6 -= 1;
        if (child->m_6 == 0 && child != 0) {
            child->v0(1);
        }
    }
    self->m_100 = arg;
}
