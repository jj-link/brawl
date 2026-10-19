#include <types.h>
#pragma force_active on

struct Target {
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
    virtual void call(void*);
};

struct Elem {
    char pad[0x10];
    void* f10;
};

struct Outer {
    char pad[0x2bc];
    Elem* arr[5];
};

struct Ctx {
    char pad1[0x64c];
    Outer* f64c;
    char pad2[4];
    Target* f654;
};

extern "C" void fn_2_2BBF8(Ctx* ctx) {
    for (u32 i = 0; i < 5; i++) {
        ctx->f654->call(ctx->f64c->arr[i]->f10);
    }
}
