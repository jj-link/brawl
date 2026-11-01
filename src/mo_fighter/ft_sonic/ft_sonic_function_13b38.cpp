#include <mt/mt_vector.h>
#include <so/event/so_event_presenter.h>

class soGimmickEventObserver;
template <> class soEventObserver<soGimmickEventObserver> : public soEventObserver<void> {
public:
    s32 getObserverId() const;
};

#include <so/so_value_accesser.h>
#pragma force_active on

class Class_1410 {
public:
    virtual void fn_123_6E08();
    virtual void fn_123_1978();
    virtual void fn_123_A2F4();
    virtual void fn_123_A2EC();
    virtual void fn_123_A2E4();
    virtual void fn_123_A2DC(int, int, int, int);
};

class Class_1BF8 {
public:
    virtual void fn_123_A590();
    virtual void fn_123_A64C();
    virtual void fn_123_A7CC();
    virtual void fn_123_A598();
    virtual Vec3f fn_123_B590();
    virtual void fn_123_2208();
};

class Class_64C0 {
public:
    virtual void fn_123_FC80();
    virtual void fn_123_F0B0();
    virtual void fn_123_FC7C();
    virtual void fn_123_F1D0();
    virtual void fn_123_FC78();
    virtual void fn_123_FC74();
};

class Class_66D0 {
public:
    virtual void fn_123_10598();
    virtual void fn_123_10020();
    virtual void fn_123_1040C();
    virtual void fn_123_100E4();
    virtual void fn_123_FC78();
    virtual void fn_123_FC74();
};

class Class_6750 {
public:
    virtual void fn_123_107F0();
    virtual void fn_123_10630();
    virtual void fn_123_FC7C();
    virtual void fn_123_FCC4();
    virtual void fn_123_FC78();
    virtual void fn_123_FC74();
};

class Class_67C8 {
public:
    virtual void fn_123_1099C();
    virtual void fn_123_10888();
    virtual void fn_123_FC7C();
    virtual void fn_123_FCC4();
    virtual void fn_123_FC78();
    virtual void fn_123_FC74();
};

class Class_6ED4 {
public:
    virtual void fn_123_6E08();
    virtual void fn_123_12DA8();
    virtual void fn_123_13F2C();
    virtual void fn_123_13F28();
    virtual void fn_123_13F24();
    virtual void fn_123_13F20();
};

class Class_7058 {
public:
    virtual void fn_123_6E08();
    virtual void fn_123_12C78();
    virtual void fn_123_14060();
    virtual void fn_123_14058();
    virtual void fn_123_14050();
    virtual void fn_123_1404C();
};

class Class_70AC {
public:
    virtual void fn_123_6E08();
    virtual void fn_123_12D4C();
    virtual void fn_123_14120();
    virtual void fn_123_14118();
    virtual void fn_123_14110();
    virtual void fn_123_14108();
};

struct Class_6558_base { char pad[8]; };
class Class_6558 : public Class_6558_base {
public:
    virtual void fn_123_FF80();
    virtual void fn_123_FDA8();
    virtual void fn_123_FDB8();
    virtual void fn_123_FF20();
    virtual void fn_123_FD74();
    virtual void fn_123_FCC8();
    virtual void fn_123_FDC8();
    virtual short fn_123_FE58();
};

struct Event {
    char data[16];
};

extern "C" {
Vec2f* fn_123_13A10(Vec2f*, float, float);
Vec3f* fn_123_13D2C(Vec3f*, const Vec2f*, float);
Vec3f* fn_123_13A1C(Vec3f*, const Vec3f*);
Event fn_123_132E0(short, int);
void fn_27_AA42C(const void*, void*, soModuleAccesser*, int);
extern const float lbl_123_rodata_70;
}

struct Offset2 : Vec2f {
    Offset2(float x, float y) { fn_123_13A10(this, x, y); }
};

struct Position2 : Vec2f {
    Position2(const Vec3f& v) { m_x = v.m_x; m_y = v.m_y; }
};

struct Fighter {
    char pad[0x60];
    soModuleAccesser* access;
};

struct SonicEventInput {
    int kind;
    int unknown;
    Vec3f position;
};

struct Param {
    int kind;
    int unknown;
    Vec3f position;
    float radius;
    float unknown2;
};

static inline void onKind17(Fighter* self, SonicEventInput* input) {
    Vec2f sum;
    Vec3f v2;
    Vec3f v1;
    soModuleAccesser* access = self->access;
    float y = soValueAccesser::getConstantFloat(access, 0xfa2, 0);
    float x = soValueAccesser::getConstantFloat(access, 0xfa1, 0);
    Offset2 off(x, y);
    Vec3f ret = reinterpret_cast<Class_1BF8&>(
            self->access->getPostureModule()).fn_123_B590();
    Position2 p(ret);
    sum.m_x = p.m_x + off.m_x;
    sum.m_y = p.m_y + off.m_y;
    Vec2f tmp;
    Vec2f::copy(tmp, sum);
    Vec2f position;
    Vec2f::copy(position, tmp);
    fn_123_13A1C(&input->position, fn_123_13D2C(&v1, &position, lbl_123_rodata_70));

    Param param;
    param.kind = 0x18;
    param.unknown = 0;
    fn_123_13A1C(&param.position, fn_123_13D2C(&v2, &position, lbl_123_rodata_70));
    param.radius = soValueAccesser::getConstantFloat(self->access, 0xfa0, 0);
    param.unknown2 = lbl_123_rodata_70;

    soEventManageModule* manager = self->access->m_enumerationStart->m_eventManageModule;
    const Event& event = fn_123_132E0(static_cast<soEventManager&>(*manager).getManageId(),
        (short)reinterpret_cast<soEventObserver<soGimmickEventObserver>*>(
            reinterpret_cast<char*>(self) + 0x2158)->getObserverId());
    fn_27_AA42C(&event, &param, self->access, -1);

    Class_1410* sound = reinterpret_cast<Class_1410*>(
        self->access->m_enumerationStart->m_soundModule);
    sound->fn_123_A2DC(0x1989, 0, 1, 0);
}

extern "C" void fn_123_13B38(Fighter* self, SonicEventInput* input) {
    if (input->kind == 0x33)
        return;
    if (input->kind <= 0x16 || input->kind >= 0x1a)
        return;
    switch (input->kind) {
    case 0x17:
        onKind17(self, input);
        break;
    }
}
