#pragma force_active on
typedef signed char s8;
typedef short s16;

extern "C" void fn_27_1A8014(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_95_B4F0(void* receiver, s16 id, int argument) {
    fn_27_1A8014(receiver, id, receiver, static_cast<s8>(argument));
}
