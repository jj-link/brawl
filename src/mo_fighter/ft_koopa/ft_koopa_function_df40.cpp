#pragma force_active on

extern "C" void fn_102_D694(void* self);

class SitModule {
public:
    virtual void s8();
    virtual void s12();
    virtual void s16();
    virtual int getKind();          // 0x14
    virtual void s24();
    virtual void s28();
    virtual void setKind(int, int); // 0x20
};

class WorkObj {
public:
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual int isFlag(int);        // 0x4c
};

struct GroundData {
    int a;
    int b;
};

class GroundModule : public GroundData {
public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual void g13();
    virtual void g14();
    virtual void g15();
    virtual void g16();
    virtual void g17();
    virtual void g18();
    virtual void fn54(int, int);    // 0x54
};

class Module70 {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m5(int, void*);    // 0x14
};

struct Mods {
    void* pad00[4];                 // 0x00
    GroundModule* ground;           // 0x10
    SitModule* sit;                 // 0x14
    void* pad18[19];                // 0x18
    WorkObj* work;                  // 0x64
    void* pad68[2];                 // 0x68
    Module70* module70;             // 0x70
};

struct Holder {
    void* pad[0xD8 / 4];
    Mods* mods;                     // 0xD8
};

extern "C" void fn_102_DF40(void*, Holder* self) {
    int kind = self->mods->sit->getKind();
    WorkObj* work = self->mods->work;
    if (kind != 2) {
        if (work->isFlag(0x22000010) != 0) {
            fn_102_D694(self);
            self->mods->module70->m5(0x11b, self);
            return;
        }
        self->mods->sit->setKind(2, 0);
        self->mods->ground->fn54(5, 0);
    }
}
