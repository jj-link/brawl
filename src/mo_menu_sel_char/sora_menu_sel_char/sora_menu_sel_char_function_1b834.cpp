#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_10_1B950(void*, void*);

struct Obj {
    void* unk0;
    void* unk4;
    void* unk8;
    void* unkC;
    void* unk10;
    void* unk14;
    void* unk18;
    unsigned char unk1C;
    unsigned char unk1D;
};

extern "C" void* fn_10_1B834(void* arg) {
    Obj* obj = (Obj*)__nw__FUlQ25Heaps8HeapType(0x20, 0x2A);
    if (obj) {
        obj->unk0 = 0;
        obj->unk10 = 0;
        obj->unk14 = 0;
        obj->unk18 = 0;
        obj->unk1C = 0;
        obj->unk1D = 0;
        obj->unk4 = 0;
        obj->unk8 = 0;
        obj->unkC = 0;
    }
    fn_10_1B950(obj, arg);
    return obj;
}
