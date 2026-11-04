#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern const float lbl_27_rodata_7F80;

struct ReflectViewBase {
    char pad[0x8];
};

class ReflectView : public ReflectViewBase {
public:
    virtual void fn_27_7B274();  // offset 0x8
    virtual void fn_27_7AC18();  // offset 0xc
    virtual void fn_27_7AC28();  // offset 0x10
    virtual void fn_27_7AB50();  // offset 0x14
    virtual void fn_27_7B2EC();  // offset 0x18
    virtual void fn_27_7AB10();  // offset 0x1c
    virtual void fn_27_7AD2C();  // offset 0x20
    virtual void fn_27_7AEDC();  // offset 0x24
    virtual int fn_27_7B22C();   // offset 0x28
    virtual int fn_27_7AC38();   // offset 0x2c
    virtual void fn_27_7ADE8();  // offset 0x30
    virtual void fn_27_7AF98();  // offset 0x34
    virtual void fn_27_7B0B0();  // offset 0x38
    virtual void fn_27_7ABD8();  // offset 0x3c
    virtual float fn_27_7ABCC(); // offset 0x40
};

class TeamView {
public:
    virtual void slot0();  // offset 0x8
    virtual void slot1();  // offset 0xc
    virtual void slot2();  // offset 0x10
    virtual void slot3(int value, int flag, soModuleAccesser* accesser);  // offset 0x14
    virtual void slot4();  // offset 0x18
    virtual void slot5();  // offset 0x1c
    virtual void slot6(int value);  // offset 0x20
    virtual void slot7(int value);  // offset 0x24
};

class KineticView {
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

extern "C" int fn_27_3B0A84(StageObject* self) {
    if (self->m_moduleAccesser->getStatusModule().getStatusKind() == 0) {
        if (self->m_moduleAccesser->getWorkManageModule().isFlag(0x22000005)) {
            self->m_moduleAccesser->getWorkManageModule().offFlag(0x22000005);
            self->m_moduleAccesser->getPostureModule().reverseLr();
            self->m_moduleAccesser->getPostureModule().updateRotYLr();
            int v = reinterpret_cast<ReflectView*>(self->m_moduleAccesser->m_enumerationStart->m_reflectModule)->fn_27_7AC38();
            reinterpret_cast<TeamView*>(self->m_moduleAccesser->m_enumerationStart->m_teamModule)->slot3(v, 1, self->m_moduleAccesser);
            reinterpret_cast<TeamView*>(self->m_moduleAccesser->m_enumerationStart->m_teamModule)->slot6(v);
            TeamView* team = reinterpret_cast<TeamView*>(self->m_moduleAccesser->m_enumerationStart->m_teamModule);
            int w = reinterpret_cast<ReflectView*>(self->m_moduleAccesser->m_enumerationStart->m_reflectModule)->fn_27_7B22C();
            team->slot7(w);
            unsigned short speedMask = 1;
            Vec3f speed;
            speed.m_x = -reinterpret_cast<ReflectView*>(self->m_moduleAccesser->m_enumerationStart->m_reflectModule)->fn_27_7ABCC();
            speed.m_y = lbl_27_rodata_7F80;
            speed.m_z = lbl_27_rodata_7F80;
            reinterpret_cast<KineticView*>(self->m_moduleAccesser->m_enumerationStart->m_kineticModule)->mulSpeed(&speed, &speedMask);
        }
        if (self->m_moduleAccesser->getWorkManageModule().isFlag(0x22000004)) {
            self->m_moduleAccesser->getStatusModule().changeStatusRequest(1, self->m_moduleAccesser);
            return 1;
        }
    }
    return 0;
}
