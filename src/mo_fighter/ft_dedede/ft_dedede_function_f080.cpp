#include <so/so_module_accesser.h>

extern "C" {
void fn_27_193C20(soModuleAccesser*, int);
void fn_117_F2D8(void*, soModuleAccesser*);
extern const float lbl_117_rodata_40, lbl_117_rodata_44;
}

struct DededeKineticEnable { unsigned char enabled : 1; };

extern "C" void fn_117_F080(void* self, soModuleAccesser* accesser) {
    soMotionChangeParam motion;
    motion.m_kind = 0x1F9;
    motion.m_frame = lbl_117_rodata_40;
    motion.m_rate = lbl_117_rodata_44;
    motion._12 = 0;
    motion._13 = 0;
    motion._14 = 0;
    motion._15 = 0;
    accesser->getMotionModule().changeMotionRequest(&motion);
    accesser->getPostureModule().getLr();
    fn_27_193C20(accesser, 1);
    fn_117_F2D8(self, accesser);
    soKineticEnergy* energy = accesser->getKineticModule().getEnergy(0);
    // soEnable's packed enable flag occupies the high bit of byte five.
    reinterpret_cast<DededeKineticEnable*>(reinterpret_cast<unsigned char*>(energy) + 5)->enabled = 0;
}
