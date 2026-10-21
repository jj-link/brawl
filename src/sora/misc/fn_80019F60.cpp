#pragma force_active on
extern "C" {
extern int lbl_8059FFC0;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_80019FEC();

int fn_80019F60() {
    if (lbl_8059FFC0 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x740, 1);
        if (p != 0) {
            fn_80019FEC();
        }
    }
    return lbl_8059FFC0;
}
}
