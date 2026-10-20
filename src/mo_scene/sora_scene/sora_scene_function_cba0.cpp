#include <types.h>
#pragma force_active on

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __ct__16muMenuControllerFv(void*);
void __dt__16muMenuControllerFv(void*);
extern char lbl_1_data_4254[];
extern char lbl_1_data_4274[];
extern void* __vt__6muMenu[];
}

extern "C" void* fn_1_CBA0() {
    char* p = (char*)__nw__FUlQ25Heaps8HeapType(0x360, 0x2e);
    if (p != 0) {
        *(void**)p = (void*)&lbl_1_data_4254;
        *(void**)(p + 4) = (void*)&__vt__6muMenu;
        __construct_array(p + 8, &__ct__16muMenuControllerFv, &__dt__16muMenuControllerFv, 0xa8, 5);
        *(void**)(p + 4) = (void*)&lbl_1_data_4274;
        *(u32*)(p + 0x35c) = 0;
    }
    return p;
}
