#pragma force_active on
extern "C" {
extern const float lbl_121_rodata_C;
extern const double lbl_121_rodata_10;
void fn_27_1963F0(void*, float, float);
bool fn_27_135A70(void*);
}

class Work {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual float get(int);
};

class Motion {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void set(float, int);
};

struct Modules {
    char pad[0x44];
    Motion* motion;
    char pad2[0x1c];
    Work* work;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

struct Object {
    char pad[0x60];
    Access* access;
};

extern "C" bool fn_121_A2A4(Object* self) {
    float value = self->access->modules->work->get(0x11000016);
    if (value > lbl_121_rodata_C) {
        Motion* motion = self->access->modules->motion;
        motion->set((float)(int)value, 0);

        Access* access = self->access;
        fn_27_1963F0(access, value,
                     access->modules->work->get(0x11000017));
        return false;
    }
    return fn_27_135A70(self);
}
