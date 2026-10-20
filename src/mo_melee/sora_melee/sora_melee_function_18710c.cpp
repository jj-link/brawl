#include <types.h>
#pragma force_active on

class VObj {
public:
    virtual void v0(int);
    virtual void v1(int);
    virtual void v2(int);
    virtual void v3(int);
    virtual void v4(int);
    virtual void v5(int);
    virtual void v6(int);
    virtual void v7(int);
    virtual void v8(int);
    virtual void v9(int);
    virtual void v10(int);
    virtual void v11(int);
    virtual void v12(int);
    virtual void v13(int);
    virtual void v14(int);
    virtual void v15(int);
    virtual void v16(int);
    virtual void v17(int);
    virtual void v18(int);
    virtual void v19(int);
    virtual void v20(int);
    virtual void v21(int);
};

extern "C" void fn_27_18710C(int unused, char* self, int code) {
    if (code != 0x42) {
        char* obj = *(char**)(self + 0xd8);
        VObj* y = *(VObj**)(obj + 0x40);
        y->v19(1);
        obj = *(char**)(self + 0xd8);
        y = *(VObj**)(obj + 0x40);
        y->v17(0);
    }
}
