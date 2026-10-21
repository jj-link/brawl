#include <types.h>
#pragma force_active on

extern "C" void fn_27_A9168(void*);

struct fn27A9BE4Obj {
    char pad0[0x24];
    char* m_base;
    char pad28[4];
    s32 m_count;
};

extern "C" void fn_27_A9BE4(fn27A9BE4Obj* self, s32 index) {
    u32 flag;

    if (index == -2) {
        flag = 0;
    } else if (index < 0) {
        flag = 1;
    } else {
        flag = self->m_count <= index;
    }

    if (flag != 1) {
        if (index == -2) {
            s32 offset;
            s32 i;
            i = 0;
            offset = 0;
            for (; i < self->m_count; ++i) {
                fn_27_A9168(self->m_base + offset);
                offset += 0x18;
            }
        } else {
            fn_27_A9168(self->m_base + index * 0x18);
        }
    }
}
