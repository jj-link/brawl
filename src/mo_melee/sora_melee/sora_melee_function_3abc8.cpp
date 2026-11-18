#pragma force_active on

extern const float lbl_27_rodata_498;

class Object_vptr_0 {
public:
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
    virtual float slot13();
};

struct Modules {
    char padding[0xC4];
    Object_vptr_0* module;
};

struct Owner {
    char padding[0xD8];
    Modules* modules;
};

struct Object {
    char padding[0x28];
    Owner* owner;
    char padding2[0x30];
    float factor;
};

extern "C" float fn_27_3ABC8(const Object* self) {
    float scale = lbl_27_rodata_498;
    Object_vptr_0* module = self->owner->modules->module;
    scale *= module->slot13();
    return scale * self->factor;
}
