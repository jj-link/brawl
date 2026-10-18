#include <types.h>
#pragma force_active on

// Shared observer notification dispatcher, implemented in another module.
extern "C" void fn_27_1A8258(void* receiver, s16 id, void* owner, s8 argument);

// Observer callback forwarding trampoline: repack the incoming (id, argument)
// pair and hand it to the shared notification routine, with the receiving
// object registered as both sender and owner of the message.
extern "C" void fn_108_ADF4(void* receiver, s16 id, s32 argument) {
    fn_27_1A8258(receiver, id, receiver, static_cast<s8>(argument));
}
