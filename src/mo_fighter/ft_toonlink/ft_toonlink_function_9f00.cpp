#pragma force_active on

typedef unsigned int u32;

struct StatusModule {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual int getStatusKind();
};

struct WorkModule {
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual int getInt(u32);
    virtual void w5();
    virtual void w6();
    virtual void w7(u32);
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void setFloat(float, u32);
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void onFlag(u32);
    virtual void offFlag(u32);
};

struct MotionModule {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void setF(float);
    virtual void m11();
    virtual float getF();
    virtual void m13();
    virtual float getF2(int);
};

struct KineticModule {
    virtual void k0();
    virtual void k1();
    virtual void k2();
    virtual void k3();
    virtual void k4();
    virtual void k5();
    virtual void* getEnergy(int);
};

struct Energy {
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
    virtual void e4();
    virtual void e5();
    virtual void setEnabled();
};

struct Enumeration {
    unsigned char pad0[0x08];
    MotionModule* motion;
    unsigned char pad1[0x58];
    WorkModule* work;
    unsigned char pad2[0x08];
    StatusModule* status;
    unsigned char pad3[0x08];
    KineticModule* kinetic;
};

struct Accesser {
    unsigned char pad[0xD8];
    Enumeration* enumeration;
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_121_10AFC(Accesser*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, u32, u32);
extern const unsigned char lbl_121_data_3110[];
extern const unsigned char lbl_121_data_31F4[];
}

extern "C" void fn_121_9F00(void*, void*, Accesser* accesser) {
    StatusModule* status = accesser->enumeration->status;

    switch (status->getStatusKind()) {
    case 0x33: {
        switch (accesser->enumeration->work->getInt(0x20000000u)) {
        case 0x66: {
            WorkModule* work = accesser->enumeration->work;
            MotionModule* motion = accesser->enumeration->motion;
            work->onFlag(0x1200003eu);
            work->offFlag(0x1200003fu);
            work->w7(0x10000040u);

            void* energy = accesser->enumeration->kinetic->getEnergy(1);
            Energy* enabledEnergy = static_cast<Energy*>(__dynamic_cast(
                energy, 0, lbl_121_data_3110, lbl_121_data_31F4, 1));
            enabledEnergy->setEnabled();

            float frame = motion->getF2(0x66);
            float constant =
                getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                    accesser, 0xfb0, 0);
            float limit = frame - constant;

            if (motion->getF() > limit) {
                motion->setF(limit);
            }

            work->setFloat(constant, 0x11000015u);
            break;
        }
        }
        break;
    }

    case 0x11b:
        fn_121_10AFC(accesser);
        break;
    }
}
