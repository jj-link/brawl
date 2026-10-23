#pragma force_active on

extern "C" void Destroy__Q34nw4r3g3d6G3dObjFv(void*);

struct Base {
    char pad[0x5c];
};

struct Outer : Base {
    virtual ~Outer();
};

extern "C" {
extern Outer* lbl_805A0338;
extern void* lbl_805A033C;
extern Outer* lbl_805A0340;
extern void* lbl_805A0344;
}

extern "C" void fn_8010BE98(void) {
    if (lbl_805A033C != 0) {
        Destroy__Q34nw4r3g3d6G3dObjFv(lbl_805A033C);
        lbl_805A033C = 0;
    }
    if (lbl_805A0338 != 0) {
        delete lbl_805A0338;
        lbl_805A0338 = 0;
    }
    if (lbl_805A0344 != 0) {
        Destroy__Q34nw4r3g3d6G3dObjFv(lbl_805A0344);
        lbl_805A0344 = 0;
    }
    if (lbl_805A0340 != 0) {
        delete lbl_805A0340;
        lbl_805A0340 = 0;
    }
}
