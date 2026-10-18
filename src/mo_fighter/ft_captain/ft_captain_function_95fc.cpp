#pragma force_active on
extern "C" void fn_27_1A76C4(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_100_95FC(void* receiver, short id, signed char argument, void* unused) {
    fn_27_1A76C4(receiver, id, receiver, argument);
}
