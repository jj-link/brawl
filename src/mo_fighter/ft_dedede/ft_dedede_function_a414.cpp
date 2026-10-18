#pragma force_active on
typedef signed short s16;
typedef signed char s8;

extern "C" void fn_27_1A7908(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_117_A414(void* receiver, s16 id, s8 argument) {
    fn_27_1A7908(receiver, id, receiver, argument);
}
