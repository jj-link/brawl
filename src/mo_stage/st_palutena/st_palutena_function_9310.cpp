#pragma force_active on
#include <types.h>
#include <nw4r/g3d/g3d_obj.h>
#include <gf/gf_heap_manager.h>
#include <sr/sr_common.h>
extern "C" {
void fn_67_C9CC(void*, int);
extern char lbl_67_data_2188[];
}
struct Anim {
    void* buf;
    unsigned char owns;
    nw4r::g3d::G3dObj* f08;
    nw4r::g3d::G3dObj* f0C;
    nw4r::g3d::G3dObj* f10;
    nw4r::g3d::G3dObj* f14;
    nw4r::g3d::G3dObj* f18;
    nw4r::g3d::G3dObj* f1C;
    ~Anim() {
        if (f0C) f0C->Destroy();
        if (f08) f08->Destroy();
        if (f10) f10->Destroy();
        if (f14) f14->Destroy();
        if (f18) f18->Destroy();
        if (f1C) f1C->Destroy();
        if (buf && owns) {
            gfHeapManager::free(buf);
            buf = 0;
        }
        f0C = 0;
        f08 = 0;
        f10 = 0;
        f14 = 0;
        f18 = 0;
        f1C = 0;
    }
    static void operator delete(void* p) { ::operator delete(p); }
};
struct Obj {
    char pad0[0x3c];
    void* vptr;
    char pad40[0x16c - 0x40];
    Anim* anim;
};
extern "C" Obj* fn_67_9310(Obj* self, int flag) {
    if (self) {
        Anim* anim = self->anim;
        self->vptr = lbl_67_data_2188;
        if (anim) {
            delete anim;
        }
        self->anim = 0;
        fn_67_C9CC(self, 0);
        if (flag > 0)
            ::operator delete(self);
    }
    return self;
}