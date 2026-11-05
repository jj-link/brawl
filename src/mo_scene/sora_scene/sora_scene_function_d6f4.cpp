#include <types.h>
#pragma force_active on
extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __ct__16muMenuControllerFv(void*);
void __dt__16muMenuControllerFv(void*);
void* memset(void*, int, unsigned long);
extern char lbl_1_data_4408[];
extern char lbl_1_data_44B0[];
extern void* __vt__6muMenu[];
void fn_1_B54C(void*);
void fn_1_5058(void*, s32);
}
extern "C" void* fn_1_D6F4(void* self) {
    char* p = (char*)self;
    *(void**)p = (void*)&lbl_1_data_4408;
    *(void**)(p + 4) = (void*)&__vt__6muMenu;
    __construct_array(p + 8, &__ct__16muMenuControllerFv, &__dt__16muMenuControllerFv, 0xa8, 5);
    *(void**)(p + 4) = (void*)&lbl_1_data_44B0;
    *(u32*)(p + 0x35c) = -1;
    *(u32*)(p + 0x360) = 0xf0;
    *(u32*)(p + 0x364) = 0;
    *(u32*)(p + 0x368) = 0;
    __construct_array(p + 0x36c, (void (*)(void*))fn_1_B54C, (void (*)(void*))fn_1_5058, 4, 8);
    *(u32*)(p + 0x3a4) = 0;
    *(u32*)(p + 0x3a8) = 0;
    *(u32*)(p + 0x3ac) = 0;
    *(u32*)(p + 0x3b4) = 0;
    *(u32*)(p + 0x3b0) = 0;
    *(u32*)(p + 0x43c) = 0;
    *(u32*)(p + 0x438) = 0;
    *(u8*)(p + 0x440) = 0;
    *(u32*)(p + 0x444) = 0;
    *(u8*)(p + 0x448) = 1;
    *(u32*)(p + 0x450) = 0;
    *(u32*)(p + 0x454) = 0;
    *(u32*)(p + 0x38c) = 0;
    *(u32*)(p + 0x390) = 0;
    *(u32*)(p + 0x394) = 0;
    *(u32*)(p + 0x398) = 0;
    *(u32*)(p + 0x39c) = 0;
    *(u32*)(p + 0x3a0) = 0;
    memset(p + 0x3b8, 0, 0x80);
    memset(p + 0x449, 0, 4);
    return self;
}