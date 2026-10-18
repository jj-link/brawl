#pragma force_active on
extern "C" void fn_27_D48FC(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_100_94DC(void* receiver, short id, int argument) {
    fn_27_D48FC(receiver, id, receiver, static_cast<signed char>(argument));
}
