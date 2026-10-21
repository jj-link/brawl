#include <types.h>
#pragma force_active on

extern "C" void* fn_8015C1B0(void*, void*);
extern "C" void fn_8015C144(void*, void*);
extern "C" void fn_8015BFB4(void*, void*);

struct List {
    void* first;
    void* last;
    u16 count;
    u16 pad;
};

struct Entry {
    List lists[3];
    u32 field24;
    u32 flags;
    u32 field2C;
    u32 field30;
};

struct Main {
    u8 pad[0x98];
    List freeList;
    Entry* entries;
};

extern "C" void fn_27_501F4(Main* self, s32 index) {
    Entry* entry = &self->entries[index];

    while (entry->lists[0].count != 0) {
        void* node = fn_8015C1B0(&entry->lists[0], 0);
        fn_8015C144(&entry->lists[0], node);
        fn_8015BFB4(&self->freeList, node);
    }

    while (entry->lists[1].count != 0) {
        void* node = fn_8015C1B0(&entry->lists[1], 0);
        fn_8015C144(&entry->lists[1], node);
        fn_8015BFB4(&self->freeList, node);
    }

    while (entry->lists[2].count != 0) {
        void* node = fn_8015C1B0(&entry->lists[2], 0);
        fn_8015C144(&entry->lists[2], node);
        fn_8015BFB4(&self->freeList, node);
    }

    entry->flags &= ~1u;
}
