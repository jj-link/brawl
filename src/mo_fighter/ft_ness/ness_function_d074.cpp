#pragma force_active on
extern "C" void fn_27_1A7B4C(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_101_D074(void* receiver, short id, int argument)
{
    fn_27_1A7B4C(receiver, id, receiver, static_cast<signed char>(argument));
}
