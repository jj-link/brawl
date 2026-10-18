#pragma force_active on
extern "C" void fn_27_D48FC(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_99_86E0(void* receiver, short id, unsigned char argument) {
    fn_27_D48FC(receiver, id, receiver, static_cast<signed char>(argument));
}
