#pragma force_active on
extern "C" void fn_27_D3E88(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_41_2944(void* receiver, short id, int argument) {
    fn_27_D3E88(receiver, id, receiver, static_cast<signed char>(argument));
}
