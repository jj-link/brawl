#include <so/stageobject.h>
#include <so/so_module_accesser.h>

extern "C" const float lbl_101_rodata_8;

extern "C" int fn_101_BDA0(StageObject* object)
{
    soWorkManageModule& work = object->m_moduleAccesser->getWorkManageModule();
    float facing;
    float recovery = work.getFloat(0x11000013);
    facing = work.getFloat(0x11000014);
    work.setFloat(lbl_101_rodata_8, 0x11000013);
    work.setFloat(lbl_101_rodata_8, 0x11000014);
    if (recovery > lbl_101_rodata_8) {
        soPostureModule& posture = object->m_moduleAccesser->getPostureModule();
        soStatusModule& status = object->m_moduleAccesser->getStatusModule();
        soMotionModule& motion = object->m_moduleAccesser->getMotionModule();
        soDamageModule& damage = object->m_moduleAccesser->getDamageModule();
        float remaining = damage.getDamage(0) - recovery;
        if (remaining < lbl_101_rodata_8) {
            recovery += remaining;
        }
        damage.addDamage(-recovery, 0);
        posture.setLr(facing);
        // The fighter-specific parameter block is not represented by StageObject.
        const unsigned char* data = *reinterpret_cast<const unsigned char**>(
            reinterpret_cast<unsigned char*>(object) + 0x4AE20);
        const float* parameters = *reinterpret_cast<const float* const*>(data + 0x88);
        if (status.getStatusKind() != 0x11F || !(motion.getFrame() <= parameters[2])) {
            status.changeStatusRequest(0x11F, object->m_moduleAccesser);
        }
    }
    return 0;
}
