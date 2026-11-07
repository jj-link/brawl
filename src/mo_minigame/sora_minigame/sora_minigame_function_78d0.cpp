#pragma force_active on

#include <nw4r/g3d/g3d_scnmdlsmpl.h>

struct Resource {
    char pad[8];
    void* manager;
};

struct Elem {
    char pad[0x20];
    unsigned char f20;
    char p2[3];
    Resource* f24;
    void* f28;
    void* f2c;
    void* f30;
    char p3[0x68 - 0x34];
    unsigned int f68;
};

extern "C" {
void fn_80106208(void* p);
void fn_8027CE3C(void* self, int n);
void fn_8027EABC(void* a, void* b, unsigned int c, int d);
void fn_802ECBC0(void* a, void* b);
void fn_802F0668(void* a);
void remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(void* root, void* mdl);
}

extern void* g_gfSceneRoot;
extern void* lbl_805A0EC8;

struct ElemVec {
    Elem** data;
    int size;
    unsigned int raw;

    bool isOwned() const {
        return (raw & 0x80000000) == 0;
    }

    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data, raw << 2, 0x15);
    }

    void clear() {
        if (isOwned())
            dealloc();
        data = 0;
        size = 0;
        raw = (raw & 0x40000000) | 0x80000000;
    }
};

struct Obj {
    char pad0[0x34c];
    void* arr34c[97];
    ElemVec v1;
    char pad1[0x4f4 - 0x4dc];
    ElemVec v2;
};

extern "C" void fn_20_78D0(Obj* o) {
    for (int i = o->v1.size - 1; i >= 0; i--) {
        if (o->v1.data[i]->f30 != 0) {
            unsigned int idx = o->v1.data[i]->f68;
            void* p = o->arr34c[idx];
            if (p != 0) {
                fn_80106208(p);
            }
            o->arr34c[idx] = 0;
            void* a = o->v1.data[i]->f2c;
            if (a != 0) {
                ((nw4r::g3d::ScnMdlSimple*)o->v1.data[i]->f30)->RemoveAnmObj((nw4r::g3d::ScnMdlSimple::AnmObjType)(u32)a);
                o->v1.data[i]->f20 = 1;
            }
            remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, o->v1.data[i]->f30);
            o->v1.data[i]->f20 = 1;
            if (o->v1.data[i]->f28 != 0) {
                o->v1.data[i]->f20 = 1;
            }
        } else if (o->v1.data[i]->f2c != 0) {
            o->v1.data[i]->f20 = 1;
        }

        fn_802ECBC0(o->v1.data[0]->f24->manager, o->v1.data[i]->f24);
        fn_802F0668(o->v1.data[i]->f24);

        Elem* e = o->v1.data[i];
        if (o->v2.size == (int)(o->v2.raw & 0x3FFFFFFF)) {
            fn_8027CE3C(&o->v2, 4);
        }
        o->v2.data[o->v2.size++] = e;
    }

    o->v1.clear();
}
