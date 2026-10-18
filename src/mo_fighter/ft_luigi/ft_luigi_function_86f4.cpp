#pragma force_active on
extern "C" void fn_27_1A8258(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_99_86F4(void* receiver, short id, int argument) {
    fn_27_1A8258(receiver, id, receiver, (signed char)argument);
}
