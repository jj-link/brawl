#pragma force_active on
extern "C" void fn_27_1A7B4C(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_106_7EE0(void* receiver, short id, signed char argument) {
    fn_27_1A7B4C(receiver, id, receiver, argument);
}
