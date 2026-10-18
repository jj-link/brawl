#pragma force_active on
extern "C" void fn_27_D4DF4(void* object, short manageId, void* observer, signed char unitId);

extern "C" void fn_118_A08C(void* receiver, short id, signed char argument) {
    fn_27_D4DF4(receiver, id, receiver, argument);
}
