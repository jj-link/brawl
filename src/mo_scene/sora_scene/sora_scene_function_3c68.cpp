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

extern "C" void* fn_1_3C68(Loader* self, HeapType heap, const char* path, void* archive, u32 leave) {
    if (!self->active) {
        self->allocSize = gfHeapManager::getMaxFreeSize(heap) - 0x800 - leave;
        self->resource = gfHeapManager::alloc(heap, self->allocSize);
        self->compressed = static_cast<char*>(self->resource) + self->allocSize - gfFileIO::getFileSize(path);
        if (self->cached) {
            self->handle.readRequestCached(path, self->compressed, 0, 0);
        } else {
            self->handle.readRequest(path, self->compressed, 0, 0);
        }
        self->heap = heap;
        self->archive = archive;
        self->loaded = false;
        self->active = true;
    }
    return self->resource;
}