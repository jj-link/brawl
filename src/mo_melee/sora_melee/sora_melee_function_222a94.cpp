#include <st/st_shadow.h>
#pragma force_active on

extern "C" void fn_27_222A94(void* p) {
    stShadow** shadow = (stShadow**)((char*)p + 0xC4);
    if (*shadow != 0) {
        (*shadow)->clearShadowObject();
    }
}
