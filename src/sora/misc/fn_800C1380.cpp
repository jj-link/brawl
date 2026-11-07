#pragma force_active on
#include <gf/gf_file_io_handle.h>
#include <nw4r/g3d/g3d_resfile.h>

struct IOPair {
    gfFileIOHandle handle;
    void* buffer;
};

struct Entry {
    int type;
    char pad[0xC];
};

struct Self {
    char pad0[0x10C];
    int f10C;
    char pad110[0x11C - 0x110];
    Entry entries[16];
    int count21C;
    int index220;
    char pad224[0x22C - 0x224];
    IOPair single22C;
    IOPair arr234[17];
    IOPair single2BC;
    IOPair arr2C4[16];
    IOPair single344;
    IOPair arr34C[4];
};

extern "C" int fn_800C1380(Self* self) {
    IOPair* p;
    int r0;
    int idx = self->index220;
    switch (self->entries[idx].type) {
    case 0:
        p = &self->arr234[idx];
        if (self->single22C.buffer == 0) {
            if (!self->single22C.handle.isReady()) { r0 = 0; goto done; }
            self->single22C.buffer = self->single22C.handle.getBuffer();
            self->single22C.handle.release();
        }
        if (p->buffer == 0) {
            if (!p->handle.isReady()) { r0 = 0; goto done; }
            p->buffer = p->handle.getBuffer();
            nw4r::g3d::ResFile::Init(&p->buffer);
            p->handle.release();
        }
        r0 = 1;
        break;
    case 1:
        p = &self->arr2C4[idx];
        if (self->single2BC.buffer == 0) {
            if (!self->single2BC.handle.isReady()) { r0 = 0; goto done; }
            self->single2BC.buffer = self->single2BC.handle.getBuffer();
            self->single2BC.handle.release();
        }
        if (p->buffer == 0) {
            if (!p->handle.isReady()) { r0 = 0; goto done; }
            p->buffer = p->handle.getBuffer();
            nw4r::g3d::ResFile::Init(&p->buffer);
            p->handle.release();
        }
        r0 = 1;
        break;
    case 2:
        if (self->single344.buffer == 0) {
            if (!self->single344.handle.isReady()) { r0 = 0; goto done; }
            self->single344.buffer = self->single344.handle.getBuffer();
            self->single344.handle.release();
        }
        r0 = 1;
        break;
    case 3:
        p = &self->arr34C[idx];
        if (p->buffer == 0) {
            if (!p->handle.isReady()) { r0 = 0; goto done; }
            p->buffer = p->handle.getBuffer();
            nw4r::g3d::ResFile::Init(&p->buffer);
            p->handle.release();
        }
        r0 = 1;
        break;
    default:
        r0 = 1;
        break;
    }
done:
    if (r0 != 0) {
        return 2;
    }
    return self->f10C;
}
