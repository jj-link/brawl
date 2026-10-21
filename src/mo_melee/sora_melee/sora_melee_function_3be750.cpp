#include <types.h>
#pragma force_active on

extern unsigned char lbl_27_bss_7B0C[];
extern "C" s32 fn_27_30FACC(void*, u32, s32, void*, u32);
extern "C" void fn_27_3C6F2C(void*);

class VObj {
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
    virtual s32 v17(u32);
    virtual void v18();
    virtual void v19(u32);
};

extern "C" s32 fn_27_3BE750(void* a, void* b, void* self) {
    char* s = (char*)self;
    VObj* o = *(VObj**)(*(char**)(s + 0xd8) + 0x70);
    s32 r = o->v16();

    switch (fn_27_30FACC(lbl_27_bss_7B0C, 0, r, self, 1)) {
    case 0x119:
    case 0x11a: {
        VObj* c = *(VObj**)(*(char**)(s + 0xd8) + 0x64);
        if (c->v17(0x22000012) != 0) {
            fn_27_3C6F2C(self);
            c = *(VObj**)(*(char**)(s + 0xd8) + 0x64);
            c->v19(0x22000012);
            return 1;
        }
        break;
    }
    }
    return 0;
}
