#include <types.h>
#pragma force_active on

class soFlagObj {
public:
    char pad[0x20];
    float m_value;
    u8 m_flag;
};

class soVirtHolder {
public:
    virtual void v0();
    virtual soFlagObj* getObj(u32 idx);
    virtual void v2();
    virtual void v3();
};

class soOuter {
public:
    char pad[0x90];
    soVirtHolder* m_holder;
};

extern "C" {
void fn_27_17B18(soOuter* self, u32 idx, float value) {
    soFlagObj* obj = self->m_holder->getObj(idx);
    if (((obj->m_flag >> 5) & 1) == 0) {
        self->m_holder->getObj(idx)->m_value = value;
    }
}
}
