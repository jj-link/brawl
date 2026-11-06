#include <types.h>
#pragma force_active on
extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __ct__16muMenuControllerFv(void*);
void __dt__16muMenuControllerFv(void*);
void* memset(void*, int, unsigned long);
extern char lbl_1_data_3EA8[];
extern char lbl_1_data_403C[];
extern void* __vt__6muMenu[];
void fn_1_B54C(void*);
void fn_1_5058(void*, s32);
}

extern "C" void* fn_1_BC60(void* self) {
    char* p = (char*)self;
    *(void**)p = (void*)&lbl_1_data_3EA8;
    *(void**)(p + 4) = (void*)&__vt__6muMenu;
    __construct_array(p + 8, &__ct__16muMenuControllerFv, &__dt__16muMenuControllerFv, 0xa8, 5);
    *(void**)(p + 4) = (void*)&lbl_1_data_403C;
    *(u32*)(p + 0x35c) = 0;
    *(u32*)(p + 0x360) = 0;
    *(u32*)(p + 0x364) = 0;
    *(u32*)(p + 0x368) = 0;
    *(u32*)(p + 0x36c) = 0;
    *(u32*)(p + 0x370) = 0;
    *(u32*)(p + 0x374) = 0;
    *(u32*)(p + 0x378) = 0;
    *(u32*)(p + 0x37c) = 0;
    *(u32*)(p + 0x380) = 0;
    *(u32*)(p + 0x384) = 0;
    *(u32*)(p + 0x388) = 0;
    *(u32*)(p + 0x38c) = 0;
    __construct_array(p + 0x390, (void (*)(void*))fn_1_B54C, (void (*)(void*))fn_1_5058, 4, 0xa);
    *(u32*)(p + 0x558) = 0;
    *(u8*)(p + 0x626) = 0;
    *(u8*)(p + 0x684) = 0;
    *(u32*)(p + 0x688) = 0;
    *(u32*)(p + 0x68c) = 0;
    *(u32*)(p + 0x360) = 0;
    *(u32*)(p + 0x364) = 0;
    *(u32*)(p + 0x368) = 0;
    *(u32*)(p + 0x36c) = 0;
    *(u32*)(p + 0x370) = 0;
    memset(p + 0x3b8, 0, 0xd0);
    memset(p + 0x488, 0, 0xd0);
    memset(p + 0x55c, 0, 0xca);
    return self;
}
