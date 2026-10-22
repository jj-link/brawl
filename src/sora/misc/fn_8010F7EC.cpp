#include <types.h>
#pragma force_active on
extern "C" {
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
void* fn_801AB6CC(void*, void*, int);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* __ct__9IfStgeditFv(void*);
void createModel__9IfStgeditFPQ34nw4r3g3d7ResFile(void*, void*);
void* GetResAnmScn__Q34nw4r3g3d7ResFileFi(void*, int);
void fn_801971D0(void*, void*);
void fn_8000D6DC(void*, void*);
extern void* g_gfSceneRoot;

void fn_8010F7EC(void* self) {
    char* p = (char*)self;
    void* spC = 0;
    void* sp8;
    void* allocator = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(0x28);
    void* scene = fn_801AB6CC(allocator, 0, 1);
    *(void**)(p + 0x4) = scene;
    void* stgedit = __nw__FUlQ25Heaps8HeapType(0x14, 0x28);
    if (stgedit != 0) {
        stgedit = __ct__9IfStgeditFv(stgedit);
    }
    *(void**)(p + 0x10) = stgedit;
    createModel__9IfStgeditFPQ34nw4r3g3d7ResFile(stgedit, p + 0x8);
    spC = GetResAnmScn__Q34nw4r3g3d7ResFileFi(p + 0xc, 0);
    sp8 = spC;
    fn_801971D0(&spC, &sp8);
    fn_8000D6DC(g_gfSceneRoot, &spC);
}
}
