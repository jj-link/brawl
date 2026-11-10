#pragma force_active on
#include <types.h>

struct SoHeapAllocator {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void free(void* p, unsigned short type, int size);
};

extern SoHeapAllocator* lbl_805A0EB8;
extern char lbl_804860C0[];
extern "C" void fn_801F6524(void*);

extern "C" void* fn_8027C298(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        s32 tmp = *(s32*)((char*)arg0 + 0x48);
        *(void**)arg0 = lbl_804860C0;
        if (tmp != -1) {
            fn_801F6524((char*)arg0 + 8);
        }
        if (arg1 > 0) {
            lbl_805A0EB8->free(arg0, *(unsigned short*)((char*)arg0 + 4), 0x18);
        }
    }
    return arg0;
}