#pragma force_active on

struct StopModule {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual int getState();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void setFrames(int, bool);
};

struct Vec2 {
    float x, y;
};

struct ShakeModule {
    virtual void slot08();
    virtual void slot0C();
    virtual void shake(int, int, int, const Vec2&);
};

struct Modules {
    char pad[0x44];
    StopModule* stop;
    void* pad48;
    ShakeModule* shake;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

struct Owner {
    char pad[0x60];
    Accesser* accesser;
};

struct Argument {
    char pad[0xC];
    float value;
};

extern "C" {
extern const float lbl_27_rodata_74BC;
extern const float lbl_27_rodata_74B0;

int fn_27_63914(void*, void*, float, int);
int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    Accesser*, unsigned long, unsigned long);

void fn_27_318010(Owner* self, Argument* arg, int kind, Accesser* accesser) {
    StopModule* stop = accesser->modules->stop;
    if (arg->value > lbl_27_rodata_74BC && stop->getState() == 0) {
        int frames = fn_27_63914(
            accesser, arg, lbl_27_rodata_74B0, kind) >> 1;
        if (frames > 0) {
            accesser->modules->stop->setFrames(frames, true);
            Vec2 vec = { lbl_27_rodata_74BC, lbl_27_rodata_74B0 };
            Accesser* ownAccesser = self->accesser;
            ShakeModule* shake = ownAccesser->modules->shake;
            shake->shake(
                0,
                getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
                    ownAccesser, 0x5DC3, 0),
                0,
                vec);
        }
    }
}
}
