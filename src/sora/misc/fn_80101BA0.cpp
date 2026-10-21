#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_80101C0C(void*);
extern "C" void* lbl_805A0310;

extern "C" void fn_80101BA0(void) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x334, 0x2A);
    if (obj != 0) {
        obj = fn_80101C0C(obj);
    }
    lbl_805A0310 = obj;
}
