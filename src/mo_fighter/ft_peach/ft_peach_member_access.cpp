#include <types.h>

// Only the pointer used by this accessor is known in the fighter layout.
struct PeachMemberOwner {
    u8 unknown[0x1870C];
    u8* member;
};

extern "C" void* fn_103_9120(PeachMemberOwner* fighter) {
    return fighter->member + 0x7C;
}
