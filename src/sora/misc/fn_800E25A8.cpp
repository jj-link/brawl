#include <gf/gf_file_io_handle.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <mu/mu_object.h>
#include <stdio.h>
#pragma force_active on

extern "C" {
extern char lbl_8045A31C[];
extern char lbl_8045A35C[];
extern float lbl_805A23B0;
void fn_800B7184(MuObject*, const char*, int, void*);
}

struct Self {
    char pad0[0xb8];
    MuObject* object;
    char pad1[0x290 - 0xbc];
    gfFileIOHandle handle;
    void* res;
    int current;
    int pending;
    int state;
    void* buffer;
};

extern "C" void fn_800E25A8(Self* self) {
    char path[64];
    switch (self->state) {
    case 2:
        if (self->handle.isReady()) {
            self->res = self->buffer;
            nw4r::g3d::ResFile::Init(&self->res);
            self->handle.release();
            fn_800B7184(self->object, lbl_8045A31C, 0, &self->res);
            self->object->setFrameVisible(lbl_805A23B0);
            self->state = 1;
        }
        break;
    case 3:
        if (self->handle.isReady()) {
            int pending = self->pending;
            if (pending >= 0) {
                sprintf(path, lbl_8045A35C, pending);
                self->handle.readRequestNoSync(path, self->buffer, 0, 0);
                self->current = pending;
                self->pending = -1;
                self->state = 2;
            } else {
                self->state = 1;
            }
        }
        break;
    }
}