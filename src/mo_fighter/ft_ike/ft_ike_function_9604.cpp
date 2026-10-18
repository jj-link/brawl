#pragma force_active on
typedef signed char s8;
typedef signed short s16;

extern "C" void fn_27_D4DF4(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_119_9604(void* receiver, s16 id, int argument) {
    fn_27_D4DF4(receiver, static_cast<s16>(id), receiver, static_cast<s8>(argument));
}
