#include <types.h>
#pragma force_active on
extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __ct__16muMenuControllerFv(void*);
void __dt__16muMenuControllerFv(void*);
void* memset(void*, int, unsigned long);
extern char lbl_1_data_42B8[];
extern char lbl_1_data_4378[];
extern void* __vt__6muMenu[];
void fn_1_B54C(void*);
void fn_1_5058(void*, s32);
}

extern "C" void* fn_1_CF00(void* self) {
    char* p = (char*)self;
    *(void**)p = (void*)&lbl_1_data_42B8;
    *(void**)(p + 4) = (void*)&__vt__6muMenu;
    __construct_array(p + 8, &__ct__16muMenuControllerFv, &__dt__16muMenuControllerFv, 0xa8, 5);
    *(void**)(p + 4) = (void*)&lbl_1_data_4378;
    *(u32*)(p + 0x35c) = 0;
    *(u32*)(p + 0x360) = 0;
    __construct_array(p + 0x364, (void (*)(void*))fn_1_B54C, (void (*)(void*))fn_1_5058, 4, 0xa);
    *(u32*)(p + 0x3ac) = 0;
    *(u32*)(p + 0x3b0) = 0;
    *(u32*)(p + 0x3b4) = 0;
    *(u32*)(p + 0x3b8) = 0;
    *(u32*)(p + 0x3bc) = 0;
    *(u32*)(p + 0x3c0) = 0;
    *(u32*)(p + 0x3c4) = 0;
    *(u32*)(p + 0x3cc) = 0;
    *(u32*)(p + 0x3d0) = 0;
    *(u32*)(p + 0x3d4) = 0;
    *(u32*)(p + 0x3d8) = 0;
    *(u32*)(p + 0x3dc) = 0;
    *(u32*)(p + 0x3e0) = 0;
    *(u32*)(p + 0x3e4) = 0;
    *(u32*)(p + 0x3e8) = 0;
    *(u32*)(p + 0x3ec) = 0;
    *(u32*)(p + 0x3f0) = 0;
    *(u32*)(p + 0x3f4) = 0;
    *(u32*)(p + 0x3f8) = 0;
    *(u8*)(p + 0x3fc) = 0;
    *(u32*)(p + 0x400) = 0;
    *(u32*)(p + 0x404) = -1;
    *(u8*)(p + 0x408) = 0;
    *(u32*)(p + 0x410) = 0;
    *(u32*)(p + 0x414) = 0;
    *(u32*)(p + 0x418) = 0;
    *(u32*)(p + 0x38c) = 0;
    *(u32*)(p + 0x390) = 0;
    *(u32*)(p + 0x394) = 0;
    *(u32*)(p + 0x398) = 0;
    *(u32*)(p + 0x39c) = 0;
    *(u32*)(p + 0x3a0) = 0;
    *(u32*)(p + 0x3a4) = 0;
    *(u32*)(p + 0x3a8) = 0;
    memset(p + 0x409, 0, 4);
    return self;
}
