#pragma force_active on

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
    virtual void slot12(int arg);
};

struct Owner {
    unsigned char pad[0x124];
    int f124;
    int f128;
    int f12C;
    int f130;
    int f134;
};

extern "C" int fn_801AF838(Owner* self, int arg1) {
    int temp = 0;
    Object_vptr_0* obj;
    switch (arg1) {
    case 0:
        temp = self->f124;
        obj = reinterpret_cast<Object_vptr_0*>(self);
        obj->slot12(temp);
        break;
    case 1:
        temp = self->f128;
        obj = reinterpret_cast<Object_vptr_0*>(self);
        obj->slot12(temp);
        break;
    case 2:
        temp = self->f12C;
        obj = reinterpret_cast<Object_vptr_0*>(self);
        obj->slot12(temp);
        break;
    case 3:
        temp = self->f130;
        obj = reinterpret_cast<Object_vptr_0*>(self);
        obj->slot12(temp);
        break;
    case 4:
        temp = self->f134;
        obj = reinterpret_cast<Object_vptr_0*>(self);
        obj->slot12(temp);
        break;
    case 5:
    case 6:
        break;
    }
    return temp;
}