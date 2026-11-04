#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

namespace {
struct SummedSpeed { float x, y; };
class KineticSpeedView {
public:
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void u4();
    virtual void u5();
    virtual void u6();
    virtual void u7();
    virtual void u8();
    virtual void u9();
    virtual void u10();
    virtual void u11();
    virtual void u12();
    virtual SummedSpeed getSumSpeed(const unsigned short&);
};
}

extern "C" {
double atan2(double, double);
void fn_8003DBA8(Vec2f* vector);
extern const float lbl_27_rodata_7ED8;
}

static inline float atan2Float(float y, float x) {
    return atan2(y, x);
}

extern "C" void fn_27_3A57B4(void*, soModuleAccesser* accesser) {
    Vec3f rotation = accesser->m_enumerationStart->m_postureModule->getRot(0);
    unsigned short attributes = 1;
    SummedSpeed summed = reinterpret_cast<KineticSpeedView*>(&accesser->getKineticModule())->getSumSpeed(attributes);
    Vec2f speed;
    __memcpy(&speed, &summed, sizeof(speed));
    fn_8003DBA8(&speed);
    rotation.m_x = lbl_27_rodata_7ED8 * -atan2Float(speed.m_y, speed.m_x * accesser->m_enumerationStart->m_postureModule->getLr());
    accesser->m_enumerationStart->m_postureModule->setRot(&rotation, 0);
}