#pragma force_active on

extern "C" void Destroy__Q34nw4r3g3d6G3dObjFv(void*);

struct Base {
    char pad[0x5c];
};

struct Outer : Base {
    virtual ~Outer();
};

extern "C" {
extern void* lbl_805A032C;
extern Outer* lbl_805A0328;
}

extern "C" void fn_801084CC(void) {
    if (lbl_805A032C != 0) {
        Destroy__Q34nw4r3g3d6G3dObjFv(lbl_805A032C);
        lbl_805A032C = 0;
    }
    if (lbl_805A0328 != 0) {
        delete lbl_805A0328;
        lbl_805A0328 = 0;
    }
}
