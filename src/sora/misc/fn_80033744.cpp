#include <types.h>
#include <gf/gf_task.h>
#include <gf/gf_heap_manager.h>
#include <revolution/GX/GXTypes.h>
#include <string.h>
#pragma force_active on

extern "C" {
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
extern char lbl_80423148[];
extern char lbl_8042316C[];
extern GXColor lbl_805A15F0, lbl_805A15F4, lbl_805A15F8, lbl_805A15FC;
extern const f32 lbl_805A1600, lbl_805A1604, lbl_805A1608, lbl_805A160C;
}
inline void setColor(GXColor* dest, GXColor color) { *dest = color; }

extern "C" gfTask* fn_80033744(gfTask* self, Heaps::HeapType heap, s16 type) {
    u8* s = (u8*)self;
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_80423148, 0, 0, 1, true);
    *(char**)(s + 0x3C) = lbl_8042316C;
    *(u8*)(s + 0x94) = 0;
    *(u8*)(s + 0x95) = 0;
    *(s16*)(s + 0x96) = 0;
    *(s16*)(s + 0x98) = 0;
    *(s32*)(s + 0x9C) = 0;
    *(s16*)(s + 0xA0) = 0;
    *(s16*)(s + 0xA2) = 0;
    *(u8*)(s + 0xA4) = 0;
    *(u8*)(s + 0xA5) = 0;
    *(s16*)(s + 0xA6) = 0;
    *(s16*)(s + 0xA8) = 0;
    *(s32*)(s + 0xAC) = 0;
    *(s16*)(s + 0xB0) = 0;
    *(s16*)(s + 0xB2) = 0;
    *(s32*)(s + 0xE8) = 0;
    *(Heaps::HeapType*)(s + 0x40) = heap;
    *(s32*)(s + 0x4C) = 0;
    *(s32*)(s + 0x50) = 0;
    *(s32*)(s + 0x54) = 0;
    *(s16*)(s + 0x48) = type;
    if (type == 0) *(s16*)(s + 0x48) = 6;
    *(s32*)(s + 0xB4) = 0;
    memset(s + 0x7C, 0, 8);
    memset(s + 0x84, 0, 8);
    *(s32*)(s + 0x8C) = 0;
    *(s16*)(s + 0x90) = 0;
    self->init();
    setColor((GXColor*)(s + 0xB8), lbl_805A15F0);
    setColor((GXColor*)(s + 0xBC), lbl_805A15F4);
    *(f32*)(s + 0xC0) = lbl_805A1600;
    *(f32*)(s + 0xC4) = lbl_805A1604;
    *(f32*)(s + 0xC8) = lbl_805A1604;
    *(f32*)(s + 0xCC) = lbl_805A1608;
    setColor((GXColor*)(s + 0xD0), lbl_805A15F8);
    setColor((GXColor*)(s + 0xD4), lbl_805A15FC);
    *(f32*)(s + 0xD8) = lbl_805A1604;
    *(f32*)(s + 0xDC) = lbl_805A160C;
    *(f32*)(s + 0xE0) = lbl_805A1608;
    *(u8*)(s + 0xE4) = 1;
    u32 size = (u16)*(s16*)(s + 0x48) << 13;
    *(void**)(s + 0x70) = gfHeapManager::alloc(*(Heaps::HeapType*)(s + 0x40), size, 0x20);
    *(void**)(s + 0x74) = gfHeapManager::alloc(*(Heaps::HeapType*)(s + 0x40), size, 0x20);
    *(void**)(s + 0x78) = gfHeapManager::alloc(*(Heaps::HeapType*)(s + 0x40), size, 0x20);
    return self;
}
