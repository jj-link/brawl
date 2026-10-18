#include <types.h>
#pragma force_active on

extern "C" void fn_27_D4B78(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_103_9D84(void* receiver, s16 id, s8 argument)
{
    fn_27_D4B78(receiver, id, receiver, argument);
}
