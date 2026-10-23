#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern "C" {
void startup__10grYakumonoFP9gfArchiveUlQ211gfSceneRoot9LayerType(void* self, void* arch, u32 p, int layer);
void* getData__9gfArchiveF11ARCNodeTypeiUs(void* arch, int type, int index, u16 n);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int heap);
void* fn_801B5AD0(void* allocator, void* buf, void* fn, int a, int b, int c);
void fn_48_7CC8(char* p, unsigned int n);
void add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(void* root, int layer, void* mdl);
void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, unsigned long flag);
extern void* g_gfSceneRoot;
}

extern "C" void fn_48_7BE8(void* self, void* arch, u32 p, int layer) {
    u8* s = (u8*)self;
    startup__10grYakumonoFP9gfArchiveUlQ211gfSceneRoot9LayerType(s, arch, p, layer);
    *(void**)(s + 0x154) = getData__9gfArchiveF11ARCNodeTypeiUs(arch, 3, 0, (u16)0xFFFE);
    void* alloc = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(0xF);
    void* buf;
    *(void**)(s + 0x150) = fn_801B5AD0(alloc, &buf, (void*)fn_48_7CC8, 0, 1, 0);
    if (*(void**)(s + 0x150) != 0) {
        *(void**)(*(u8**)(s + 0x150) + 0xf0) = s;
        add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, 0, *(void**)(s + 0x150));
        u8* d0 = s + 0xd0;
        void* scnMdl = *(void**)(*(u32*)(s + 0x44));
        if (scnMdl != 0) {
            *(void**)((u8*)scnMdl + 0x11c) = d0;
            EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(scnMdl, 1);
            *(u16*)((u8*)scnMdl + 0x122) = (u16)*(u32*)(*(u32**)(d0 + 4));
        }
    }
}
