#include <types.h>
#pragma force_active on

extern "C" void fn_80095990(void* obj, u32* arg);

class fn27Obj {
public:
    u8 pad_0x00[0x28];
    void* m_28;
};

extern "C" {
void fn_27_11E68(fn27Obj* self, u32 arg) {
    if (self->m_28) {
        u32 local = arg;
        fn_80095990(self->m_28, &local);
    }
}
}
