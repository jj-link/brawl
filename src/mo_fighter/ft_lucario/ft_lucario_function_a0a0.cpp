#pragma force_active on
extern "C" void fn_27_D443C(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_118_A0A0(void* receiver, short id, signed char argument) {
    fn_27_D443C(receiver, id, receiver, argument);
}
