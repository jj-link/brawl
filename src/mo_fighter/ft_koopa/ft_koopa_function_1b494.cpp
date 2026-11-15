#pragma opt_propagation off
#include <so/stageobject.h>
#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#include <math.h>
#pragma force_active on

struct KoopaDescriptor {
    unsigned int taskId;
    int identifier0, identifier1, identifier2;
    int ownerId, teamId;
    int field18, field1C;
    Vec3f position;
    float facing;
    int parameter, field34, situation, status, field40, motion, field48;
    u8 active : 1;
    u8 field4C1 : 3;
    u8 field4C4 : 1;
    u8 field4C5 : 3;
    u8 field4D0 : 2;
    u8 reserved : 6;

    KoopaDescriptor(unsigned int task, int value, const Vec3f& pos, float lr)
        : taskId(task), identifier0(0xffff), identifier1(0xffff), identifier2(0xffff),
          ownerId(-1), teamId(-1), field18(0), field1C(0), position(pos), facing(lr),
          parameter(value), field34(0), situation(2), status(0x80), field40(0),
          motion(0x35f), field48(0), active(1), field4C1(0), field4C4(1),
          field4C5(0), field4D0(0) {}
};

struct KoopaParams {
    float speed;
    int a;
    int b;
    float minValue;
    float maxValue;
};

struct KoopaObject : StageObject {
    unsigned char body[0x1f18];
    KoopaParams* parameters;
};

#define V8(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();

class GroundSlot : public soNull, public soNullable {
public:
    virtual ~GroundSlot();
    V8(a) V8(b) V8(c) V8(d) V8(e) V8(f) V8(g) V8(h) V8(i) V8(j) V8(k) V8(l)
    virtual void m0(); virtual void m1(); virtual void m2sub(); virtual void m3sub();
    virtual void slot105(float, u32);
};

extern "C" {
extern const unsigned char lbl_102_data_83E8[], lbl_102_data_14F4[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1D8370(void*, const KoopaDescriptor*);
Vec2f* fn_102_C5AC(Vec2f*, float, float);
void fn_102_1B788(void*, const Vec2f*);
float randf__Fv();

void fn_102_1B494(KoopaObject* object, unsigned int task, int value,
                  const Vec3f* position, float facing, int arg4, float scale,
                  float speed, float mult, float angle) {
    KoopaDescriptor descriptor(task, value, *position, facing);
    fn_27_1D8370(object, &descriptor);

    KoopaParams* p;
    float sine;
    object->m_moduleAccesser->getWorkManageModule().setInt(arg4, 0x10000007);
    object->m_moduleAccesser->getWorkManageModule().setInt(object->parameters->a, 0x10000005);
    object->m_moduleAccesser->getWorkManageModule().setInt(object->parameters->b, 0x10000006);
    object->m_moduleAccesser->getWorkManageModule().setFloat(speed, 0x11000001);
    reinterpret_cast<GroundSlot*>(&object->m_moduleAccesser->getGroundModule())->slot105(object->parameters->speed, 0);
    object->m_moduleAccesser->getPostureModule().setScale(speed);
    object->m_moduleAccesser->getStatusModule().changeStatusForce(0, object->m_moduleAccesser);
    soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(
        object->m_moduleAccesser->getKineticModule().getEnergy(0), 0,
        lbl_102_data_83E8, lbl_102_data_14F4, static_cast<short>(1)));

    p = object->parameters;
    float r = randf__Fv();
    float range = p->maxValue - p->minValue;
    float length = mult * (scale * (p->minValue + (range * r)));
    sine = static_cast<float>(sin(angle));
    float cosine = static_cast<float>(cos(angle));
    Vec2f velocity;
    fn_102_1B788(energy, fn_102_C5AC(&velocity, facing * (length * cosine), length * sine));
    object->updateNodeSRT();
}
}
