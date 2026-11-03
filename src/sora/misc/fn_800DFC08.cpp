#pragma force_active on

extern "C" void Destroy__Q34nw4r3g3d6G3dObjFv(void*);

struct Base {
    char pad[0x5c];
};

struct Outer : Base {
    virtual ~Outer();
};

extern "C" {
extern void* lbl_805A02DC;
extern Outer* lbl_805A02D8;
}

extern "C" void fn_800DFC08(void) {
    if (lbl_805A02DC != 0) {
        Destroy__Q34nw4r3g3d6G3dObjFv(lbl_805A02DC);
        lbl_805A02DC = 0;
    }
    if (lbl_805A02D8 != 0) {
        delete lbl_805A02D8;
        lbl_805A02D8 = 0;
    }
}