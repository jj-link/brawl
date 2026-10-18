#pragma force_active on
extern "C" {
void fn_27_D443C(void* receiver, short id, void* owner, signed char argument);

void fn_101_D048(void* receiver, short id, signed char argument)
{
    fn_27_D443C(receiver, id, receiver, argument);
}
}
