#pragma force_active on
extern "C" void fn_27_D512C(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_91_A41C(void* receiver, short id, signed char argument) {
    fn_27_D512C(receiver, id, receiver, argument);
}
