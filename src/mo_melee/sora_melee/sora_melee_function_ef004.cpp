#include <types.h>
#pragma force_active on

struct Pair {
    u32 a;
    u32 b;
};

struct Data {
    u32 a;
    u32 b;
    u32 c;
    u8 d;
    u8 e;
    u8 f;
    u8 g;
    Pair p;
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
    virtual Data* getData(u32 index);
};

extern "C" void fn_27_EF004(Base* self, u32 unused, u32 idx) {
    Data* src = self->getData(unused);
    Data* dst = self->getData(idx);
    *dst = *src;
}
