#pragma force_active on
extern "C" {
extern void* lbl_805A0348;
int fn_8010EC6C(void* p);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_40_47EB8(void* obj, void* arg);
void* fn_40_47E50(void* arg);
}

void* fn_40_47E50(void* arg) {
    void* p = lbl_805A0348;
    if (p == 0 || fn_8010EC6C(p) == 0) {
        return 0;
    }
    void* obj = __nw__FUlQ25Heaps8HeapType(0x22c, 0x2a);
    if (obj != 0) {
        fn_40_47EB8(obj, arg);
    }
}
