#include <gf/gf_file_io.h>
#include <gf/gf_file_io_handle.h>
#include <gf/gf_heap_manager.h>
#include <types.h>
#pragma force_active on

struct Loader {
    gfFileIOHandle handle;
    void* compressed;
    u32 allocSize;
    u32 resourceSize;
    void* resource;
    HeapType heap;
    void* archive;
    u8 loaded : 1;
    u8 cached : 1;
    u8 active : 1;
};

extern "C" {
    extern Loader *lbl_1_bss_18;
    extern void *lbl_1_bss_1C;
    extern char lbl_1_data_288[];
}

static inline const char* pathOf(const char* p) {
    const char* q = p;
    return q;
}

static inline void* archiveOf(void* p) {
    void* q = p;
    return q;
}

static inline void* loadFile(Loader* self, HeapType heap, void* archive, const char* path, u32 leave) {
    if (!self->active) {
        self->allocSize = gfHeapManager::getMaxFreeSize(heap) - 0x800 - leave;
        self->resource = gfHeapManager::alloc(heap, self->allocSize);
        self->compressed = static_cast<char*>(self->resource) + self->allocSize - gfFileIO::getFileSize(path);
        if (self->cached) {
            self->handle.readRequestCached(path, self->compressed, 0, 0);
        } else {
            self->handle.readRequest(path, self->compressed, 0, 0);
        }
        u32 flags = *(u8*)((char*)self + 0x1C);
        self->heap = heap;
        self->archive = archive;
        *(u8*)((char*)self + 0x1C) = (u8)((flags & 0xFFFFFF7F) | 0x20);
    }
    return self->resource;
}

extern "C" void fn_1_3AC0(void) {
    loadFile(lbl_1_bss_18, (HeapType)0x29, archiveOf(lbl_1_bss_1C), pathOf(lbl_1_data_288), 0);
}
