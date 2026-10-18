#pragma force_active on
extern "C" void fn_27_D512C(void* object, short manageId, void* observer, signed char unitId);

extern "C" void fn_101_D020(void* receiver, short id, signed char argument)
{
    fn_27_D512C(receiver, id, receiver, argument);
}
