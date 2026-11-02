#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_80030654(void*);
extern int lbl_805A0078;

extern "C" int fn_80030548(int arg0) {
    void* p;

    if (lbl_805A0078 != 0) {
        return 0;
    }
    p = __nw__FUlQ25Heaps8HeapType(0x118, arg0);
    if (p != 0) {
        p = fn_80030654(p);
    }
    lbl_805A0078 = (int)p;
    if (p != 0) {
        *(int*)((char*)p + 0x114) = arg0;
    }
    return lbl_805A0078;
}
