#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#include <so/work/so_work_manage_module_impl.h>

struct NessTransitionParameterProcess { void* vtable; };
struct NessTransitionParameterRegistration { void* next; void* object; void* destructor; };
extern "C" {
extern NessTransitionParameterProcess lbl_101_bss_22C;
extern NessTransitionParameterRegistration lbl_101_bss_220;
extern unsigned char lbl_101_data_8BF4[];
extern const float lbl_101_rodata_88;
NessTransitionParameterProcess* fn_101_12B8C(NessTransitionParameterProcess*);
void* fn_101_12B04(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_101_12B44() {
    fn_101_12B8C(&lbl_101_bss_22C);
    __register_global_object(&lbl_101_bss_22C,
        reinterpret_cast<void*>(fn_101_12B04), &lbl_101_bss_220);
}

#pragma dont_inline on
extern "C" NessTransitionParameterProcess* fn_101_12B8C(NessTransitionParameterProcess* process) {
    process->vtable = lbl_101_data_8BF4;
    return process;
}
#pragma dont_inline reset

extern "C" void fn_101_12B9C(void*, soModuleAccesser* accesser, int eventKind) {
    if (eventKind == 16) {
        ftData* data = g_ftCommonDataAccesser.getData(static_cast<ftKind>(10));
        // This common parameter block is not yet described by ftData.
        unsigned char* parameters = *reinterpret_cast<unsigned char**>(
            reinterpret_cast<unsigned char*>(data) + 0x84);
        float value = *reinterpret_cast<float*>(parameters + 0x2C);
        if (value > lbl_101_rodata_88) {
            accesser->getWorkManageModule().setFloat(value, 0x11000000);
        }
    }
}

void operator delete(void*);
extern "C" void* fn_101_12C10(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}

__declspec(section ".ctors") extern void (*const nessTransitionParameterInitializer)() = fn_101_12B44;
