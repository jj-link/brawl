#pragma force_active on
extern "C" void fn_27_1A7908(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_106_7F5C(void* receiver, short id, int argument) {
    fn_27_1A7908(receiver, id, receiver, static_cast<signed char>(argument));
}
