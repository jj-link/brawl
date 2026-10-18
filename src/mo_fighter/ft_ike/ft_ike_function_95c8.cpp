#pragma force_active on
extern "C" void fn_27_1A8258(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_119_95C8(void* receiver, short id, int argument) {
    fn_27_1A8258(receiver, id, receiver, static_cast<signed char>(argument));
}
