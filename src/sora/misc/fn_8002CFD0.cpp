#pragma force_active on
extern "C" {
extern void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern void* __ct__14gfSceneManagerFv(void*);
extern void* lbl_805A0060;

void* create__14gfSceneManagerFv() {
    if (lbl_805A0060 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x320, 1);
        if (p != 0) {
            p = __ct__14gfSceneManagerFv(p);
        }
        lbl_805A0060 = p;
    }
    return lbl_805A0060;
}
}
