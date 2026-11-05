#pragma force_active on

#include <gf/gf_heap_manager.h>
#include <nw4r/g3d/g3d_scnmdl.h>

extern "C" {
void* fn_800C0164(void*);
void fn_800B96E8(void*, int);
void fn_800C0580(void*, void*, int, void*, int);
void fn_800C0670(void*, void*);
int fn_800B5854(void*, int, int, int, int);
extern char lbl_804080C0[];
extern unsigned char lbl_805A22D0;
}

extern "C" void* fn_800C001C(void* a0, void* a1, void* a2, int a3, void* a4, int a5)
{
    void* heap;
    unsigned char* tbl;
    int count;
    int i;
    char* obj = (char*)operator new(0x3D4, (Heaps::HeapType)0x2A);

    if (obj != 0) {
        obj = (char*)fn_800C0164(obj);
    }
    *(int*)(obj + 0x114) = a5;
    *(void**)(obj + 0x58) = a2;
    *(void**)(obj + 0x224) = a1;
    *(void**)(obj + 0x228) = a4;
    if (a4 != 0) {
        obj[0x2B4] = 1;
    }
    fn_800B96E8(obj + 0x60, 0xF0);
    fn_800C0580(obj, lbl_804080C0, 5, a0, a3);
    tbl = (unsigned char*)&lbl_805A22D0;
    heap = gfHeapManager::getMEMAllocator((Heaps::HeapType)0x2A);
    count = tbl[1] - tbl[0];
    if (count <= 0) {
        count = 1;
    }
    for (i = 0; i < count; i++) {
        void* model = ((void**)(obj + 0x40))[tbl[2] + i];
        void* r = nw4r::g3d::ScnMdl::Construct(heap, 0, tbl[3], *(void**)((char*)model + 0x10));
        ((void**)(obj + 0x54))[tbl[0] + i] = r;
    }
    fn_800C0670(obj, a1);
    fn_800B5854(*(void**)(obj + 0x40), 2, 2, 0, 0);
    return obj;
}
