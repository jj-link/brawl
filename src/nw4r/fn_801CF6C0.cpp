#include <types.h>
#pragma force_active on

extern "C" s32 fn_801CD478(void*, s32);
extern "C" void fn_801CD554(void*);
extern "C" s32 fn_801CD5E8(void*, s32, s32, s32, s32);

struct Obj {
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

    char pad[0xD4];
    int member;
};

extern "C" s32 fn_801CF6C0(Obj* self, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    if (a1 == 0) {
        return 0;
    }
    self->v23();
    if (fn_801CD478(&self->member, a1) == 0) {
        return 0;
    }
    if (fn_801CD5E8(&self->member, a5, a4, a2, a3) == 0) {
        fn_801CD554(&self->member);
        return 0;
    }
    return 1;
}
