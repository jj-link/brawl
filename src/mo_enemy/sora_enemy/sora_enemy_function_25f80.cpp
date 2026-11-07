#include <em/em_area_module_impl.h>
#pragma force_active on
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char __RTTI__16emAreaModuleImpl[], __RTTI__12soAreaModule[];
unsigned long fn_41_23BD4(soModuleAccesser*, unsigned long);
}
extern "C" void fn_41_25F80(soModuleAccesser* acc, int index) {
    char* area = (char*)__dynamic_cast(*(void**)(*(char**)((char*)acc + 0xd8) + 0x90), 0, __RTTI__16emAreaModuleImpl, __RTTI__12soAreaModule, 1);
    if (index == 8) {
        for (int i = 0; i < 8; i++) {
            if (emAreaModuleImpl::isExistTarget(acc, i)) {
                ((unsigned long*)(area + 0x568))[i] = fn_41_23BD4(acc, i);
            }
        }
    } else {
        if (index <= -1 || index >= 8) return;
        ((unsigned long*)(area + 0x568))[index] = fn_41_23BD4(acc, index);
    }
}
