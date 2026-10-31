#include <types.h>
#pragma force_active on

class soVirtBase {
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
    virtual void v10(u32 a, u32 b);
};

struct soNodeHolder {
    u8 pad[0x40];
    soVirtBase* obj;
};

struct soOwner {
    u8 pad[0xD8];
    soNodeHolder* holder;
};

extern "C" {
void fn_27_18FAA0(void* p1, soOwner* p2, s32 p3);
}

extern "C" void fn_27_18FAA0(void* p1, soOwner* p2, s32 p3) {
    if (p3 == 0xfa) {
        return;
    }
    if (p3 >= 0xfa || p3 != 0x42) {
        p2->holder->obj->v10(0, 0);
    }
}
