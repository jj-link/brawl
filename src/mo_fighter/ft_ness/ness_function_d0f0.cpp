#pragma force_active on
extern "C" void fn_27_1A7908(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_101_D0F0(void* receiver, short id, signed char argument)
{
    fn_27_1A7908(receiver, id, receiver, argument);
}
