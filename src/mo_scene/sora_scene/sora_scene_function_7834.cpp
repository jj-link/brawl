#pragma force_active on

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __ct__16muMenuControllerFv(void*);
void __dt__16muMenuControllerFv(void*);
extern char lbl_1_data_1A10[];
extern char lbl_1_data_1AA4[];
extern void* __vt__6muMenu[];
}

extern "C" void* fn_1_7834() {
    void* mem = __nw__FUlQ25Heaps8HeapType(0x360, 0x2e);
    if (mem) {
        *(void**)mem = (void*)&lbl_1_data_1A10;
        *(void**)((char*)mem + 4) = (void*)&__vt__6muMenu;
        __construct_array((char*)mem + 8, &__ct__16muMenuControllerFv, &__dt__16muMenuControllerFv, 0xa8, 5);
        *(void**)((char*)mem + 4) = (void*)&lbl_1_data_1AA4;
        *(unsigned int*)((char*)mem + 0x35c) = 0;
    }
    return mem;
}
