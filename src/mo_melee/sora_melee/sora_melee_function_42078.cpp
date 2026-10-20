#include <types.h>
#pragma force_active on

class Lookup {
public:
    virtual void f0();
    virtual u32* getWork(s32 index);
};

struct Holder {
    u8 pad0[4];
    s16 m_index;
    u8 pad1[0x33 - 6];
    u8 m_flag;
};

extern "C" void fn_27_42078(Holder* self, Lookup* lookup, s32 offset, u32 value) {
    *lookup->getWork(self->m_index + offset) = value;
    self->m_flag = 1;
}
