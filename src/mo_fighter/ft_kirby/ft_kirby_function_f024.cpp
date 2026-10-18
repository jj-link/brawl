#pragma force_active on
typedef int __attribute__((eabi)) eabi_int;

extern "C" eabi_int fn_27_D3E88(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_96_F024(void* receiver, short id, int argument) {
    fn_27_D3E88(receiver, id, receiver, (signed char)argument);
}
