#include <types.h>
#pragma force_active on

extern unsigned char lbl_27_bss_7B0C[];
extern "C" int fn_27_30FACC(void*, unsigned int, int, void*, unsigned int);
extern "C" void fn_27_3C7790(void*);

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
    virtual int v16();
};

extern "C" void fn_27_3BE820(void* a0, void* a1, void* a2, void* self) {
    char* work = *(char**)((char*)self + 0xD8);
    VObj* object = *(VObj**)(work + 0x70);
    int status = object->v16();

    switch (fn_27_30FACC(lbl_27_bss_7B0C, 0, status, self, 1)) {
    case 0x117:
    case 0x118:
    case 0x119:
    case 0x11A:
    case 0x11B:
    case 0x11C:
    case 0x11D:
        if ((*(unsigned int*)((char*)a1 + 0x6C) & 0x1F) == 7) {
            fn_27_3C7790(self);
        }
        break;
    }
}
