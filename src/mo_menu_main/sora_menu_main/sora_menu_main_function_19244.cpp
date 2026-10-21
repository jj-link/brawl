#include <types.h>
#pragma force_active on

extern char lbl_2_data_23B4[];
extern "C" void printf__5MuMsgFUlPCce(void* msg, u32 index, const char* fmt, ...);

struct SelfObj {
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
    virtual void v13(u32 a);
};

extern "C" void fn_2_19244(char* self) {
    ((SelfObj*)*(void**)(self + 0x654))->v13(*(u32*)(*(char**)(self + 0x650)));
    ((SelfObj*)*(void**)(self + 0x654))->v13(*(u32*)(*(char**)(self + 0x650) + 4));

    for (int i = 0; i < 5; i++) {
        printf__5MuMsgFUlPCce(*(void**)(self + 0x694), i, lbl_2_data_23B4);
    }
}
