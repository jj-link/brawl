#include <types.h>
#pragma force_active on

extern unsigned char lbl_27_bss_7B0C[];
extern "C" s32 fn_27_30FACC(void* a, u32 b, void* c, void* d, u32 e);

class VObjA {
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

class VObjB {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setIt(s32 x);
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void setIt(s32 x);
};

extern "C" {
void fn_27_397E24(void* unused, void* self) {
    char* s = (char*)self;
    char* a = *(char**)(s + 0xd8);
    VObjA* b = *(VObjA**)(a + 0x70);
    s32 r = b->v16();
    s32 res = fn_27_30FACC(lbl_27_bss_7B0C, 0, (void*)r, self, 1);
    switch (res) {
    case 0x119: {
        char* c = *(char**)(s + 0xd8);
        VObjB* d = *(VObjB**)(c + 0x3c);
        d->setIt(-1);
        break;
    }
    case 0x11A: {
        char* c = *(char**)(s + 0xd8);
        VObjC* d = *(VObjC**)(c + 0x20);
        d->setIt(0);
        break;
    }
    }
}
}
