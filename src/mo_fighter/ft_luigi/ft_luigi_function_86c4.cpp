#pragma force_active on
extern "C" void fn_27_D4B78(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_99_86C4(void* receiver, short id, int argument) {
    fn_27_D4B78(receiver, id, receiver, static_cast<signed char>(argument));
}
