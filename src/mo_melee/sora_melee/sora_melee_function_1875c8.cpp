#include <types.h>
#pragma force_active on

class VObj {
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
    virtual void v12(s32, s32);
};

extern "C" {
void fn_27_1875C8(void* a, char* b, s32 code) {
    if (code != 0xEA) {
        VObj* obj = *(VObj**)(*(char**)(b + 0xD8) + 0x40);
        obj->v12(0, 0);
    }
}
}
