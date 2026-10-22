#pragma force_active on
extern "C" {
extern void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern void* lbl_805A0460;

void* fn_80158640() {
    if (lbl_805A0460 == 0) {
        int* p = (int*)__nw__FUlQ25Heaps8HeapType(0x34, 2);
        if (p != 0) {
            p[0] = -1;
            p[1] = 0;
            p[2] = -1;
            p[3] = 0;
            p[4] = 0;
            p[5] = -1;
            p[9] = 0;
            p[6] = -1;
            p[10] = 0;
            p[7] = -1;
            p[11] = 0;
            p[8] = -1;
            p[12] = 0;
        }
        lbl_805A0460 = p;
    }
    return lbl_805A0460;
}
}
