#include <types.h>
#pragma force_active on
extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __ct__16muMenuControllerFv(void*);
void __dt__16muMenuControllerFv(void*);
extern char lbl_1_data_3C58[];
extern char lbl_1_data_3E14[];
extern void* __vt__6muMenu[];
void fn_1_B54C(void*);
void fn_1_5058(void*, s32);
}

extern "C" void* fn_1_B478(void* self) {
    char* p = (char*)self;
    *(void**)p = (void*)&lbl_1_data_3C58;
    *(void**)(p + 4) = (void*)&__vt__6muMenu;
    __construct_array(p + 8, &__ct__16muMenuControllerFv, &__dt__16muMenuControllerFv, 0xa8, 5);
    *(void**)(p + 4) = (void*)&lbl_1_data_3E14;
    *(u32*)(p + 0x35c) = 0;
    *(u32*)(p + 0x360) = 0;
    *(u32*)(p + 0x364) = 0;
    *(u32*)(p + 0x368) = 0;
    *(u32*)(p + 0x36c) = 0;
    *(u32*)(p + 0x370) = 0;
    *(u32*)(p + 0x374) = 0;
    *(u32*)(p + 0x37c) = 0;
    *(u32*)(p + 0x380) = 0;
    __construct_array(p + 0x384, (void (*)(void*))fn_1_B54C, (void (*)(void*))fn_1_5058, 4, 9);
    *(u32*)(p + 0x3a8) = 0;
    *(u32*)(p + 0x360) = 0;
    *(u32*)(p + 0x364) = 0;
    *(u32*)(p + 0x368) = 0;
    *(u32*)(p + 0x36c) = 0;
    return self;
}