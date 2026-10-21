#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_800485A4(void*);
extern "C" void* lbl_805A00C8;

extern "C" void* getInstance__11ipPadConfigFv() {
    if (lbl_805A00C8 == 0) {
        void* ptr = __nw__FUlQ25Heaps8HeapType(0x1AC, 1);
        if (ptr != 0) {
            *(unsigned char*)((unsigned char*)ptr + 0xB4) = 0;
            fn_800485A4(ptr);
        }
        lbl_805A00C8 = ptr;
    }
    return lbl_805A00C8;
}
