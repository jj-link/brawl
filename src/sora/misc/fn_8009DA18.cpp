#include <gf/gf_heap_manager.h>
#include <string.h>
#pragma force_active on

struct Anim { char pad[0x1c]; unsigned short frames; };
struct Names { const char* names[5]; };
struct Object {
    char pad[0x22c];
    void* buffer;
    Anim* anim[5];
    float frames[5];
};
extern "C" {
extern const Names lbl_804078E0;
extern const float lbl_805A1DC8;
Anim* fn_8018D5D4(void**, const char*);
int fn_8009DA18(Object* self, const void* data, unsigned long size, Heaps::HeapType heap) {
    if (!data || !size) return 0;
    if (self->buffer) {
        if (self->buffer) {
            gfHeapManager::free(self->buffer);
            self->buffer = 0;
        }
        for (int i = 0; i < 5; i++) {
            self->anim[i] = 0;
            self->frames[i] = lbl_805A1DC8;
        }
    }
    void* buffer = gfHeapManager::alloc(heap, size, 0x20);
    if (!buffer) return 0;
    memcpy(buffer, data, size);
    self->buffer = buffer;
    void* res = buffer;
    gfHeapManager::getMEMAllocator(heap);
    Names names = lbl_804078E0;
    for (int i = 0; i < 5; i++) {
        self->anim[i] = fn_8018D5D4(&res, names.names[i]);
        if (self->anim[i])
            self->frames[i] = (float)(int)self->anim[i]->frames;
    }
    return 1;
}
}