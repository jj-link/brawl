#pragma force_active on
typedef signed short s16;
typedef signed char s8;
typedef signed int s32;

extern "C" void fn_27_D4B78(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_109_8E28(void* receiver, s16 id, s32 argument) {
    fn_27_D4B78(receiver, id, receiver, static_cast<s8>(argument));
}
