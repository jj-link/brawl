#include <types.h>
#pragma force_active on

class soSeq {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual u32 v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
};

extern "C" int fn_27_2ACB8C(soSeq* p, int x);

extern "C" void* fn_27_2AE6C0(soSeq* p, int x) {
    int idx = fn_27_2ACB8C(p, x);
    if (p->v4() != 1 && idx >= 0) {
        p->v13();
    }
    return (char*)p + idx * 12 + 12;
}
