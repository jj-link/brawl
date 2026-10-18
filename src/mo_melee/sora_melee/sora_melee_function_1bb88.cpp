#include <types.h>
#pragma force_active on

class fnArrayBase {
public:
    virtual void vfunc0();
    virtual s32* at(s32 index);
    virtual void vfunc2();
    virtual s32 size();
};

class fnOwner {
public:
    char pad[0x154];
    fnArrayBase* m_arr;
};

extern "C" {
void fn_27_1BB88(fnOwner* self, s32 index, s32 value) {
    if (index >= 0) {
        if (index < self->m_arr->size()) {
            *self->m_arr->at(index) = value;
        }
    }
}
}
