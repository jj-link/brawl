#include <so/stageobject.h>
#include <so/so_module_accesser.h>
#pragma force_active on

class Class_8CD0 {
public:
    virtual void fn_114_8BC0();
    virtual void fn_114_150C0();
    virtual void fn_114_159B0();
    virtual void fn_114_159AC();
    virtual void fn_114_159A8();
    virtual void fn_114_159A4();
    virtual void fn_114_1599C();
    virtual void fn_114_159E4();
    virtual void fn_114_159DC();
    virtual void fn_114_159D4();
    virtual void fn_114_159CC();
    virtual void fn_114_159C4();
    virtual float fn_114_1595C(unsigned long);
    virtual void fn_114_15990(float, unsigned long);
    virtual void fn_114_15984();
    virtual void fn_114_1597C();
    virtual void fn_114_15970();
};
class Class_9054 {
public:
    virtual void fn_114_8BC0();
    virtual void fn_114_15064();
    virtual void fn_114_15CB4();
    virtual void fn_114_15CAC(int, soModuleAccesser*);
    virtual void fn_114_15CA4();
    virtual void fn_114_15C9C();
    virtual void fn_114_15C94();
    virtual void fn_114_15C8C();
    virtual void fn_114_15C84();
    virtual void fn_114_15C7C();
    virtual void fn_114_15C74();
    virtual void fn_114_15C6C();
    virtual void fn_114_15C64();
    virtual void fn_114_15C5C();
    virtual void fn_114_15C0C();
    virtual void fn_114_15C54();
    virtual int fn_114_15C44();
};

extern "C" const float lbl_114_rodata_8;

extern "C" int fn_114_B700(StageObject* object)
{
    soWorkManageModule& work = object->m_moduleAccesser->getWorkManageModule();
    float facing;
    float recovery = work.getFloat(0x11000013);
    facing = work.getFloat(0x11000014);
    work.setFloat(lbl_114_rodata_8, 0x11000013);
    work.setFloat(lbl_114_rodata_8, 0x11000014);
    if (recovery > lbl_114_rodata_8) {
        soPostureModule& posture = object->m_moduleAccesser->getPostureModule();
        soStatusModule& status = object->m_moduleAccesser->getStatusModule();
        soMotionModule& motion = object->m_moduleAccesser->getMotionModule();
        soDamageModule& damage = object->m_moduleAccesser->getDamageModule();
        float remaining = damage.getDamage(0) - recovery;
        if (remaining < lbl_114_rodata_8) {
            recovery += remaining;
        }
        damage.addDamage(-recovery, 0);
        posture.setLr(facing);
        const unsigned char* data = *reinterpret_cast<const unsigned char**>(
            reinterpret_cast<unsigned char*>(object) + 0x48CC0);
        const float* parameters = *reinterpret_cast<const float* const*>(data + 0x88);
        if (status.getStatusKind() != 0x120 || !(motion.getFrame() <= parameters[2])) {
            status.changeStatusRequest(0x120, object->m_moduleAccesser);
        }
    }
    return 0;
}
