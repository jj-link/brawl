#include <types.h>
#pragma force_active on

extern "C" {
extern s32 g_ftManager;
u8 fn_27_10A4B0(void* mgr, s32 id);
u8 fn_27_10AA8C(void* mgr, s32 id, s32 x);
void fn_27_10C0DC(void* mgr, s32 id, u8 flag, s32 b, s32 c);

class VObjB {
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
    virtual void v18(s32 id, void* en);
};

class VObjC {
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
    virtual void v16(s32 a, s32 b);
};

void fn_27_35896C(void* unused, char* obj, s32 a, s32 b, s32 c) {
    if (fn_27_10A4B0((void*)g_ftManager, a) > 1) {
        char* en = *(char**)(obj + 0xD8);
        VObjB* work = *(VObjB**)(en + 0x64);
        work->v18(0x12000041, en);
        VObjC* st = *(VObjC**)(*(char**)(obj + 0xD8) + 0x84);
        st->v16(0, 0);
        char* sub = *(char**)(obj + 8);
        s32 x = *(s32*)(sub + 0x28);
        u8 r = fn_27_10AA8C((void*)g_ftManager, a, x);
        fn_27_10C0DC((void*)g_ftManager, a, (u8)(r == 0), b, c);
    }
}
}
