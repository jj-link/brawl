#pragma force_active on
extern "C" {
void* fn_800B03F0(void*, int);
void Init__Q34nw4r3g3d7ResFileFPv(void*);
void* GetResAnmScn__Q34nw4r3g3d7ResFileFi(void*, int);
void fn_801971D0(void*, void*);
void fn_8000D6DC(void*, void*);
extern void* g_gfSceneRoot;
extern char lbl_24_data_57C[];
void* create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(void*, const char*, int, void*, int);
}

extern "C" void fn_24_1740(void* self, void* arg) {
    void* spC;
    void* sp8;
    char* p = (char*)self;
    *(void**)(p + 0x48) = fn_800B03F0(arg, 0x15);
    *(void**)(p + 0x4C) = fn_800B03F0(arg, 0x1E);
    Init__Q34nw4r3g3d7ResFileFPv(p + 0x48);
    Init__Q34nw4r3g3d7ResFileFPv(p + 0x4C);
    spC = 0;
    spC = GetResAnmScn__Q34nw4r3g3d7ResFileFi(p + 0x48, 0);
    sp8 = spC;
    fn_801971D0(&spC, &sp8);
    fn_8000D6DC(g_gfSceneRoot, &spC);
    *(void**)(p + 0x50) = create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(p + 0x4C, lbl_24_data_57C, 1, 0, 0x2A);
}
