#pragma force_active on

typedef unsigned int u32;

struct Work {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual u32 isFlag(u32);
    virtual void onFlag(u32);
    virtual void offFlag(u32);
};

struct Modules {
    char padding[0x64];
    Work* work;
};

struct Accesser {
    char padding[0xD8];
    Modules* modules;
};

struct Vec2 {
    float x, y;

    Vec2 operator*(float f) const {
        Vec2 r = {x * f, y * f};
        return r;
    }
};

struct Object {
    virtual void slot0();
    virtual void update(Accesser*);

    unsigned char pad4;
    unsigned char enabled : 1;
    unsigned char rest : 7;
    unsigned char state;
    char pad7[0x19];
    Vec2 speed;

    bool isEnabled() const { return enabled; }
};

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    Accesser*, u32, u32);

extern "C" void fn_27_3BE568(Object* self, void*, Accesser* accesser) {
    if (accesser->modules->work->isFlag(0x22000016) == 1) {
        accesser->modules->work->offFlag(0x22000016);
        float scale =
            getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                accesser, 0xFE4, 0);
        self->speed = self->speed * scale;
    }

    if (self->isEnabled() == true && self->state == 0) {
        self->update(accesser);
    }
}
