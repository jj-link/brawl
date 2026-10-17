#include <so/work/so_work_manage_module_impl.h>

extern "C" {
void fn_27_130808(void* object, int param);
extern const float lbl_101_rodata_8;
}

// ft_ness status-exit reset: forwards the status parameter to the common
// handler, then clears the article-spawn work state (flag 0x1200003D, the
// interval/elapsed floats, and the spawn counter).
extern "C" void fn_101_B9FC(void* object, int param) {
    fn_27_130808(object, param);
    unsigned char* storage = static_cast<unsigned char*>(object);
    unsigned char* accesser = *reinterpret_cast<unsigned char**>(storage + 0x60);
    unsigned char* modules = *reinterpret_cast<unsigned char**>(accesser + 0xd8);
    soWorkManageModule* work = *reinterpret_cast<soWorkManageModule**>(modules + 0x64);
    work->offFlag(0x1200003d);
    work->setFloat(lbl_101_rodata_8, 0x11000015);
    work->setFloat(lbl_101_rodata_8, 0x11000016);
    work->setInt(0, 0x10000040);
}
