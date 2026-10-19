#include <types.h>
#pragma force_active on

extern "C" void fn_27_199F1C(void* object, int a, int b);
extern "C" void fn_27_6A244(void* a, void* b, void* c);

extern "C" void* fn_114_98A8(void* object, void* arg) {
    fn_27_199F1C(object, 7, 0);
    fn_27_6A244(static_cast<char*>(object) + 0x178, arg, object);
    return object;
}
