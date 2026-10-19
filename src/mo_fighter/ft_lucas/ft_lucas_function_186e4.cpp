#include <types.h>
#pragma force_active on

extern "C" void* fn_114_57E0(void* object, short deleting);
extern "C" void fn_114_18750(void* object, short deleting);

struct LucasDeletable {
    u8 pad0[4];
    u8 sub[0x3f10 - 4];
};

extern "C" void* fn_114_186E4(void* object, short deleting) {
    if (object != 0) {
        fn_114_57E0(static_cast<char*>(object) + 0x3f10, -1);
        fn_114_18750(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
