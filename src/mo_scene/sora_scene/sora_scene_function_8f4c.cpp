#include <types.h>
#pragma force_active on

extern "C" void* getInstance__14gfSceneManagerFv();
extern "C" void fn_1_8EC0(void*);
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* __ct__9gfArchiveFv(void*);
extern "C" void fn_1_3C68(void*, int, void*, void*, int);
extern "C" char lbl_1_data_20F8[];
extern "C" void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);

extern "C" void fn_1_8F4C(char* self) {
    char* mgr = (char*)getInstance__14gfSceneManagerFv();
    if (*(int*)(mgr + 0x280) == 0) {
        fn_1_8EC0(self);
        *(int*)(self + 0x36c) = *(int*)(self + 0x394);
    } else {
        self[0x380] = 1;
    }

    int zero = 0;
    *(void**)(self + 0x35c) = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(0x2a, 8);
    *(int*)(*(char**)(self + 0x35c)) = zero;
    *(int*)(*(char**)(self + 0x35c) + 4) = zero;
    char* q = (char*)__nw__FUlQ25Heaps8HeapType(0x20, 0x2b);
    if (q != 0) {
        int ff = 0xff;
        *(int*)(q + 0x0) = zero;
        *(int*)(q + 0x4) = zero;
        *(int*)(q + 0x8) = zero;
        *(int*)(q + 0xc) = zero;
        *(int*)(q + 0x10) = zero;
        unsigned char b = (unsigned char)q[0x1c];
        *(int*)(q + 0x18) = zero;
        *(int*)(q + 0x14) = ff;
        q[0x1c] = (char)(b & ~0xE0);
    }
    *(char**)(self + 0x39c) = q;

    char* a = (char*)__nw__FUlQ25Heaps8HeapType(0x80, 0x2b);
    char* arc = a;
    if (a != 0) {
        arc = (char*)__ct__9gfArchiveFv(a);
    }
    *(char**)(self + 0x398) = arc;
    fn_1_3C68(*(void**)(self + 0x39c), 0x2b, lbl_1_data_20F8, arc, 0);
}
