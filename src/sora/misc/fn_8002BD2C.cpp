#include <gf/gf_heap_manager.h>
#include <memory.h>
#include <types.h>
#pragma force_active on

struct HeapBlockHdr {
    u32 size;
    u32 unk4;
    u32 cnt8;
    u32 cntC;
    u32 cnt10;
    u32 pad14[3];
    void* p20;
    void* p24;
    void* p28;
    void* p2C;
    void* p30;
};

extern "C" void fn_8002BD2C(void* a0, HeapBlockHdr* self, u8* data) {
    u32 sz;
    u32 off;
    u8* base;
    if (self->p20 != 0) {
        gfHeapManager::free(self->p20);
    }
    if (self->p24 != 0) {
        gfHeapManager::free(self->p24);
    }
    if (self->p28 != 0) {
        gfHeapManager::free(self->p28);
    }
    if (self->p2C != 0) {
        gfHeapManager::free(self->p2C);
    }
    if (self->p30 != 0) {
        gfHeapManager::free(self->p30);
    }
    memset(self, 0, 0x40);
    memcpy(self, data, 0x20);
    off = self->unk4;
    self->p20 = gfHeapManager::alloc((Heaps::HeapType)7, off);
    memcpy(self->p20, data + 0x20, off);
    off += 0x20;
    if (self->cnt8 != 0) {
        sz = self->cnt8 * 4;
        self->p24 = gfHeapManager::alloc((Heaps::HeapType)7, sz);
        memcpy(self->p24, data + off, sz);
        off += sz;
    }
    if (self->cntC != 0) {
        sz = self->cntC * 8;
        self->p28 = gfHeapManager::alloc((Heaps::HeapType)7, sz);
        memcpy(self->p28, data + off, sz);
        off += sz;
    }
    if (self->cnt10 != 0) {
        sz = self->cnt10 * 8;
        self->p2C = gfHeapManager::alloc((Heaps::HeapType)7, sz);
        memcpy(self->p2C, data + off, sz);
        off += sz;
    }
    sz = self->size - off;
    if (sz != 0) {
        self->p30 = gfHeapManager::alloc((Heaps::HeapType)7, sz);
        memcpy(self->p30, data + off, sz);
    }
    for (u32 i = 0; i < self->cnt8; i++) {
        u32 o = ((u32*)self->p24)[i];
        base = (u8*)self->p20;
        *(u32*)(base + o) += (u32)base;
    }
}
