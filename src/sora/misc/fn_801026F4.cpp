#pragma force_active on
#pragma opt_propagation off
extern "C" void fn_800FABEC(void*);
extern "C" void fn_800FAC58(void*, const void*, int, int);
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_800AD808(void*, int);
extern "C" void fn_800AD87C(void*, int);
extern char lbl_8045C838[];

extern "C" void fn_801026F4(char* self) {
    unsigned long base = (unsigned long)lbl_8045C838;
    const void* p = (void*)(base + 0x1B4);
    fn_800FABEC(self + 0x1DC);
    *(int*)(self + 0x1C8) = 0;
    self[0x1F4] = 0;
    fn_800FAC58(self + 0x1DC, p, 0x2B, 0);
    const void* p2 = (void*)(base + 0x1D4);
    fn_800FABEC(self + 0x210);
    *(int*)(self + 0x1FC) = 0;
    self[0x228] = 0;
    fn_800FAC58(self + 0x210, p2, 0x2B, 0);
    const void* p3 = (void*)(base + 0x1EC);
    fn_800FABEC(self + 0x244);
    *(int*)(self + 0x230) = 0;
    self[0x25C] = 0;
    fn_800FAC58(self + 0x244, p3, 0x2B, 0);
    fn_800FAC58(self + 0x264, (void*)(base + 0x20C), 0x2B, 0);
    void* obj = __nw__FUlQ25Heaps8HeapType(0x3EB4, 0x2A);
    if (obj != 0) obj = fn_800AD808(obj, 1);
    if (*(void**)(self + 0x328) != obj) {
        fn_800AD87C(*(void**)(self + 0x328), 1);
        *(void**)(self + 0x328) = obj;
    }
}