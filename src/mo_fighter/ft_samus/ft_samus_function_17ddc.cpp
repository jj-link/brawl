#pragma force_active on
extern "C" {
extern void* lbl_27_bss_B8;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_4FAB4(void*);

void* fn_94_17DDC() {
    if (!lbl_27_bss_B8) {
        void* manager = __nw__FUlQ25Heaps8HeapType(0x1508, 2);
        if (manager) {
            manager = fn_27_4FAB4(manager);
        }
        lbl_27_bss_B8 = manager;
    }
    return lbl_27_bss_B8;
}
}
