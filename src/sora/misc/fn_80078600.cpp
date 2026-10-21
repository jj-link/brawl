#pragma force_active on
extern "C" {

extern void* lbl_805A01D8;
extern void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern void* fn_800783EC(void*);

void* fn_80078600() {
    if (lbl_805A01D8 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x14D8, 5);
        if (p != 0) {
            p = fn_800783EC(p);
        }
        lbl_805A01D8 = p;
    }
    return lbl_805A01D8;
}

}
