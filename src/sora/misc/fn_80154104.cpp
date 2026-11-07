#include <gf/gf_heap_manager.h>
#include <string.h>
#pragma force_active on

struct Entry {
    char data[0x1c];
    unsigned long size;
    void* buffer;
};

struct Object {
    Entry entries[5];
    int count;
    Heaps::HeapType heap;
};

extern "C" int fn_80154104(Object* self, Entry* input) {
    if (!input)
        return 0;
    int result = 0;
    if (self->count < 5) {
        unsigned long size = input->size;
        if (!size)
            return 0;
        Entry* entry = &self->entries[self->count];
        entry->buffer = gfHeapManager::alloc(self->heap, size, 0x20);
        if (!entry->buffer)
            return 0;
        memcpy(entry, input, 0x20);
        memcpy(entry->buffer, (char*)input + 0x20, size);
        self->count++;
        result = 1;
    }
    return result;
}