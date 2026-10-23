#include <types.h>
#pragma force_active on
extern "C" {
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
void* fn_801B3440(void*, int, int);
void* fn_801AB6CC(void*, int, int);
void fn_800DFAB4(void*, int);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_800DFCB4(void*, int);
void fn_800E023C(void*, int, int, void*, void*);
void* fn_800DD528(void*);
void fn_800DD6E4(void*, void*, void*, int, int);
void fn_8010BDD0(void*);
void fn_8010BF3C(void*);
void* fn_8010B76C(void);
void fn_8010BC58(void*, void*);
void fn_8010BD28(void*, void*);
void fn_8010BD74(void*, void*, void*);
void fn_80108D1C(void*);
void* fn_8010890C(void*);
void fn_80108AE0(void*, void*);
void fn_80108404(void*);
void* fn_80108014(int, void*);
void fn_801081C8(void*, void*);
void fn_8010A800(void*, void*, void*);
void* GetResAnmScn__Q34nw4r3g3d7ResFileFi(void*, int);
void fn_801971D0(void*, void*);
void fn_8000D6DC(void*, void*);
void fn_8010CF88(void*, int);
extern void* g_gfSceneRoot;

void fn_80106E48(char* self) {
    void* spC;
    void* sp8;
    char* p;
    int i;
    void* allocator = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(0x28);
    *(void**)(self + 0x8) = fn_801B3440(allocator, 0, 2);
    *(void**)(self + 0x44) = fn_801AB6CC(allocator, 0, 0x20);
    fn_800DFAB4(self + 0x14, *(int*)(self + 0x114));
    p = self;
    for (i = 0; i < *(int*)(self + 0x114); i++) {
        void* obj = __nw__FUlQ25Heaps8HeapType(0x5D8, 0x28);
        if (obj != 0) {
            obj = fn_800DFCB4(obj, i);
        }
        *(void**)(p + 0xE8) = obj;
        fn_800E023C(obj, 0, 0, self + 0x14, self + 0x2C);
        p += 4;
    }
    void* o2 = __nw__FUlQ25Heaps8HeapType(0x1E4, 0x28);
    if (o2 != 0) {
        o2 = fn_800DD528(o2);
    }
    *(void**)(self + 0x108) = o2;
    fn_800DD6E4(o2, self + 0x14, self + 0x34, 0, 5);
    fn_8010BDD0(self + 0x18);
    fn_8010BF3C(self + 0x14);
    *(void**)(self + 0x104) = fn_8010B76C();
    fn_8010BC58(*(void**)(self + 0x104), self + 0x18);
    fn_8010BD28(*(void**)(self + 0x104), self + 0x14);
    fn_8010BD74(*(void**)(self + 0x104), self + 0x18, self + 0x2C);
    fn_80108D1C(self + 0x18);
    *(void**)(self + 0x6C) = fn_8010890C(*(void**)(self + 0x58));
    fn_80108AE0(*(void**)(self + 0x6C), self + 0x18);
    fn_80108404(self + 0x18);
    *(void**)(self + 0x60) = fn_80108014(0, *(void**)(self + 0x58));
    fn_801081C8(*(void**)(self + 0x60), self + 0x18);
    fn_8010A800(*(void**)(self + 0x74), self + 0x1C, self + 0x20);
    {
        void* v = *(void**)(self + 0x28);
        *(void**)(*(char**)(self + 0x74) + 0x104) = v;
    }
    {
        void* v = *(void**)(self + 0x40);
        *(void**)(*(char**)(self + 0x74) + 0x108) = v;
    }
    {
        void* v = *(void**)(self + 0x24);
        *(void**)(*(char**)(self + 0x74) + 0x10C) = v;
    }
    {
        void* v = *(void**)(self + 0x5C);
        *(void**)(*(char**)(self + 0x74) + 0x13C) = v;
    }
    sp8 = 0;
    sp8 = GetResAnmScn__Q34nw4r3g3d7ResFileFi(self + 0x30, 0);
    spC = sp8;
    fn_801971D0(&sp8, &spC);
    fn_8000D6DC(g_gfSceneRoot, &sp8);
    if (*(void**)(self + 0x78) != 0) {
        fn_8010CF88(*(void**)(self + 0x78), 0);
    }
}
}
