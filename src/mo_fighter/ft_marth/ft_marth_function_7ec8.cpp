#pragma force_active on
extern "C" void fn_27_1A8014(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_106_7EC8(void* receiver, short id, signed char argument) {
    fn_27_1A8014(receiver, id, receiver, argument);
}
