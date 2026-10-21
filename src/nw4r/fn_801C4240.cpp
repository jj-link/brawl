#include <types.h>
#pragma force_active on

class fn801Sub {
public:
    virtual void v0();
    virtual u32 v1(void* self, u32 a, u32 b);
};

struct fn801Owner {
    u8 pad[0xb0];
    fn801Sub* m_obj;
};

extern "C" {
u32 fn_801C4240(fn801Owner* self, u32 a, u32 b) {
    return self->m_obj->v1(self, a, b);
}
}
