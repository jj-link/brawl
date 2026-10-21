#include <types.h>
#pragma force_active on

struct fn27Data {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    u8 e;
};

class fn27Base {
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
    virtual fn27Data* getData(u32 index);
};

extern "C" {
fn27Data* fn_27_E746C(fn27Base* self, u32 a, u32 index)
{
    fn27Data* src = self->getData(a);
    fn27Data* dst = self->getData(index);
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
    return dst;
}
}
