#include <types.h>
#pragma force_active on

struct Pair {
    u32 a;
    u32 b;
};

struct Quad {
    Pair p;
    Pair q;
};

struct Data {
    u32 a;
    u32 b;
    u32 c;
    Quad q;
    u8 h;
    u8 i;
};

class Base {
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
    virtual Data* getNoArg();
};

class BaseIdx {
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
    virtual Data* slot26(int);
};

extern "C" void fn_27_EC07C(Base* self, u32 unused, u32 idx) {
    Data* src = self->getNoArg();
    Data* dst = ((BaseIdx*)self)->slot26(idx);
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->q = src->q;
    dst->h = src->h;
    dst->i = src->i;
}
