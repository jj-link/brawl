#pragma force_active on
typedef signed short s16;
typedef signed char s8;

extern "C" void fn_27_1A8258(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_115_9F3C(void* receiver, s16 id, int argument) {
    fn_27_1A8258(receiver, static_cast<s16>(id), receiver, static_cast<s8>(argument));
}
