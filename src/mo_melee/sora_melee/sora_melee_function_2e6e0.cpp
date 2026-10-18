#include <types.h>
#pragma force_active on

class fn27Target {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual s32 fn19(void* self, void* arg);
};

class fn27Owner {
public:
    u8 pad[0x44];
    fn27Target* m44;
};

extern "C" s32 fn_27_2E6E0(fn27Owner* self, void* arg) {
    return self->m44->fn19(self, arg);
}
