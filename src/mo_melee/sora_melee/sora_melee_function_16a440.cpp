#include <so/so_value_accesser.h>
#include <so/posture/so_posture_module_simple.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec3f slot4();
    virtual void slot5(const Vec3f*);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual unsigned int slot11();
    virtual float slot12(int);
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual float slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual unsigned char slot23();
};
struct Mods {
    char p0[0xC];
    soPostureModule* posture;
    char p1[0x34];
    Object_vptr_0* o44;
    char p2[0x14];
    Object_vptr_0* o5c;
    char p3[4];
    Object_vptr_0* o64;
};
struct Acc {
    char pad[0xD8];
    Mods* m;
};
#define GC(a, i) soValueAccesser::getConstantFloat((soModuleAccesser*)a, i, 0)
extern "C" void fn_27_16A440(void*, Acc* a) {
    if (a->m->o44->slot11() == 1) {
        Object_vptr_0* o = a->m->o5c;
        float t = GC(a, 0xC65);
        if (o->slot23() < t) {
            float v = a->m->o5c->slot16();
            float av = static_cast<float>(static_cast<double>(nw4r::math::FAbs(v)));
            if (av >= GC(a, 0xC65)) {
                Vec3f p = a->m->posture->getPos();
                Object_vptr_0* o2 = a->m->o64;
                p.m_x += o2->slot12(0x21000006) * ((v * GC(a, 0xC66)) * (GC(a, 0xC68)));
                a->m->posture->setPos(&p);
                a->m->o5c->slot14();
            }
        }
    }
}
