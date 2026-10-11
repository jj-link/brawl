#include <sr/sr_common.h>
#include <types.h>

extern "C" {
void* fn_103_3B44(void* member, s16 deleteFlag);

void* fn_103_533C(void* object, s32 deleteFlag) {
    if (object != nullptr && static_cast<s16>(deleteFlag) > 0) {
        ::operator delete(object);
    }
    return object;
}

void* fn_103_537C(void* object, s32 deleteFlag) {
    if (object != nullptr && static_cast<s16>(deleteFlag) > 0) {
        ::operator delete(object);
    }
    return object;
}

void* fn_103_53BC(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_3B44(static_cast<u8*>(object) + 0x1C0, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
