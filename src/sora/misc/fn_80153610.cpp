#include <types.h>
#include <string.h>
#include <gf/gf_heap_manager.h>
#include <gm/gm_global.h>
#pragma force_active on
struct Object_vptr_8_base { u32 kind; u32 pad; };
class Object_vptr_8 : public Object_vptr_8_base {
public:
virtual void slot0();
virtual void* slot1();
virtual u32 slot2();
};
struct Hdr { u64 time; u64 id; u32 crc; u8 flags; u8 kind; u8 b16; u8 b17; u32 size; u32 csize; };
struct Holder { Hdr* buf; u8 owned; };
extern "C" {
u64 fn_8014FEB4();
u8 getLanguage__10GameGlobalFv(GameGlobal*);
u8 fn_8004EAC8(GameGlobal*);
u32 fn_80204FC8(void*, u32, void*, void*, int);
u32 NETCalcCRC32(void*, u32);
int fn_80153610(Holder* self, Object_vptr_8* src, u64 id, Heaps::HeapType heap, u8 b, void* work) {
Hdr* h;
GameGlobal* g;
if (self->owned) {
if (self->buf) gfHeapManager::free(self->buf);
self->owned = 0;
}
self->buf = 0;
if (!src) return 0;
void* data = src->slot1();
u32 size = src->slot2();
if (!data || !size) return 0;
self->buf = (Hdr*)gfHeapManager::alloc(heap, size + 0x20, 0x20);
if (!self->buf) return 0;
void* w = work;
if (!work) {
w = gfHeapManager::alloc(heap, 0x2400, 0x20);
if (!w) {
gfHeapManager::free(self->buf);
self->buf = 0;
return 0;
}
}
self->owned = 1;
h = self->buf;
u8* dst = (u8*)self->buf + 0x20;
h->time = fn_8014FEB4();
g = g_GameGlobal;
u8 lang = getLanguage__10GameGlobalFv(g);
u8 hi = fn_8004EAC8(g);
h->flags = (hi << 5) | lang;
h->kind = src->kind;
h->b16 = b;
h->id = id;
h->size = size;
h->b17 = 0xdb;
u32 cs = fn_80204FC8(data, size, dst, w, 1);
if (!cs) { cs = size; memcpy(dst, data, size); }
h->csize = cs;
h->crc = 0xDEADBEEF;
h->crc = NETCalcCRC32(h, cs + 0x20);
if (!work && w) gfHeapManager::free(w);
return 1;
}
}
