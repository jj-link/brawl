#include <so/so_module_accesser.h>
#include <ft/ft_common_data_accesser.h>

struct PikachuRangeOwner {
    char reserved[0x60];
    soModuleAccesser* accesser;
};
struct PikachuRangeCommonData {
    char reserved[0x34];
    const float* horizontalRange;
};

extern "C" {
extern const float lbl_98_rodata_D8;
PikachuRangeCommonData* fn_27_148148(ftCommonDataAccesser*);
void* fn_98_17D34(void* owner);
bool fn_98_145A0(void* storage, const Vec3f* point);

bool fn_98_17DEC(PikachuRangeOwner* owner, const Vec3f* point) {
    soWorkManageModule* work = &owner->accesser->getWorkManageModule();
    Vec3f position = owner->accesser->getPostureModule().getPos();
    const float* horizontalRange = fn_27_148148(&g_ftCommonDataAccesser)->horizontalRange;
    const float distance = lbl_98_rodata_D8 * *horizontalRange;
    const float lower = position.m_x - distance;
    const float upper = position.m_x + distance;
    if (work->isFlag(0x12000005)) {
        return false;
    }
    if (lower <= point->m_x && point->m_x <= upper) {
        void* storage = fn_98_17D34(owner);
        if (storage && fn_98_145A0(storage, point)) {
            work->incInt(0x10000008);
            return true;
        }
    }
    return false;
}
}
