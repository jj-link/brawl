#include <types.h>
#pragma force_active on

struct FnMsg {
    s32 id;
    u8 flag;
};

class FnObjA {
public:
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
    virtual void v17(s32 a, FnMsg* msg) = 0;
    virtual bool v18() = 0;
};

extern "C" void fn_27_1DF3C8(void* unused, u8* self) {
    FnObjA* a = *(FnObjA**)(*(u8**)(self + 0xd8) + 0x8);
    if (a->v18()) {
        FnMsg msg;
        msg.id = 0x839;
        msg.flag = 0;
        FnObjA* b = *(FnObjA**)(*(u8**)(self + 0xd8) + 0x54);
        b->v17(1, &msg);
    }
}
