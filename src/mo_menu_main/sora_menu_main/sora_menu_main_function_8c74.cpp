#include <gf/gf_heap_manager.h>
#include <it/it_manager.h>
#pragma force_active on
struct Data { u32 first; u32 rest[20]; };
struct Param { u8 kind; Data data; };
extern "C" void fn_2_8DB8(void*);
extern "C" void fn_1_6D4C(void*, void*, int);
extern "C" void* fn_801AB6CC(MEMAllocator*, void*, int);
extern "C" void fn_2_8C74(u8* self, void* scene, Param* param) {
    int i;
    u8* p;
    MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)0x2b);
    fn_2_8DB8(self);
    *(void**)(self + 0x40) = scene;
    *(u32*)(self + 0x25c) = *(u32*)(self + 0x48) = param->data.first;
    fn_1_6D4C(scene, self + 0x108, 4);
    p = self;
    for (i = 0; i < 4; i++, p += 4)
        *(void**)(p + 0x2a0) = gfHeapManager::alloc((Heaps::HeapType)0x2b, 0x400000);
    p = self;
    for (i = 0; i < 2; i++, p += 4)
        *(void**)(p + 0x2b0) = gfHeapManager::alloc((Heaps::HeapType)0x2b, 0x132000);
    void* figure = itManager::getInstance()->m_figureManager;
    if (figure)
        *(u32*)(self + 0xd8) = *(u32*)((u8*)figure + 4);
    else
        *(u32*)(self + 0xd8) = 0;
    *(u8*)(self + 0x44) = param->kind;
    *(Data*)(self + 0x48) = param->data;
    *(u8*)(self + 0x44) = param->kind;
    *(u32*)(self + 0x254) = param->kind;
    *(void**)(self + 0x29c) = fn_801AB6CC(allocator, 0, 1);
    *(u32*)(self + 0x238) = 0;
}