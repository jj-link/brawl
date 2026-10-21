#include <types.h>
#pragma force_active on

struct Result {
    s32 a;
    s32 b;
    s16 c;
    s16 d;
};

class C {
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
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual Result* f(int) = 0;
};

extern "C" void fn_27_1D231C(C* self, int a, int b) {
    Result* x = self->f(a);
    Result* y = self->f(b);
    y->a = x->a;
    y->b = x->b;
    y->c = x->c;
    y->d = x->d;
}
