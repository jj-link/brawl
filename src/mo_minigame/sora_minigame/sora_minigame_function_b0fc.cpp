#pragma force_active on

struct Elem {
    char pad[0x20];
    unsigned char f20;
};

struct Vec;
extern "C" void fn_8027CE3C(Vec*, int);

struct Vec {
    Elem** data;
    int size;
    union {
        struct {
            unsigned int noFree : 1;
            unsigned int b : 1;
            unsigned int cap : 30;
        } bf;
        unsigned int raw;
    };

    void push_back(Elem* e) {
        if (size == (int)bf.cap)
            fn_8027CE3C(this, 4);
        data[size++] = e;
    }
};

struct Work {
    char pad0[0x60];
    int f60;
    char pad64[0x244 - 0x64];
    Elem* arr[5][7];
    Elem* f2d0;
    char pad2d4[0x2ec - 0x2d4];
    void* f2ec;
    char pad2f0[0x308 - 0x2f0];
    int f308;
    char pad30c[4];
    void* f310;
    char pad314[0x31c - 0x314];
    char f31c[0x334 - 0x31c];
    char f334[0x4f4 - 0x334];
    Vec v;
};

struct Sub {
    char pad[0xc];
    void* fc;
};

struct Self {
    char pad[0x10];
    Sub* f10;
    Work* f14;
    void* f18;
    void* f1c;
    void* f20;
    void* f24;
};

extern "C" {
void freeGroup__9sndSystemFii(void*, int, int);
void fn_802EE530(void*, void*);
void fn_8008093C(void*);
void fn_80080868(void*, int);
void unbind__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(void*);
void removeResAnmScn__11gfSceneRootFv(void*);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void fn_20_77D0(Work*);
void fn_20_78D0(Work*);
void fn_20_7C30(Work*);
void fn_20_7E58(Work*);
void __dt__9gfArchiveFv(void*, int);
void fn_8018E808(void*);
void fn_8009DEE8();
void stopMotor__11gfPadSystemFi(void*, int);
}

extern void* g_sndSystem;
extern void* g_gfSceneRoot;
extern void* g_gfPadSystem;

extern "C" void fn_20_B0FC(Self* self) {
    void* root;
    freeGroup__9sndSystemFii(g_sndSystem, self->f14->f308, 0);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            Elem* e = self->f14->arr[i][j];
            if (e) {
                e->f20 = 1;
                Work* w = self->f14;
                w->v.push_back(w->arr[i][j]);
            }
        }
    }
    self->f14->f2d0->f20 = 1;
    Work* w = self->f14;
    w->v.push_back(w->f2d0);
    if (self->f1c) {
        fn_802EE530(self->f10->fc, self->f1c);
    }
    if (self->f18) {
        fn_802EE530(self->f10->fc, self->f18);
    }
    if (self->f24) {
        fn_8008093C(self->f24);
        fn_80080868(self->f24, 1);
    }
    if (self->f20) {
        fn_8008093C(self->f20);
        fn_80080868(self->f20, 1);
    }
    if (self->f14->f2ec) {
        root = g_gfSceneRoot;
        unbind__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(self->f14->f2ec);
        removeResAnmScn__11gfSceneRootFv(root);
        Destroy__Q34nw4r3g3d6G3dObjFv(self->f14->f2ec);
    }
    if (self->f14) {
        fn_20_77D0(self->f14);
        fn_20_78D0(self->f14);
        fn_20_7C30(self->f14);
        fn_20_7E58(self->f14);
    }
    __dt__9gfArchiveFv(self->f14->f310, 1);
    fn_8018E808(self->f14->f334);
    fn_8018E808(self->f14->f31c);
    fn_8009DEE8();
    stopMotor__11gfPadSystemFi(g_gfPadSystem, self->f14->f60);
}
