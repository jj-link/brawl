#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" char lbl_8045DD3C[];

struct LocalStruct {
    char pad0[0x6];
    short unk6;
    char pad8[0x20];
    void* unk28;
};

extern "C" void fn_801385AC() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x2C, 0xF);
    if (obj) {
        LocalStruct* s = (LocalStruct*)obj;
        s->unk28 = &lbl_8045DD3C;
        s->unk6 = 1;
    }
}
