#pragma force_active on
extern "C" void fn_27_D38D4(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_101_CF7C(void* receiver, short id, signed char argument) {
    fn_27_D38D4(receiver, id, receiver, argument);
}
