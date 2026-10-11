#include <types.h>

struct PeachFlagOwner {
    void* vtable;
    u8 flag;
};

extern "C" {
extern u8 lbl_103_data_235C[];

PeachFlagOwner* fn_103_71CC(PeachFlagOwner* owner, u8 flag) {
    owner->vtable = lbl_103_data_235C;
    owner->flag = flag;
    return owner;
}
}
