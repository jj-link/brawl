#include <types.h>
#pragma force_active on

class fnInner {
public:
    virtual void v0(void);
    virtual void v1(void);
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(void);
    virtual void v5(void);
    virtual void v6(void);
    virtual void v7(void);
    virtual void v8(void);
    virtual void v9(void);
    virtual void v10(void);
    virtual void v11(void);
    virtual void v12(void);
    virtual void v13(void);
    virtual void v14(void);
    virtual void v15(void);
    virtual void v16(void);
    virtual void v17(s32);
    virtual void v18(void);
    virtual void v19(s32);
    virtual void v20(void);
};

struct fnMid {
    char pad[0x40];
    fnInner* inner;
};

struct fnObj {
    char pad[0xd8];
    fnMid* mid;
};

extern "C" {
void fn_27_183724(void* unused, fnObj* obj, s32 type) {
    if (type != 0x42) {
        obj->mid->inner->v19(1);
        obj->mid->inner->v17(0);
    }
}
}
