#pragma force_active on
#include <gf/gf_file_io_handle.h>

struct Obj {
    char pad0[0xBC];
    char m_bc[0xD8];
    char m_194[0x1B4];
    int m_348;
    int m_34c;
    int m_350;
    int m_354;
    gfFileIOHandle m_358;
    gfFileIOHandle m_35c;
    gfFileIOHandle m_360;
    unsigned char m_364;
    int m_368;
};

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
Obj* fn_29_F8(void*);
void fn_800B96E8(void*, int);
}

extern "C" Obj* fn_29_0(const int* args, int heap, int fileHeap)
{
    Obj* obj = (Obj*)__nw__FUlQ25Heaps8HeapType(0x36C, heap);

    if (obj != 0) {
        obj = fn_29_F8(obj);
    }

    obj->m_350 = heap;
    obj->m_354 = fileHeap;
    obj->m_368 = args[0];

    if (args[1] >= 0) {
        fn_800B96E8(obj->m_bc, (unsigned char)args[1]);
    }

    if (args[2] >= 0) {
        fn_800B96E8(obj->m_194, (unsigned char)args[2]);
    }

    obj->m_348 = args[3];
    obj->m_358.readRequest("/menu/adventure/selchrb.brres", (Heaps::HeapType)obj->m_354, 0, 0);
    obj->m_35c.readRequest("/menu/adventure/selchr_common.brres", (Heaps::HeapType)obj->m_354, 0, 0);
    obj->m_360.readRequest("/menu/adventure/mu_adv_selchrb_tbl.dat", (Heaps::HeapType)obj->m_354, 0, 0);

    obj->m_364 = 0;
    return obj;
}
