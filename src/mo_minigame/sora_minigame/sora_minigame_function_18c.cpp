#pragma force_active on
extern "C" void fn_20_8230(void*, void*);
extern "C" void fn_20_C8(void*, int);
extern "C" void fn_8009A048(void*);
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* lbl_20_bss_8;
extern "C" char lbl_20_data_6C[];
extern "C" char lbl_20_data_A0[];

extern "C" void* fn_20_18C(void* self) {
    char* p = (char*)self;
    *(void**)(p + 0x0) = lbl_20_data_6C;
    *(int*)(p + 0x4) = 0;
    *(int*)(p + 0x8) = 0;
    *(unsigned int*)(p + 0xC) = 0x80000000;
    fn_20_8230(lbl_20_bss_8, self);
    char* obj = (char*)__nw__FUlQ25Heaps8HeapType(0x30, 0x2A);
    if (obj != 0) {
        fn_20_C8(obj, 5);
        fn_8009A048(obj + 0x8);
        *(void**)(obj + 0x0) = lbl_20_data_A0;
        *(void**)(obj + 0x8) = lbl_20_data_A0 + 0x18;
        obj[0x18] = 0;
        *(int*)(obj + 0x1C) = 0;
        *(int*)(obj + 0x20) = 0;
        *(int*)(obj + 0x24) = -1;
        *(int*)(obj + 0x28) = -1;
        *(int*)(obj + 0x2C) = 0;
    }
    *(void**)(p + 0x10) = obj;
    return self;
}
