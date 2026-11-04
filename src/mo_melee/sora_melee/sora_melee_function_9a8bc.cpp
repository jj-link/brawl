#include <types.h>
#pragma force_active on

class Lst {
public:
    virtual void f0();
    virtual s32* getAt(s32 idx);
    virtual void f2();
    virtual s32 size();
};

struct Owner {
    char pad0[0x74];
    s32 m_id;
    Lst m_list;
};

extern "C" s32 fn_27_9A8BC(Owner* self, s32 arg1) {
    if (self->m_id != -1 && self->m_id == arg1) {
        return 1;
    }
    for (s32 i = 0; i < self->m_list.size(); i++) {
        if (arg1 == *self->m_list.getAt(i)) {
            return 1;
        }
    }
    return 0;
}
