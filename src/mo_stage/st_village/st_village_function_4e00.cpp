#pragma force_active on
extern "C" {
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void free__13gfHeapManagerFPv(void*);
void __dl__FPv(void*);
void fn_70_20FC(void* p, int x);
extern char lbl_70_data_21D0[];
}

struct Anim {
    void* buf;
    unsigned char owns;
    void* f08;
    void* f0C;
    void* f10;
    void* f14;
    void* f18;
    void* f1C;
    ~Anim() {
        if (f0C) Destroy__Q34nw4r3g3d6G3dObjFv(f0C);
        if (f08) Destroy__Q34nw4r3g3d6G3dObjFv(f08);
        if (f10) Destroy__Q34nw4r3g3d6G3dObjFv(f10);
        if (f14) Destroy__Q34nw4r3g3d6G3dObjFv(f14);
        if (f18) Destroy__Q34nw4r3g3d6G3dObjFv(f18);
        if (f1C) Destroy__Q34nw4r3g3d6G3dObjFv(f1C);
        if (buf && owns) {
            free__13gfHeapManagerFPv(buf);
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
    void* vptr;
    char pad40[0x1c8 - 0x40];
    Anim* anim;
};

extern "C" Obj* fn_70_4E00(Obj* self, int flag) {
    if (self) {
        if (self) {
            Anim* anim = self->anim;
            self->vptr = lbl_70_data_21D0;
            if (anim) {
                delete anim;
                self->anim = 0;
            }
            fn_70_20FC(self, 0);
        }
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}
