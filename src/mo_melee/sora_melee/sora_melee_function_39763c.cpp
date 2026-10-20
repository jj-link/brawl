#include <types.h>
#pragma force_active on

extern unsigned char lbl_27_bss_7B0C[];
extern "C" s32 fn_27_30FACC(void* a, u32 b, void* c, void* d, u32 e);
extern "C" void fn_27_397B04(void* a, void* b);

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
};

extern "C" void fn_27_39763C(void* arg0, void* self) {
    char* s = (char*)self;
    char* a = *(char**)(s + 0xd8);
    VObj* b = *(VObj**)(a + 0x70);
    s32 r = b->v16();
    s32 res = fn_27_30FACC(lbl_27_bss_7B0C, 0, (void*)r, self, 1);
    switch (res) {
    case 0x11b:
    case 0x11c:
        fn_27_397B04(arg0, self);
        break;
    }
}
