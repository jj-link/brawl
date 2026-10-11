#include <so/stageobject.h>

class MarioArticleReflectView : private soNull, public soNullable {
public:
    virtual void slot00(); virtual void slot01(); virtual void slot02();
    virtual void slot03(); virtual void slot04(); virtual void slot05();
    virtual void slot06(); virtual void slot07(); virtual void slot08();
    virtual void slot09(); virtual void slot10();
    virtual float getFacing();
};
class MarioArticleKineticMultiplierView {
public:
    virtual void slot00(); virtual void slot01(); virtual void slot02();
    virtual void slot03(); virtual void slot04(); virtual void slot05();
    virtual void slot06(); virtual void slot07(); virtual void slot08();
    virtual void slot09(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14();
    virtual void slot15(); virtual void slot16();
    virtual void mulSpeed(Vec3f*, const unsigned short*);
    virtual void mulAccel(Vec3f*, const unsigned short*);
};
extern "C" {
extern const float lbl_91_rodata_5C;
extern const float lbl_91_rodata_60;
int fn_91_16A20(StageObject* object) {
    Vec3f speed;
    speed.m_x = -static_cast<MarioArticleReflectView*>(object->m_moduleAccesser->m_enumerationStart->m_reflectModule)->getFacing();
    speed.m_y = lbl_91_rodata_60;
    speed.m_z = lbl_91_rodata_5C;
    Vec3f acceleration;
    acceleration.m_x = -static_cast<MarioArticleReflectView*>(object->m_moduleAccesser->m_enumerationStart->m_reflectModule)->getFacing();
    acceleration.m_y = lbl_91_rodata_5C;
    acceleration.m_z = lbl_91_rodata_5C;
    unsigned short speedMask = 1;
    reinterpret_cast<MarioArticleKineticMultiplierView*>(object->m_moduleAccesser->m_enumerationStart->m_kineticModule)->mulSpeed(&speed, &speedMask);
    unsigned short accelerationMask = 1;
    reinterpret_cast<MarioArticleKineticMultiplierView*>(object->m_moduleAccesser->m_enumerationStart->m_kineticModule)->mulAccel(&acceleration, &accelerationMask);
    return 0;
}
}
