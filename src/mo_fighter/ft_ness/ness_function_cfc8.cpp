#pragma force_active on
extern "C" void fn_27_D4B78(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_101_CFC8(void* receiver, short id, signed char argument) {
    fn_27_D4B78(receiver, id, receiver, argument);
}
