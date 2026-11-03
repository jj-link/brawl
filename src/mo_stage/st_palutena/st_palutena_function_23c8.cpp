#include <types.h>
#include <nw4r/g3d/g3d_obj.h>
#include <gf/gf_heap_manager.h>
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#pragma force_active on

extern "C" {
extern char lbl_67_data_11C8[];
void __dl__FPv(void*);
void* fn_67_20BC(void*, int);
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
    static void operator delete(void* p) { __dl__FPv(p); }
};

struct Obj {
    char pad0[0x3c];
    char* vptr;
    char pad40[0x1a4 - 0x40];
    Anim* anim;
    char pad1a8[0xc];
    void* p1b4;
    void* p1b8;
    void* p1bc;
    void* p1c0;
    void* p1c4;
    snd3DGenerator sound;
};

extern "C" Obj* fn_67_23C8(Obj* self, int flag) {
    if (self) {
        Anim* anim = self->anim;
        self->vptr = lbl_67_data_11C8;
        if (anim) delete anim;
        self->anim = 0;
        if (self->p1b4) __dl__FPv(self->p1b4);
        self->p1b4 = 0;
        if (self->p1b8) __dl__FPv(self->p1b8);
        self->p1b8 = 0;
        if (self->p1bc) __dl__FPv(self->p1bc);
        self->p1bc = 0;
        if (self->p1c0) __dl__FPv(self->p1c0);
        self->p1c0 = 0;
        if (self->p1c4) __dl__FPv(self->p1c4);
        self->p1c4 = 0;
        self->sound.snd3DGenerator::~snd3DGenerator();
        fn_67_20BC(self, 0);
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}