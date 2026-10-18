#pragma force_active on
typedef signed short s16;
typedef signed char s8;

extern "C" void fn_27_D443C(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_117_A36C(void* receiver, s16 id, int argument) {
    s8 arg = static_cast<s8>(argument);
    fn_27_D443C(receiver, id, receiver, arg);
}
