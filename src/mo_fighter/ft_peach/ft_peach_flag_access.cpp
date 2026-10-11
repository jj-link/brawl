#include <types.h>

struct PeachFlagOwner {
    void* vtable;
    u8 flag;
};

extern "C" u8 fn_103_72A4(const PeachFlagOwner* owner) {
    return owner->flag;
}
