#include <types.h>
#pragma force_active on

class fn27VBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void call(u32 a, u32 b);
};

struct fn27Mid {
    u8 pad[0x40];
    fn27VBase* obj;
};

struct fn27Outer {
    u8 pad[0xd8];
    fn27Mid* mid;
};

extern "C" {
void fn_27_1925D4(void* self, fn27Outer* p, s32 msg) {
    if (msg == 0x104) {
        return;
    }
    if (msg < 0x104) {
        if (msg == 0x42) {
            return;
        }
    }
    p->mid->obj->call(0, 0);
}
}
