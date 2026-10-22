#pragma force_active on

struct Obj {
    char pad0[0x28];
    void* f28;
    void* f2C;
    void* f30;
    char pad1[0x68 - 0x34];
    int f68;
};

extern "C" {
void Init__Q34nw4r3g3d7ResFileFPv(void*, void*);
void fn_8018E5D4(void*, void*);
void* fn_8018D174(void*, int);
void* fn_8018F2EC(void*, int);
void fn_80191FB8(void*, void*);
void* fn_801B0B40(void*, void*, void*, int, int, void*);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
void* Construct__Q34nw4r3g3d6ScnMdlFPviiPv(void*, int, int, void*);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, void*);
void add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(void*, int, void*);
void fn_801B0A28(void);
extern void* g_gfSceneRoot;
extern void* lbl_20_bss_8;
extern char lbl_20_data_230[];
extern void* lbl_805A0310;
}

extern "C" void fn_20_3F6C(Obj* self) {
    void* sp30;
    void* sp2C;
    void* sp28;
    void* sp24;
    void* sp20;
    void* sp1C;
    void* sp18;
    void* sp14;
    void* sp10;
    void* sp0C;
    void* sp08;

    void* res = *(void**)((char*)lbl_20_bss_8 + self->f68 * 4 + 0x34C);
    sp30 = *(void**)((char*)res + 0x10);
    Init__Q34nw4r3g3d7ResFileFPv(&sp30, res);
    sp0C = sp30;
    fn_8018E5D4(&sp30, &sp0C);
    void* root = g_gfSceneRoot;
    sp2C = fn_8018D174(&sp30, 0);
    void* alloc = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(0x2A);
    sp1C = sp2C;
    self->f28 = fn_801B0B40(alloc, &sp28, &sp1C, 0, 1, (void*)&fn_801B0A28);
    sp24 = fn_8018F2EC(&sp2C, 0);
    sp18 = sp30;
    fn_80191FB8(&sp24, &sp18);
    if (self->f2C == 0) {
        sp30 = *(void**)((char*)lbl_805A0310 + 0x1FC);
        Init__Q34nw4r3g3d7ResFileFPv(&sp30, lbl_805A0310);
        sp08 = sp30;
        fn_8018E5D4(&sp30, &sp08);
        sp2C = fn_8018D174(&sp30, 0);
        sp14 = sp2C;
        self->f2C = fn_801B0B40(alloc, &sp20, &sp14, 0, 1, (void*)&fn_801B0A28);
        sp24 = fn_8018F2EC(&sp2C, 0);
        sp10 = sp30;
        fn_80191FB8(&sp24, &sp10);
    }
    self->f30 = Construct__Q34nw4r3g3d6ScnMdlFPviiPv(alloc, 0, 1, self->f28);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->f30, self->f2C, lbl_20_data_230);
    add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(root, 0, self->f30);
}
