#include <types.h>
#pragma force_active on
extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __ct__16muMenuControllerFv(void*);
void __dt__16muMenuControllerFv(void*);
void* memset(void*, int, unsigned long);
extern char lbl_1_data_4540[];
extern char lbl_1_data_45F8[];
extern void* __vt__6muMenu[];
void fn_1_B54C(void*);
void fn_1_5058(void*, s32);
}
extern "C" void* fn_1_DEE0(void* self) {
    char* p = (char*)self;
    *(void**)p = (void*)&lbl_1_data_4540;
    *(void**)(p + 4) = (void*)&__vt__6muMenu;
    __construct_array(p + 8, &__ct__16muMenuControllerFv, &__dt__16muMenuControllerFv, 0xa8, 5);
    *(void**)(p + 4) = (void*)&lbl_1_data_45F8;
    *(u32*)(p + 0x35c) = 0;
    *(u32*)(p + 0x360) = 0;
    *(u32*)(p + 0x364) = 0;
    *(u32*)(p + 0x368) = 0;
    *(u32*)(p + 0x36c) = 0;
    *(u32*)(p + 0x370) = 0;
    __construct_array(p + 0x434, (void (*)(void*))fn_1_B54C, (void (*)(void*))fn_1_5058, 4, 3);
    *(u8*)(p + 0x440) = 0;
    *(u32*)(p + 0x444) = 0;
    *(u16*)(p + 0x448) = 1;
    *(u16*)(p + 0x44a) = 1;
    *(u32*)(p + 0x44c) = 0x26f9;
    *(u32*)(p + 0x450) = 9;
    *(u32*)(p + 0x454) = 0;
    *(u32*)(p + 0x364) = 0;
    memset(p + 0x374, 0, 0xc0);
    return self;
}