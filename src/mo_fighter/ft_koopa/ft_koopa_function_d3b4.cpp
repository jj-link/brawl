#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_102_D3B4(void* unused, soModuleAccesser* accesser, int kind) {
    soWorkManageModule* work = &accesser->getWorkManageModule();
    if (kind == 0x117) {
        char* c = *(char**)((char*)g_ftCommonDataAccesser.getData((ftKind)0xB) + 0x80);
        accesser->getWorkManageModule().setFloat((float)*(int*)(c + 0x2c), 0x11000000);
        float frame = accesser->getMotionModule().getFrame();
        if (frame > (float)*(int*)(c + 0x20)) {
            work->onFlag(0x22000016);
            if (frame - (float)*(int*)(c + 0x28) < (float)*(int*)(c + 0x24)) {
                work->onFlag(0x22000013);
            }
        }
    } else {
        ftData* data = g_ftCommonDataAccesser.getData((ftKind)0xB);
        char* c = *(char**)((char*)data + 0x80);
        work->setFloat((float)*(int*)(c + 0x2c), 0x11000000);
    }
}
