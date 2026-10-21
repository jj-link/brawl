#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_8005AD3C(void*);
extern void* lbl_805A0110;

extern "C" void fn_8005AD04() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x13c, 0x2);
    if (obj) {
        obj = fn_8005AD3C(obj);
    }
    lbl_805A0110 = obj;
}
