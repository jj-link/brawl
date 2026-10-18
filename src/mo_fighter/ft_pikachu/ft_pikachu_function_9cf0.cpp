#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A8014(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_98_9CF0(void* receiver, s16 manageId, s8 priority) {
    fn_27_1A8014(receiver, manageId, receiver, priority);
}
