#pragma force_active on

struct Work {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual float get(int id);
};

struct Motion {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3();
    virtual void set(float value, int id);
};

struct Modules {
    char pad[0x44];
    Motion* motion;
    char pad48[0x1c];
    Work* work;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

struct Fighter {
    char pad[0x60];
    Access* access;
};

extern "C" void fn_27_1963F0(Access*, float, float);
extern "C" bool fn_27_135A70(void*);
extern const float lbl_93_rodata_C;
extern const double lbl_93_rodata_10;

extern "C" bool fn_93_A2A4(Fighter* self) {
    float value = self->access->modules->work->get(0x11000016);
    if (value > lbl_93_rodata_C) {
        self->access->modules->motion->set((float)(int)value, 0);
        Access* access = self->access;
        fn_27_1963F0(access, value, access->modules->work->get(0x11000017));
        return false;
    }
    return fn_27_135A70(self);
}
