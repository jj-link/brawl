#include <sr/sr_common.h>
#include <types.h>

extern "C" void* fn_103_52FC(void* object, s32 deleteFlag) {
    if (object != nullptr && static_cast<s16>(deleteFlag) > 0) {
        ::operator delete(object);
    }
    return object;
}
