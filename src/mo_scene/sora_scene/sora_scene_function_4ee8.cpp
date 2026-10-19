#include <types.h>
#pragma force_active on

extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __ct__16muMenuControllerFv(void*);
void __dt__16muMenuControllerFv(void*);
void* memset(void*, int, unsigned long);
extern char lbl_1_data_6D8[];
extern char lbl_1_data_75C[];
extern void* __vt__6muMenu[];
}

extern "C" void* fn_1_4EE8(void* self) {
    char* p = (char*)self;
    *(void**)p = (void*)&lbl_1_data_6D8;
    *(void**)(p + 4) = (void*)&__vt__6muMenu;
    __construct_array(p + 8, &__ct__16muMenuControllerFv, &__dt__16muMenuControllerFv, 0xa8, 5);
    *(void**)(p + 4) = (void*)&lbl_1_data_75C;
    *(u32*)(p + 0x35c) = 0;
    *(u32*)(p + 0x360) = 0;
    *(u32*)(p + 0x364) = 1;
    *(u32*)(p + 0x380) = 0;
    memset(p + 0x368, 0, 0x18);
    memset(p + 0x384, 0, 0x10);
    *(u32*)(p + 0x394) = 0;
    *(u32*)(p + 0x398) = 0;
    *(u8*)(p + 0x39c) = 0;
    *(u8*)(p + 0x39d) = 0x78;
    *(u32*)(p + 0x3a0) = 0;
    *(u32*)(p + 0x3a4) = 0;
    memset(p + 0x35c, 0, 0x38);
    *(u32*)(p + 0x35c) = 0;
    *(u32*)(p + 0x360) = 0;
    *(u32*)(p + 0x364) = 1;
    *(u32*)(p + 0x368) = 0;
    *(u32*)(p + 0x36c) = 0;
    *(u32*)(p + 0x380) = 0;
    return self;
}
