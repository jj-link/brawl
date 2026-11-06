#include <types.h>
#pragma force_active on

extern unsigned char lbl_27_bss_7B0C[];
extern f32 lbl_27_rodata_7698;
extern "C" s32 fn_27_30FACC(void* a, u32 b, void* c, void* d, u32 e);

class VObjFirst {
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
    virtual s32 v16();
};

class VObjSecond {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(s32 a, u32 b);
};

extern "C" void fn_27_3313D8(void* unused1, void* unused2, s32 flag, void* arg, void* self, f32 t) {
    if (flag != 0 && t > lbl_27_rodata_7698) {
        char* work = *(char**)((char*)self + 0xD8);
        VObjFirst* obj = *(VObjFirst**)(work + 0x70);
        s32 status = obj->v16();
        s32 res = fn_27_30FACC(lbl_27_bss_7B0C, 0, (void*)status, self, 1);
        if (res == 0x112) {
            char* c = *(char**)((char*)self + 0xD8);
            VObjSecond* d = *(VObjSecond**)(c + 0x64);
            d->v5((s32)arg, 0x20000002);
        }
    }
}
