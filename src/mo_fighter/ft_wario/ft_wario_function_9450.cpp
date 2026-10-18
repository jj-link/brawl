#pragma force_active on
typedef signed short s16;
typedef signed char s8;

extern "C" void fn_27_D38D4(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_110_9450(void* receiver, s16 id, int argument) {
    fn_27_D38D4(receiver, id, receiver, static_cast<s8>(argument));
}
