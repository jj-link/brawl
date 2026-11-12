#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_8009D468(void*);
extern "C" void* lbl_805A0280;
extern "C" const float lbl_805A1DC8;
inline void clear(int* begin, int* end) {
    int* p = begin;
    do { *p = 0; ++p; } while (p < end);
}
extern "C" void* fn_8009D2DC() {
    if (lbl_805A0280 == 0) {
        char* p = (char*)__nw__FUlQ25Heaps8HeapType(0x274, 1);
        if (p != 0) {
            *(int*)(p + 0x22C) = 0;
            clear((int*)(p + 0x230), (int*)(p + 0x244));
            fn_8009D468(p);
            *(float*)(p + 0x244) = lbl_805A1DC8;
            *(float*)(p + 0x248) = lbl_805A1DC8;
            *(float*)(p + 0x24C) = lbl_805A1DC8;
            *(float*)(p + 0x250) = lbl_805A1DC8;
            *(float*)(p + 0x254) = lbl_805A1DC8;
        }
        lbl_805A0280 = p;
    }
    return lbl_805A0280;
}