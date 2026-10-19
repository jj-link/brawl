#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_199DDC(void* object, int a, int b);
void fn_27_6A244(void* a, void* b, void* c);

void* fn_103_7F54(void* object, void* modules) {
    fn_27_199DDC(object, 6, 0);
    fn_27_6A244(static_cast<char*>(object) + 0x144, modules, object);
    return object;
}
}
