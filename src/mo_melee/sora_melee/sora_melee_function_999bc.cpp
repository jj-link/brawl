#pragma force_active on
#include <types.h>

extern "C" {
void fn_27_9FB70(void*);
void fn_27_9FB88(void*, int);
void fn_27_9FBC8(u32*, u32, u32, u32);
}

struct LocalState {
    int f0;
    int f1;
    int f2;
};

class TargetClass {
public:
    virtual void v0() {}
    virtual void v1() {}
    virtual void v2() {}
    virtual void v3() {}
    virtual void v4() {}
    virtual void v5() {}
    virtual void v6() {}
    virtual void v7() {}
    virtual void v8() {}
    virtual void v9() {}
    virtual void process(LocalState*);
};

class SelfClass {
public:
    virtual void v0() {}
    virtual void v1() {}
    virtual void v2() {}
    virtual void v3() {}
    virtual void v4() {}
    virtual void v5() {}
    virtual int calc(int, int, int, int, int);
};

struct SelfLayout {
    void** vtable;
    char _pad[0x58];
    TargetClass* target;
};

extern "C" void fn_27_999BC(SelfClass* self, int a1, int a2, int a3, int a4, int a5) {
    int result = self->calc(a1, a3, a4, a5, -1);
    if (result != 0) {
        LocalState local;
        fn_27_9FB70(&local);
        fn_27_9FBC8((u32*)&local, (u32)a1, (u32)result, (u32)a2);
        ((SelfLayout*)self)->target->process(&local);
        fn_27_9FB88(&local, -1);
    }
}
