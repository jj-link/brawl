#include <it/item.h>
#include <mt/mt_prng.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

union Vec2 { struct { float x, y; }; unsigned int bits[2]; };
struct Vec3 { float x, y, z; Vec3(float a, float b) : x(a), y(b) {} };
struct Actor;
class Obj {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(unsigned long, unsigned long);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual Vec2 slot13(short*);
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23(Vec3*, Actor*);
};
struct Owner { char pad[0x64]; Obj* obj; };
struct Actor { char pad0[8]; BaseItem* item; char pad1[0xcc]; Owner* owner; };
extern "C" {
extern const float lbl_27_rodata_5EB8[];
void fn_27_288720(BaseItem*, Vec2*, unsigned int);
void fn_27_28880C(BaseItem*, int);
void fn_27_2B543C(Obj* self, Actor* actor, int flag) {
    const float* k = lbl_27_rodata_5EB8;
    BaseItem* item = actor->item;
    short sp8 = -1;
    Vec2 p;
    Vec2 q = self->slot13(&sp8);
    p.bits[0] = q.bits[0];
    p.bits[1] = q.bits[1];
    self->slot9();
    if (flag != 0 && (float)(double)nw4r::math::FAbs(p.x) < k[8]) {
        float t31 = k[6] * randf();
        float t30 = (float)(double)nw4r::math::FAbs(p.y);
        float r = randaf();
        p.x = p.x + r * ((k[9] + t30) * (k[6] + t31));
    }
    float a = -item->getParam((itValueAccesser::ParamFloat)0xd69);
    p.x = p.x * a;
    float b = item->getParam((itValueAccesser::ParamFloat)0xd6a);
    float c = item->getParam((itValueAccesser::ParamFloat)0xd69);
    p.y *= c;
    p.y += b;
    fn_27_288720(item, &p, 0x10);
    Vec3 v(p.x, p.y);
    v.z = k[1];
    self->slot23(&v, actor);
    actor->owner->obj->slot5(0x10, 0x10000004);
    fn_27_28880C(item, 3);
}
}