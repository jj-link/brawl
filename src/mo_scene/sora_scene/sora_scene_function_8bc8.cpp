#pragma force_active on
extern "C" {
    void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
    void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
    void __ct__16muMenuControllerFv(void*);
    void __dt__16muMenuControllerFv(void*);
    extern char lbl_1_data_1FA0[];
    extern char lbl_1_data_2030[];
    extern void* __vt__6muMenu[];
}

extern "C" void* fn_1_8BC8() {
    void* mem = __nw__FUlQ25Heaps8HeapType(0x3a4, 0x2e);
    if (mem) {
        *(void**)mem = (void*)&lbl_1_data_1FA0;
        *(void**)((char*)mem + 4) = (void*)&__vt__6muMenu;
        __construct_array((char*)mem + 8, &__ct__16muMenuControllerFv, &__dt__16muMenuControllerFv, 0xa8, 5);
        *(void**)((char*)mem + 4) = (void*)&lbl_1_data_2030;
        *(unsigned int*)((char*)mem + 0x35c) = 0;
        *(unsigned int*)((char*)mem + 0x360) = 0;
        *(unsigned char*)((char*)mem + 0x364) = 0;
    }
    return mem;
}
