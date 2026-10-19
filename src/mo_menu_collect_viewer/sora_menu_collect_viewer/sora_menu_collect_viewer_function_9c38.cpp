#include <types.h>
#pragma force_active on

class gfTask {
public:
    u8 pad[0x104];
    s32 m_state;
    void exit();
};

struct Owner {
    u8 pad0[0x124];
    s32 f124;
    u8 pad1[0x750 - 0x128];
    gfTask* f750;
};

extern "C" {
s32 fn_6_9C38(Owner* self) {
    gfTask* task = self->f750;
    if (task->m_state == 3) {
        task->exit();
        self->f750 = nullptr;
        return 7;
    }
    return self->f124;
}
}
