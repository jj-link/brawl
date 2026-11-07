#include <gf/gf_file_io_handle.h>
#include <gf/gf_heap_manager.h>
#pragma force_active on

struct Resource {
    virtual ~Resource();
};

struct Object {
    char padding[0x604];
    gfFileIOHandle handle;
    unsigned char flag;
    char padding2[3];
    Resource* resource;
};

extern "C" void __dt__14gfFileIOHandleFv(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" Object* fn_5_11B70(Object* self, int flag) {
    if (self) {
        if (self->flag == 0) {
            gfHeapManager::free(self->handle.getBuffer());
            self->handle.release();
        }
        if (self->resource) {
            Resource* resource = self->resource;
            delete resource;
            self->resource = 0;
        }
        __dt__14gfFileIOHandleFv(&self->handle, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}