#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern "C" {
void startup__10grYakumonoFP9gfArchiveUlQ211gfSceneRoot9LayerType(void* self, void* arch, u32 p, int layer);
void* getData__9gfArchiveF11ARCNodeTypeiUs(void* arch, int type, int index, u16 n);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int heap);
void* fn_801B5AD0(void* allocator, void* buf, void* fn, int a, int b, int c);
void fn_68_2964(void);
void add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(void* root, int layer, void* mdl);
extern void* g_gfSceneRoot;
}

extern "C" void fn_68_399C(void* self, void* arch, u32 p) {
    u8* s = (u8*)self;
    startup__10grYakumonoFP9gfArchiveUlQ211gfSceneRoot9LayerType(self, arch, p, 0);
    *(void**)(s + 0xa50) = getData__9gfArchiveF11ARCNodeTypeiUs(arch, 3, 0, (u16)0xFFFE);
    void* alloc = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(0xF);
    int buf[2];
    void* mdl = fn_801B5AD0(alloc, buf, (void*)fn_68_2964, 1, 0, 0);
    *(void**)(s + 0x9b8) = mdl;
    if (mdl != 0) {
        *(void**)((u8*)mdl + 0xf0) = self;
        add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, 0, *(void**)(s + 0x9b8));
    }
}
