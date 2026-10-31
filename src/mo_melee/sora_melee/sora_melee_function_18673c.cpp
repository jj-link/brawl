#include <types.h>
#pragma force_active on

class fn27VirtObj {
public:
    virtual ~fn27VirtObj();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void call12(u32 a, u32 b);
};

struct fn27Sub {
    u8 pad[0x40];
    fn27VirtObj* obj;
};

struct fn27Self {
    u8 pad[0xd8];
    fn27Sub* sub;
};

extern "C" {
void fn_27_18673C(s32 unused, fn27Self* self, s32 id) {
    if (id != 0xd7) {
        self->sub->obj->call12(0, 0);
    }
}
}
