#include <types.h>
#pragma force_active on

struct FrameEntry {
    u8 _pad[0xD];
    s8 value;
    u8 _pad2[2];
};

class soWork {
public:
    virtual int f0();
    virtual int f1();
    virtual bool check();

    u32 m_unk04;
    FrameEntry* m_entries;
    s32 m_index;
};

extern "C" bool fn_27_9A788(soWork* self) {
    if (!self->check()) {
        self->m_index = -1;
        return false;
    } else {
        self->m_index = self->m_entries[self->m_index].value;
        return true;
    }
}
