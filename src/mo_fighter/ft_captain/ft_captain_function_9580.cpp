#pragma force_active on
typedef signed short s16;
typedef signed char s8;

extern "C" void fn_27_D3C0C(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_100_9580(void* receiver, s16 id, int argument) {
    fn_27_D3C0C(receiver, id, receiver, static_cast<s8>(argument));
}
