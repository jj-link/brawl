#include <gf/gf_copyefb.h>
#include <gf/gf_heap_manager.h>
#pragma force_active on

extern "C" {
unsigned char* fn_801A12A0();
int fn_801F270C(unsigned short, unsigned short, unsigned int, int, int);
void fn_801D76BC(void*, unsigned int);
void fn_801F28F0(void*, void*, unsigned short, unsigned short, unsigned int, unsigned int, unsigned int, unsigned char);
void fn_801F2B44(void*, int, int, int, int, int, float, float, float);
}
extern const float lbl_805A15D0;

void gfCopyEFBMgr::createCopyEFB(int index, Heaps::HeapType heapType) {
    unsigned char* p = (unsigned char*)this + index * 0x34;
    if (*(void**)(p + 0x4) == 0) {
        unsigned char* src = fn_801A12A0();
        unsigned short w = *(unsigned short*)(src + 4);
        *(unsigned short*)(p + 0xC) = w;
        unsigned short h = *(unsigned short*)(src + 6);
        *(unsigned short*)(p + 0xE) = h;
        *(int*)p = 4;
        int type = fn_801F270C(w, h, 4, 0, 0);
        *(int*)(p + 0x8) = type;
        *(void**)(p + 0x4) = gfHeapManager::alloc(heapType, type);
        fn_801D76BC(*(void**)(p + 0x4), *(unsigned int*)(p + 0x8));
        fn_801F28F0(p + 0x10, *(void**)(p + 0x4), *(unsigned short*)(p + 0xC), *(unsigned short*)(p + 0xE), *(unsigned int*)p, 0, 0, 0);
        fn_801F2B44(p + 0x10, 0, 0, 0, 0, 0, lbl_805A15D0, lbl_805A15D0, lbl_805A15D0);
        p[0x30] = 0;
    }
}
