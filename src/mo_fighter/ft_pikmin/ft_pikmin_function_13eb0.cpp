#include <stddef.h>
#pragma force_active on

extern "C" int fn_113_243CC(void*);
extern "C" void* fn_113_244FC(void*);

struct Local {
    int a;
    unsigned char b;
};

class Obj {
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
    virtual void method(int a, int b, Local* c);
};

extern "C" void fn_113_13EB0(void* a1, void* a2, int a3) {
    if (a3 != 0xf1 && (a3 >= 0xf1 || a3 >= 0x3d || a3 < 0x39)) {
        void* ptr = *(void**)((char*)a1 + 4);
        if (fn_113_243CC(ptr) <= 0) return;
        
        Local local;
        local.a = 0x457;
        local.b = 0;
        
        int field = *(int*)((char*)fn_113_244FC(*(void**)((char*)a1 + 4)) + 0x28);
        void* obj = *(void**)((char*)(*(void**)((char*)a2 + 0xd8)) + 0x54);
        ((Obj*)obj)->method(1, field, &local);
    }
}