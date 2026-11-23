#include <gf/gf_file_io_handle.h>
#include <nw4r/g3d/g3d_resfile.h>

#pragma force_active on
#pragma opt_propagation off
#pragma opt_lifetimes off

struct Self {
    unsigned char flags;
    char pad[7];
    void* f8;
    void* fC;
    void* f10;
    char pad2[0x34];
    void* f48;
    void* f4C;
    char pad3[4];
    gfFileIOHandle h[5];
};

extern "C" int fn_800FC660(void* buffer) {
    char* handle;
    int i;
    Self* self = (Self*)buffer;
    void* resource2;
    void* resource1;
    void* resource0;

    if ((unsigned)((self->flags >> 7) & 1) == 1)
        return 1;

    handle = (char*)self->h;
    i = 0;
    do {
        if (!((gfFileIOHandle*)handle)->isReady())
            return 0;
        ++i;
        handle += 4;
    } while (i < 5);

    resource0 = 0;
    if (self->h[0].getReturnStatus() == 0x15)
        handle = 0;
    else {
        handle = (char*)self->h[0].getBuffer();
        self->h[0].release();
    }
    if (handle) {
        resource0 = handle;
        nw4r::g3d::ResFile::Init(&resource0);
    }
    self->f8 = resource0;

    resource1 = 0;
    if (self->h[1].getReturnStatus() == 0x15)
        handle = 0;
    else {
        handle = (char*)self->h[1].getBuffer();
        self->h[1].release();
    }
    if (handle) {
        resource1 = handle;
        nw4r::g3d::ResFile::Init(&resource1);
    }
    self->fC = resource1;

    resource2 = 0;
    if (self->h[2].getReturnStatus() == 0x15)
        handle = 0;
    else {
        handle = (char*)self->h[2].getBuffer();
        self->h[2].release();
    }
    if (handle) {
        resource2 = handle;
        nw4r::g3d::ResFile::Init(&resource2);
    }
    self->f10 = resource2;

    if (self->h[3].getReturnStatus() == 0x15)
        handle = 0;
    else {
        handle = (char*)self->h[3].getBuffer();
        self->h[3].release();
    }
    self->f48 = handle;

    if (self->h[4].getReturnStatus() == 0x15)
        handle = 0;
    else {
        handle = (char*)self->h[4].getBuffer();
        self->h[4].release();
    }
    self->f4C = handle;
    self->flags |= 0x80;
    return 1;
}
