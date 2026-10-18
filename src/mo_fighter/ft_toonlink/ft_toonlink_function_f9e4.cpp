#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

extern "C" const float lbl_121_rodata_60;

extern "C" void fn_121_F9E4(void*, void* accesser) {
    unsigned char* modules = *reinterpret_cast<unsigned char**>(
        static_cast<unsigned char*>(accesser) + 0xd8);
    soWorkManageModule* work =
        *reinterpret_cast<soWorkManageModule**>(modules + 0x64);

    work->setInt(0, 0x20000001);
    work->setInt(0, 0x20000002);
    work->offFlag(0x22000017);
    work->offFlag(0x22000018);
    work->setInt(-1, 0x20000003);
    work->setFloat(lbl_121_rodata_60, 0x21000004);
    work->offFlag(0x22000019);
}
