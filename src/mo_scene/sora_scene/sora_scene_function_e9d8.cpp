#include <types.h>
#pragma force_active on

extern "C" {
    void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
    void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
    void __ct__16muMenuControllerFv(void*);
    void __dt__16muMenuControllerFv(void*);
    extern char lbl_1_data_49D8[];
    extern char lbl_1_data_4AC0[];
    extern void* __vt__6muMenu[];
}

struct muMenuBase {
    void* unk0;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
struct muMenu : muMenuBase { };

extern "C" void* fn_1_E9D8() {
    void* mem = __nw__FUlQ25Heaps8HeapType(0x394, 0x2e);
    muMenu* m = (muMenu*)mem;
    if (m) {
        *(void**)m = (void*)&lbl_1_data_49D8;
        *(void**)((char*)m + 4) = (void*)&__vt__6muMenu;
        __construct_array((char*)m + 8, &__ct__16muMenuControllerFv, &__dt__16muMenuControllerFv, 0xa8, 5);
        *(void**)((char*)m + 4) = (void*)&lbl_1_data_4AC0;
        *(unsigned int*)((char*)m + 0x35c) = 0;
        *(unsigned int*)((char*)m + 0x378) = 0;
        *(unsigned int*)((char*)m + 0x37c) = 0;
        *(unsigned int*)((char*)m + 0x360) = 0;
        *(unsigned int*)((char*)m + 0x364) = 0;
        *(unsigned int*)((char*)m + 0x380) = 0;
        *(unsigned int*)((char*)m + 0x384) = 0;
        *(unsigned int*)((char*)m + 0x388) = 0;
        *(unsigned int*)((char*)m + 0x38c) = 0;
    }
    m->v4();
    return m;
}
