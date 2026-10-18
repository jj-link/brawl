#pragma force_active on
typedef short s16;
typedef signed char s8;

extern "C" void fn_27_D46B8(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_102_8D98(void* receiver, s16 id, int argument) {
    fn_27_D46B8(receiver, static_cast<s16>(id), receiver, static_cast<s8>(argument));
}
