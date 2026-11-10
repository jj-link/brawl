#pragma force_active on
extern "C" void fn_27_D46B8(void* receiver, short id, void* owner, signed char argument);
extern "C" void fn_106_7E20(void* receiver, short id, int argument) {
    fn_27_D46B8(receiver, id, receiver, static_cast<signed char>(argument));
}