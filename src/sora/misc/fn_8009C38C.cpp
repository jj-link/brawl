#pragma force_active on

class gfCameraController_base {
public:
    char pad[0x4];
};

class gfCameraController : public gfCameraController_base {
public:
    virtual void slot0();
    virtual void draw();
    virtual void slot2(int);
};

extern "C" {
extern char lbl_80454BF0[];
extern char lbl_8049DEDC[];
extern void* lbl_805A0278;
void __dl__FPv(void*);
void __dt__6gfTaskFv(void*, int);
void __dt__22cmMeleeFixedControllerFv(void*, int);
void* fn_800A9E0C(void*, int);
void* fn_800AAA98(void*, int);
void fn_8015C304(void*);
}

struct gfTaskObj {
    char pad0[0x3C];
    char* vtbl;
    char pad40[8];
    int unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    gfCameraController* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    gfCameraController* unk68;
    void* unk6C;
    void* unk70;
    gfCameraController* unk74;
    void* unk78;
    char pad7C[4];
    void* unk80;
};

extern "C" gfTaskObj* fn_8009C38C(gfTaskObj* self, int flag) {
    if (self != 0) {
        self->vtbl = lbl_80454BF0;
        self->unk48 = 0;
        if (self->unk4C != 0) {
            void* p = self->unk4C;
            if (p != 0) {
                __dl__FPv(p);
            }
            self->unk4C = 0;
        }
        if (self->unk54 != 0) {
            __dl__FPv(self->unk54);
            self->unk54 = 0;
        }
        if (self->unk58 != 0) {
            gfCameraController* p = self->unk58;
            if (p != 0) {
                p->slot2(1);
            }
            self->unk58 = 0;
        }
        if (self->unk50 != 0) {
            __dl__FPv(self->unk50);
            self->unk50 = 0;
        }
        if (self->unk60 != 0) {
            __dl__FPv(self->unk60);
            self->unk60 = 0;
        }
        if (self->unk64 != 0) {
            __dl__FPv(self->unk64);
            self->unk64 = 0;
        }
        if (self->unk68 != 0) {
            gfCameraController* p = self->unk68;
            if (p != 0) {
                p->slot2(1);
            }
            self->unk68 = 0;
        }
        if (self->unk6C != 0) {
            __dl__FPv(self->unk6C);
            self->unk6C = 0;
        }
        if (self->unk70 != 0) {
            __dl__FPv(self->unk70);
            self->unk70 = 0;
        }
        if (self->unk74 != 0) {
            gfCameraController* p = self->unk74;
            if (p != 0) {
                p->slot2(1);
            }
            self->unk74 = 0;
        }
        if (self->unk78 != 0) {
            fn_800A9E0C(self->unk78, 1);
            self->unk78 = 0;
        }
        if (self->unk5C != 0) {
            __dt__22cmMeleeFixedControllerFv(self->unk5C, 1);
            self->unk5C = 0;
        }
        if (self->unk80 != 0) {
            fn_800AAA98(self->unk80, 1);
            self->unk80 = 0;
        }
        fn_8015C304(lbl_8049DEDC);
        lbl_805A0278 = 0;
        __dt__6gfTaskFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
