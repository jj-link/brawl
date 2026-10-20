#include <types.h>
#pragma force_active on

struct S12 {
    u32 a;
    u32 b;
    s16 c;
    s16 d;
};

class T {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual S12* target(void* a) = 0;
};

extern "C" void fn_27_11C61C(void* pThis, void* a, void* b) {
    S12* r1 = ((T*)pThis)->target(a);
    S12* r2 = ((T*)pThis)->target(b);
    r2->a = r1->a;
    r2->b = r1->b;
    r2->c = r1->c;
    r2->d = r1->d;
}
