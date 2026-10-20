#include <so/so_module_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

extern "C" int randi__Fl(long);

extern "C" void fn_96_B3F8(void* owner) {
    soModuleAccesser* accesser = *(soModuleAccesser**)((char*)owner + 0x60);
    void* module = *(void**)((char*)accesser + 0xD8);
    soWorkManageModule* work = *(soWorkManageModule**)((char*)module + 0x64);
    int value = work->getInt(0x10000047);
    int index = (value + randi__Fl(3) + 1) % 5;
    work->setInt(index, 0x10000047);
}
