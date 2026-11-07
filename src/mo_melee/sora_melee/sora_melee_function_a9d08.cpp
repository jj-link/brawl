#include <types.h>
#pragma force_active on

class soWaitObj {
public:
    virtual bool vf0();
    u8 m_pad0[0x8 - 0x4];
    u8 m_counterBuf[0x14 - 0x8];
    s32 m_0x14;
};

struct Obj {
    u8 pad0[0x20];
    u32 context;
    soWaitObj* base;
    u32 pad28;
    s32 count;
};

extern "C" bool fn_27_A967C(soWaitObj* self, u32 a, u32 b);

extern "C" bool fn_27_A9D08(Obj* obj, s32 index, u32 c) {
    u32 flag;

    if (index == -2) {
        flag = 0;
    } else if (index < 0) {
        flag = 1;
    } else {
        flag = obj->count <= index;
    }

    if (flag == 1)
        return false;

    if (index == -2)
        return false;

    return fn_27_A967C(obj->base + index, obj->context, c);
}
