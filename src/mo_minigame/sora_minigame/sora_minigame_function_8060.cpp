#pragma force_active on

struct Resource {
    char pad[8];
    void* manager;
};

struct Animation {
    void* buffer;
    unsigned char owns;
    char pad[3];
    void* a;
    void* b;
    void* c;
    void* d;
    void* e;
    void* f;
};

struct Elem {
    char pad[0x20];
    unsigned char f20;
    char p2[3];
    Resource* f24;
    void* f28;
    Animation* f2c;
};

extern "C" {
void unbind__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(void*);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void free__13gfHeapManagerFPv(void*);
void __dl__FPv(void*);
void remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(void*, void*);
void fn_802ECBC0(void*, Resource*);
void fn_802F0668(Resource*);
void fn_8027CE3C(void*, int);
}

extern void* g_gfSceneRoot;

struct Vec {
    Elem** data;
    int size;
    unsigned int raw;
};

struct Obj {
    char pad[0x4e8];
    Vec v1;
    Vec v2;
};

extern "C" void fn_20_8060(Obj* o) {
    void* root = g_gfSceneRoot;
    for (int i = o->v1.size - 1; i >= 1; i--) {
        if (o->v1.data[i]->f28) {
            unbind__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(o->v1.data[i]->f28);

            Animation* a = o->v1.data[i]->f2c;
            if (a) {
                if (a->b)
                    Destroy__Q34nw4r3g3d6G3dObjFv(a->b);
                if (a->a)
                    Destroy__Q34nw4r3g3d6G3dObjFv(a->a);
                if (a->c)
                    Destroy__Q34nw4r3g3d6G3dObjFv(a->c);
                if (a->d)
                    Destroy__Q34nw4r3g3d6G3dObjFv(a->d);
                if (a->e)
                    Destroy__Q34nw4r3g3d6G3dObjFv(a->e);
                if (a->f)
                    Destroy__Q34nw4r3g3d6G3dObjFv(a->f);

                if (a->buffer && a->owns) {
                    free__13gfHeapManagerFPv(a->buffer);
                    a->buffer = 0;
                }

                a->b = 0;
                a->a = 0;
                a->c = 0;
                a->d = 0;
                a->e = 0;
                a->f = 0;
                __dl__FPv(a);
            }

            o->v1.data[i]->f2c = 0;
            remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(root, o->v1.data[i]->f28);
            o->v1.data[i]->f20 = 1;
        }

        fn_802ECBC0(o->v1.data[0]->f24->manager, o->v1.data[i]->f24);
        fn_802F0668(o->v1.data[i]->f24);

        Elem* e = o->v1.data[i];
        if (o->v2.size == (int)(o->v2.raw & 0x3FFFFFFF))
            fn_8027CE3C(&o->v2, 4);
        o->v2.data[o->v2.size++] = e;
        o->v1.size--;
    }
}
