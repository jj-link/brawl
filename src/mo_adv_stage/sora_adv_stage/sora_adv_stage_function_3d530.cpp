#pragma force_active on
#include <gr/gr_gimmick.h>

struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
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
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60(unsigned long);
    char pad40[0x110];
    int state;
    char pad154[0x5c];
    float timer;
};

extern "C" {
extern const float lbl_40_rodata_848[];

void fn_40_3D530(Object_vptr_3c* self) {
    const float* data = lbl_40_rodata_848;
    Vec3f pos = reinterpret_cast<grGimmick*>(self)->getPos();
    self->timer += data[0x94 / 4];
    if (self->timer >= data[0x98 / 4]) {
        self->state = 5;
        self->timer = data[0];
        self->slot60(0);
    }
    pos.m_y -= data[0x94 / 4];
    reinterpret_cast<grGimmick*>(self)->setPos(&pos);
}
}
