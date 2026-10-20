#include <types.h>
#pragma force_active on

struct fn27VirtIface {
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
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
};

extern "C" {
void fn_27_8CC10(u8* self) {
    u8* a = *(u8**)(self + 0x60);
    u8* b = *(u8**)(a + 0xd8);
    fn27VirtIface* c = *(fn27VirtIface**)(b + 0x8);
    c->v21();
}
}
