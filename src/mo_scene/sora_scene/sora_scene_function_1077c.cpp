#include <types.h>
#pragma force_active on
extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __ct__16muMenuControllerFv(void*);
void __dt__16muMenuControllerFv(void*);
extern char lbl_1_data_4DF0[];
extern char lbl_1_data_4F54[];
extern void* __vt__6muMenu[];
}
inline void clearWords(s32* p, s32* e) {
    do {
        *p = 0;
        p++;
    } while (p < e);
}
extern "C" void* fn_1_1077C(void* self) {
    char* p = (char*)self;
    *(void**)p = (void*)&lbl_1_data_4DF0;
    *(void**)(p + 4) = (void*)&__vt__6muMenu;
    __construct_array(p + 8, &__ct__16muMenuControllerFv, &__dt__16muMenuControllerFv, 0xa8, 5);
    *(u32*)(p + 0x7c4) = 0;
    *(void**)(p + 4) = (void*)&lbl_1_data_4F54;
    clearWords((s32*)(p + 0x7c4), (s32*)(p + 0x80c));
    *(u32*)(p + 0x80c) = 0;
    clearWords((s32*)(p + 0x80c), (s32*)(p + 0xa90));
    *(u32*)(p + 0xa90) = 0;
    *(u32*)(p + 0xa94) = 0;
    *(u32*)(p + 0xa98) = 0;
    *(u32*)(p + 0xa9c) = 0;
    *(u32*)(p + 0xac0) = 0;
    *(u32*)(p + 0xac4) = 0;
    return self;
}