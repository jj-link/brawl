#include <types.h>
#pragma force_active on

class soWaitObj {
public:
    virtual bool vf0();

    u8 m_pad0[0x8 - 0x4];
    u8 m_counterBuf[0x14 - 0x8];
    s32 m_0x14;
};

struct Object {
    u8 pad0[0x20];
    void* context;
    soWaitObj* nodes;
    u32 unk28;
    s32 count;
};

extern "C" bool fn_27_A9710(soWaitObj*, u32, void*);

extern "C" u32 fn_27_A9D74(Object* self, s32 index, void* arg2) {
    u32 invalid;

    if (index == -2) {
        invalid = 0;
    } else if (index < 0) {
        invalid = 1;
    } else {
        invalid = self->count <= index;
    }

    if (invalid == 1) {
        return 0;
    }

    if (index == -2) {
        return 0;
    }

    return fn_27_A9710(
        self->nodes + index,
        (u32)self->context,
        arg2
    );
}
