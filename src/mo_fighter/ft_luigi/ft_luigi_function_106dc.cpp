#include <types.h>

struct LuigiCollisionObserverFlags {
    u8 storage[0xA4];
    u8 : 1;
    u8 enabled : 1;
    u8 : 6;
};

extern "C" void fn_99_106DC(LuigiCollisionObserverFlags* object, bool enabled) {
    object->enabled = enabled;
}
