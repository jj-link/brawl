#include <types.h>
#pragma force_active on

class Obj {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7(void* node, s32 idx, s32 flag);
};

extern "C" void fn_8027E8DC(char* arg0) {
    char* p = arg0 + 0x40;
    s32 i;
    void* node;
    for (i = 0x10; i >= 0; i--) {
        while ((node = *(void**)(p + 0x28)) != 0) {
            *(void**)(p + 0x28) = *(void**)node;
            Obj* obj = *(Obj**)(arg0 + 4);
            obj->m7(node, i, 1);
        }
        *(void**)(p + 0x28) = 0;
        *(s32*)(p + 0x6c) = 0;
        p -= 4;
    }
}
