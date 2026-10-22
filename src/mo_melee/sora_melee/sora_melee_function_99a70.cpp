#pragma force_active on
#include <types.h>

extern "C" void fn_27_9FB70(void*);
extern "C" void fn_27_9FB88(void*, int);
extern "C" void fn_27_9FBC8(u32*, u32, u32, u32);

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
    virtual void process(int*);
};

class SelfClass {
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
    virtual void v10() {}
    virtual int calc(int, int, int, int, int, int, int);
    char _pad[0x58];
    TargetClass* target;
};

struct State {
    int flag;
    int pad;
    int data[3];
};

extern "C" void fn_27_99A70(SelfClass* self, int a1, int a2, int a3, int a4, int a5, int a6) {
    State state;
    state.flag = -1;
    int result = self->calc(a1, a2, a4, a5, 0, a6, 0);
    if (result != 0) {
        fn_27_9FB70(state.data);
        fn_27_9FBC8((u32*)state.data, (u32)a1, (u32)result, (u32)a3);
        self->target->process(state.data);
        fn_27_9FB88(state.data, -1);
    }
}
