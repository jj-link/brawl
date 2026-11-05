#include <gf/gf_model.h>
#include <gf/gf_3d_scene.h>
#include <gf/gf_heap_manager.h>
#pragma force_active on

struct Animation {
    void* buffer;
    unsigned char owns;
    char pad[3];
    nw4r::g3d::G3dObj* a;
    nw4r::g3d::G3dObj* b;
    nw4r::g3d::G3dObj* c;
    nw4r::g3d::G3dObj* d;
    nw4r::g3d::G3dObj* e;
    nw4r::g3d::G3dObj* f;
};
struct Resource { char pad[8]; void* manager; };
struct Elem { char pad[0x24]; Resource* resource; };
struct LocalVec;
extern "C" void fn_8027CE3C(LocalVec*, int);
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern "C" void fn_802ECBC0(void*, Resource*);
extern "C" void fn_802F0668(Resource*);
extern void* lbl_805A0EC8;
extern int lbl_20_data_438[5];
struct LocalVec {
    Elem** data;
    int size;
    union {
        struct { unsigned int noFree:1; unsigned int b:1; unsigned int cap:30; } bf;
        unsigned int raw;
    };
    void push_back(Elem* e) {
        if (size == (int)bf.cap) fn_8027CE3C(this, 4);
        data[size++] = e;
    }
    bool isOwned() const { return (raw & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, raw << 2, 0x15); }
    void clear() {
        if (isOwned()) dealloc();
        data = 0;
        size = 0;
        raw = (raw & 0x40000000) | 0x80000000;
    }
};
struct Obj {
    char pad[0x3b0];
    nw4r::g3d::ScnMdl* models[5][6];
    unsigned char flags[5][6];
    char pad2[2];
    Animation* anims[5][6];
    char pad3[0x1c];
    LocalVec v1;
    char pad4[0x0c];
    LocalVec v2;
};
inline void cleanup(Animation* a) {
    if (a) {
        if (a->b) a->b->Destroy();
        if (a->a) a->a->Destroy();
        if (a->c) a->c->Destroy();
        if (a->d) a->d->Destroy();
        if (a->e) a->e->Destroy();
        if (a->f) a->f->Destroy();
        if (a->buffer && a->owns) {
            gfHeapManager::free(a->buffer);
            a->buffer = 0;
        }
        a->b = 0;
        a->a = 0;
        a->c = 0;
        a->d = 0;
        a->e = 0;
        a->f = 0;
        delete a;
    }
}
extern "C" void fn_20_7C30(Obj* o) {
    gfSceneRoot* root = g_gfSceneRoot;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < lbl_20_data_438[i]; j++) {
            gfModelAnimation::unbind(o->models[i][j]);
            cleanup(o->anims[i][j]);
            o->anims[i][j] = 0;
            root->remove(o->models[i][j]);
            o->flags[i][j] = 1;
        }
    }
    for (int i = o->v1.size - 1; i >= 0; i--) {
        fn_802ECBC0(o->v1.data[0]->resource->manager, o->v1.data[i]->resource);
        fn_802F0668(o->v1.data[i]->resource);
        o->v2.push_back(o->v1.data[i]);
    }
    o->v1.clear();
}