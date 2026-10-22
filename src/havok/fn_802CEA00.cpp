#include <types.h>
#pragma force_active on

class Foo {
public:
    virtual void v0();
    virtual void v1(char* a, int b, void* c);
    virtual void v2();
    virtual void v3(char* a, int b, u32 c);
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

extern char lbl_804103D0[];

extern "C" void fn_802CEA00(void* arg0, void* arg1) {
    Foo* obj = (Foo*)arg1;
    obj->v1(lbl_804103D0 + 0xF, 1, arg0);
    obj->v3(lbl_804103D0 + 0x17, 1, *(u32*)((u8*)arg0 + 0x14));
    obj->v6();
}
