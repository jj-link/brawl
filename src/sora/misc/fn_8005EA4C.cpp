#include <types.h>
#pragma force_active on

struct Entry {
    void* archive;
    char pad[12];
    u32 id;
    char pad2[4];
};
struct Manager {
    char pad[0x44];
    int heap;
    char pad2[0x10];
    Entry* entries;
    u32 count;
};
extern "C" {
extern unsigned char lbl_80407060[];
void fn_80063F40(Entry*, void*, int, u32);
}
inline Entry* findEntry(Manager* self, u32 id) {
    for (u32 i = 0; i < self->count; i++) {
        if (self->entries[i].archive && self->entries[i].id == id)
            return &self->entries[i];
    }
    return 0;
}
extern "C" void fn_8005EA4C(Manager* self, u32 id, void* file, int size, int unused, int heap) {
    if (!findEntry(self, id) && lbl_80407060[id]) {
        u32 i;
        for (i = 0; i < self->count; i++) {
            if (!self->entries[i].archive)
                break;
        }
        if (i < self->count) {
            int oldHeap = self->heap;
            if (heap != 0xff)
                self->heap = heap;
            if (file)
                fn_80063F40(&self->entries[i], file, size, id);
            self->heap = oldHeap;
        }
    }
}