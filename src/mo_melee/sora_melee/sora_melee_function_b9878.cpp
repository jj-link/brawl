#include <types.h>
#pragma force_active on

extern "C" {

class ArrIf {
public:
    virtual void v0() = 0;
    virtual s32& at(s32 i) = 0;
    virtual void v1() = 0;
    virtual s32 size() = 0;
};

struct Obj {
    u8 pad[0x40];
    ArrIf* m_arr;
};

bool fn_27_B9878(Obj* self, s32 p) {
    s32 s = self->m_arr->size();
    for (s32 i = 0; i < s; i++) {
        if (self->m_arr->at(i) == p)
            return true;
    }
    return false;
}

}
